#pragma once
#include <vtkPolyDataMapper.h>
#include "quickVtkMapper.hpp"
#include "quickVtkAlgorithm.hpp"
#include "quickVtkLookupTable.hpp"
#include "quickVtkFloatArray.hpp"
namespace quick {
    namespace Vtk {

        class DataSetAlgorithm;

        class DataSetMapper : public Mapper {
            Q_OBJECT
            Q_PROPERTY(qlonglong numberOfPoints READ getNumberOfPoints)
            Q_PROPERTY(quick::List::FloatArray* scalars WRITE setScalars)
            Q_PROPERTY(quick::Vtk::LookupTable* lookupTable READ getLookupTable WRITE setLookupTable NOTIFY lookupTableChanged);
        private:
            static Qml::Register::Class<DataSetMapper> Register;
            LookupTable* m_loopTable = nullptr;
        public:
            DataSetMapper();
            auto getLookupTable()->LookupTable*;
            auto setLookupTable(LookupTable*)->void;
            auto getNumberOfPoints()->qlonglong;
            auto setScalars(quick::List::FloatArray*)->void;
        signals:
            void lookupTableChanged();
        };
    }
}