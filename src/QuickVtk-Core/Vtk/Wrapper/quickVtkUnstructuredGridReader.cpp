#include "quickVtkUnstructuredGridReader.hpp"


namespace quick {
    namespace Vtk {

        Qml::Register::Class<UnstructuredGridReader> UnstructuredGridReader::Register(true);

        UnstructuredGridReader::UnstructuredGridReader() : DataReader(vtkSmartPointer<vtkUnstructuredGridReader>::New()) {
        }
    }
}