#include "quickVtkDataSetMapper.hpp"
#include "quickVtkPolyDataAlgorithm.hpp"
#include "vtkDataSetMapper.h"

#include <vtkAlgorithm.h>
#include <vtkPointData.h>
#include <vtkDataArray.h>

namespace quick {
    namespace Vtk {

        Qml::Register::Class<DataSetMapper> DataSetMapper::Register(true);

        DataSetMapper::DataSetMapper() : Mapper(vtkSmartPointer<vtkDataSetMapper>::New()) {
            m_loopTable = new LookupTable();
        }

        DataSetMapper::~DataSetMapper() {
            delete m_loopTable;
            m_loopTable = nullptr;
        }

        auto DataSetMapper::getLookupTable()->LookupTable* {
            this->m_loopTable->setVtkObject(dynamic_cast<vtkLookupTable*>(this->getVtkObject()->GetLookupTable()));
            return this->m_loopTable;
        }

        auto DataSetMapper::setLookupTable(LookupTable* table) -> void {
            if (table) {
                this->m_loopTable = table;
                this->getVtkObject()->SetLookupTable(table->getVtkObject());
                emit lookupTableChanged();
                this->update();
            }
        }

        auto DataSetMapper::getNumberOfPoints()->qlonglong {
            return this->getVtkObject()->GetInput()->GetNumberOfPoints();
        }

        auto DataSetMapper::setScalars(quick::List::FloatArray* scalars) ->void {
            this->getVtkObject()->GetInput()->GetPointData()->SetScalars(scalars->getVtkFloatArray());
        }
    }
}
