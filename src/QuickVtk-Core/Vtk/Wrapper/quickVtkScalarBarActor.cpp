#include "quickVtkScalarBarActor.hpp"

namespace quick {
    namespace Vtk {
        Qml::Register::Class<ScalarBarActor> ScalarBarActor::Register(true);

        ScalarBarActor::ScalarBarActor() : Actor2D(vtkSmartPointer<vtkScalarBarActor>::New()) {
            this->m_vtkObject = vtkScalarBarActor::SafeDownCast(Actor2D::getVtkObject());
        }

        ScalarBarActor::ScalarBarActor(vtkSmartPointer<vtkScalarBarActor> vtkObject) : Actor2D(vtkObject) {
            this->m_vtkObject = vtkScalarBarActor::SafeDownCast(vtkObject);
        }

        auto ScalarBarActor::getVtkObject() -> vtkSmartPointer<vtkScalarBarActor> {
            return vtkScalarBarActor::SafeDownCast(ScalarBarActor::getVtkObject());
        }

        ScalarBarActor::~ScalarBarActor() {

        }

        auto ScalarBarActor::getNumberOfLabels() -> int {
            return this->m_vtkObject->GetNumberOfLabels();
        }

        auto ScalarBarActor::setNumberOfLabels(int num) -> void {
            this->m_vtkObject->SetNumberOfLabels(num);
            this->update();
        }

        auto ScalarBarActor::getLookupTable()->LookupTable* {
            return this->m_loopTable;
        }

        auto ScalarBarActor::setLookupTable(LookupTable* table) -> void {
            if (table) {
                this->m_loopTable = table;
                this->m_vtkObject->SetLookupTable(table->getVtkObject());
                emit lookupTableChanged();
                this->update();
            }
        }

        auto ScalarBarActor::getTitle()->QString {
            return this->m_vtkObject->GetTitle();
        }

        auto ScalarBarActor::setTitle(QString str)->void {
            this->m_vtkObject->SetTitle(str.toStdString().c_str());
            this->update();
        }

        auto getMaximumWidthInPixels() ->int;
        auto setMaximumWidthInPixels(int) -> void;
        auto getMaximumHeightInPixels() ->int;
        auto setMaximumHeightInPixels(int) -> void;
        auto ScalarBarActor::getMaximumWidthInPixels()->int {
            return this->m_vtkObject->GetMaximumWidthInPixels();
        }

        auto ScalarBarActor::setMaximumWidthInPixels(int w)->void {
            this->m_vtkObject->SetMaximumWidthInPixels(w);
            this->update();
        }

        auto ScalarBarActor::getMaximumHeightInPixels()->int {
            return this->m_vtkObject->GetMaximumHeightInPixels();
        }

        auto ScalarBarActor::setMaximumHeightInPixels(int h)->void {
            this->m_vtkObject->SetMaximumHeightInPixels(h);
            this->update();
        }
    }
}