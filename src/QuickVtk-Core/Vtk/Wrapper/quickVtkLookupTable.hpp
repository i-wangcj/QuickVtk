#pragma once
#include "quickVtkObject.hpp"

#include <vtkLookupTable.h>

namespace quick {
	namespace Vtk {
		class LookupTable : public Object
		{
			Q_OBJECT
		private:
			static Qml::Register::Class<LookupTable> Register;
			vtkSmartPointer<vtkLookupTable> m_vtkObject = nullptr;
		public:
			LookupTable();
			LookupTable(vtkSmartPointer<vtkLookupTable>);
			~LookupTable();
			auto getVtkObject()->vtkSmartPointer<vtkLookupTable>;
			Q_INVOKABLE void setVtkObject(vtkSmartPointer<vtkLookupTable>);
		};
	}
}