#pragma once

#include "quickVtkMapper.hpp"
#include "quickVtkAlgorithm.hpp"
#include <vtkPolyDataMapper.h>

namespace quick {
    namespace Vtk {

        class DataSetAlgorithm;

        class DataSetMapper : public Mapper {
            Q_OBJECT
        private:
            static Qml::Register::Class<DataSetMapper> Register;
        public:
            DataSetMapper();
        };
    }
}