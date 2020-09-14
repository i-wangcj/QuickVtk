#include "quickVtkUnstructuredGridReader.h"


namespace quick {
    namespace Vtk {

        Qml::Register::Class<UnstructuredGridReader> UnstructuredGridReader::Register(true);

        UnstructuredGridReader::UnstructuredGridReader() : DataReader(vtkSmartPointer<vtkUnstructuredGridReader>::New()) {
        }
    }
}