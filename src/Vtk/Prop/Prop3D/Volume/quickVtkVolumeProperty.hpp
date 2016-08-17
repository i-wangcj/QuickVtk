#pragma once

#include "quickQmlRegister.hpp"

#include <QColor>
#include <QObject>

#include <vtkSmartPointer.h>
#include <vtkVolumeProperty.h>
#include <vtkVolume.h>

namespace quick {

    namespace Vtk {

        class Volume;
        class PiecewiseFunction;
        class ColorTransferFunction;

        class VolumeProperty : public QObject {
            Q_OBJECT
            Q_PROPERTY(bool shade READ getShade WRITE setShade NOTIFY shadeChanged);
            Q_PROPERTY(quick::Vtk::PiecewiseFunction* scalarOpacity READ getScalarOpacity CONSTANT);
            Q_PROPERTY(quick::Vtk::ColorTransferFunction* transferFunction READ getTransferFunction CONSTANT);
        private:
            static Qml::Register::UncreatableClass<VolumeProperty> Register;
            Volume* m_volume = nullptr;
            PiecewiseFunction* m_scalarOpacity = nullptr;
            ColorTransferFunction* m_transferFunction = nullptr;
            vtkSmartPointer<vtkVolume> m_vtkVolume = nullptr;
        private:
            void update();
        public:
            VolumeProperty() = delete;
            VolumeProperty(Volume*);
            auto setShade(bool) -> void;
            auto getShade() -> bool;
            auto getScalarOpacity() -> PiecewiseFunction*;
            auto getTransferFunction() -> ColorTransferFunction*;
        signals:
            void shadeChanged();
        };
    }
}