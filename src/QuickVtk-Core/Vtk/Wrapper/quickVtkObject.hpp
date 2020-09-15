#pragma once

#include "quickQmlRegister.hpp"

#include <QObject>

namespace quick {
    namespace Vtk {

        class Object : public QObject {
            Q_OBJECT
        public:
            enum class Type {
                Prop,
                Algorithm,
                Widget,
                Other
            };
        private:
            static Qml::Register::AbstractClass<Object> Register;
            Type m_type;
        public:
            Object(Type);
            auto getType() -> Type;
            //fork dev.
            virtual auto init() -> void {}
        };
    }
}
