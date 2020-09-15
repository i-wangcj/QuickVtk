#include "quickVtkFloatArray.hpp"

namespace quick {
    namespace List {
        Qml::Register::Class<FloatArray> FloatArray::Register(true);

        FloatArray::FloatArray() : QObject() {
            this->m_floatArray = vtkSmartPointer<vtkFloatArray>::New();
        }

        auto FloatArray::getNumberOfValues() -> int {
            return  this->m_floatArray->GetNumberOfValues();
        }

        auto FloatArray::setNumberOfValues(int numPts) -> void {
            this->m_floatArray->SetNumberOfValues(numPts);
            for (int i = 0; i < numPts; ++i)
            {
                this->m_floatArray->SetValue(i, static_cast<float>(i) / numPts);
            }
        }

        auto FloatArray::getVtkFloatArray()->vtkSmartPointer<vtkFloatArray> {
            return this->m_floatArray;
        }
    }
}
