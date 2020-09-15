#include "quickVtkLookupTable.hpp"

namespace quick {
	namespace Vtk {
        Qml::Register::Class<LookupTable> LookupTable::Register(true);

        LookupTable::LookupTable() : Object(Object::Type::Prop) {
            this->m_vtkObject = vtkSmartPointer<vtkLookupTable>::New();
            this->m_vtkObject->SetTableRange(0, 1);
            this->m_vtkObject->SetHueRange(0, 1);
            this->m_vtkObject->SetSaturationRange(1, 1);
            this->m_vtkObject->SetValueRange(1, 1);
            this->m_vtkObject->Build();
        }

        LookupTable::LookupTable(vtkSmartPointer<vtkLookupTable> vtkObject) : Object(Object::Type::Prop) {
            this->m_vtkObject = vtkObject;
        }

        auto LookupTable::getVtkObject() -> vtkSmartPointer<vtkLookupTable> {
            return this->m_vtkObject;
        }

        LookupTable::~LookupTable() {

        }
	}
}