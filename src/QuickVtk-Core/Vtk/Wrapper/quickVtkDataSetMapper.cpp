#include "quickVtkDateSetMapper.h"
//#include "quickVtkPolyDataAlgorithm.hpp"
#include "quickVtkPolyDataAlgorithm.hpp"
#include "vtkDataSetMapper.h"

#include <vtkAlgorithm.h>

namespace quick {
    namespace Vtk {

        Qml::Register::Class<DataSetMapper> DataSetMapper::Register(true);

        DataSetMapper::DataSetMapper() : Mapper(vtkSmartPointer<vtkDataSetMapper>::New()) {
        }
    }
}
