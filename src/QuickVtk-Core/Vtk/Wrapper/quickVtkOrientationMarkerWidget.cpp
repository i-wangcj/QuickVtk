#include "quickVtkOrientationMarkerWidget.h"

#include <vtkNamedColors.h>
#include <vtkAxesActor.h>

namespace quick {
    namespace Vtk {

        Qml::Register::Class<OrientationMarkerWidget> OrientationMarkerWidget::Register(true);

        OrientationMarkerWidget::OrientationMarkerWidget() : Object(Object::Type::Widget), m_vtkObject(vtkSmartPointer<vtkOrientationMarkerWidget>::New()) {
        }

        auto OrientationMarkerWidget::getVtkObject() -> vtkSmartPointer<vtkOrientationMarkerWidget> {
            return this->m_vtkObject;
        }

        auto OrientationMarkerWidget::setEnabled(bool enabled) -> void {
            this->m_vtkObject->SetEnabled(enabled);
            emit this->enabledChanged();
        }

        auto OrientationMarkerWidget::getEnabled() -> bool {
            return this->m_vtkObject->GetEnabled();
        }

        auto OrientationMarkerWidget::init() -> void {
            vtkSmartPointer<vtkNamedColors> colors =
                vtkSmartPointer<vtkNamedColors>::New();
            vtkSmartPointer<vtkAxesActor> axes =
                vtkSmartPointer<vtkAxesActor>::New();

            double rgba[4]{ 0.0, 0.0, 0.0, 0.0 };
            colors->GetColor("Carrot", rgba);
            m_vtkObject->SetOutlineColor(rgba[0], rgba[1], rgba[2]);
            m_vtkObject->SetOrientationMarker(axes);
            //m_vtkObject->SetViewport(0.0, 0.0, 0.4, 0.4);
            //m_vtkObject->InteractiveOff();
        }
    }
}