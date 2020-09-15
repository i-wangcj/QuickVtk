#pragma once
#include "quickQmlRegister.hpp"
#include <vtkFloatArray.h>
#include <qobject.h>
namespace quick {
    namespace List {
        class FloatArray :public QObject
        {
            Q_OBJECT
            Q_PROPERTY(qreal numberOfValues READ getNumberOfValues WRITE setNumberOfValues);
        private:
            vtkSmartPointer<vtkFloatArray> m_floatArray = nullptr;
        public:
            static Qml::Register::Class<FloatArray> Register;
            FloatArray();
            auto getNumberOfValues() -> int;
            auto setNumberOfValues(int) -> void;
            auto getVtkFloatArray()->vtkSmartPointer<vtkFloatArray>;
        };
    }
}
