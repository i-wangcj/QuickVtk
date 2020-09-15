#pragma once

#include "quickQmlRegister.hpp"
#include "quickVtkObject.hpp"

#include <vtkSmartPointer.h>
#include <vtkOrientationMarkerWidget.h>

namespace quick {
	namespace Vtk{

		class OrientationMarkerWidget : public Object {
			Q_OBJECT
			Q_PROPERTY(bool enabled READ getEnabled WRITE setEnabled NOTIFY enabledChanged);
		private:
			static Qml::Register::Class<OrientationMarkerWidget> Register;
			bool m_enabled = true;
			vtkSmartPointer<vtkOrientationMarkerWidget> m_vtkObject = nullptr;
		public:
			//OrientationMarkerWidget() = delete;
			OrientationMarkerWidget();
			auto setEnabled(bool) -> void;
			auto getEnabled() -> bool;
			auto getVtkObject()->vtkSmartPointer<vtkOrientationMarkerWidget>;
			auto init() -> void;
		signals:
			void enabledChanged();
		};
	}
}