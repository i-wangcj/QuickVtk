#pragma once

#include "quickVtkDataReader.hpp"
#include <vtkUnstructuredGridReader.h>

namespace quick {
    namespace Vtk {

        class UnstructuredGridReader : public DataReader {
            Q_OBJECT
        private:
            static Qml::Register::Class<UnstructuredGridReader> Register;
        public:
            UnstructuredGridReader();
        };
    }
}