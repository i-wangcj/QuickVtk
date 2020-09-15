#pragma once

#include "quickVtkActor2D.hpp"
#include "quickVtkLookupTable.hpp"
#include <vtkScalarBarActor.h>

namespace quick {
    namespace Vtk {

        class ScalarBarActor : public Actor2D
        {
            Q_OBJECT
            Q_PROPERTY(QString title READ getTitle WRITE setTitle);
            Q_PROPERTY(quick::Vtk::LookupTable* lookupTable READ getLookupTable WRITE setLookupTable NOTIFY lookupTableChanged);
            Q_PROPERTY(int  numberOfLabels READ getNumberOfLabels WRITE setNumberOfLabels);
        private:
            static Qml::Register::Class<ScalarBarActor> Register;
            vtkSmartPointer<vtkScalarBarActor> m_vtkObject = nullptr;
            LookupTable* m_loopTable = nullptr;
        public:
            ScalarBarActor();
            ScalarBarActor(vtkSmartPointer<vtkScalarBarActor>);
            auto getVtkObject()->vtkSmartPointer<vtkScalarBarActor>;
            virtual ~ScalarBarActor();
            auto getNumberOfLabels() -> int;
            auto setNumberOfLabels(int) -> void;
            auto getLookupTable()->LookupTable*;
            auto setLookupTable(LookupTable*)->void;
            auto getTitle()->QString;
            auto setTitle(QString)->void;
        signals:
            void lookupTableChanged();
        };
    }
}