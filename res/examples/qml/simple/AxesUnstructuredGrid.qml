import QtQuick 2.12

import Vtk 1.0 as Vtk
import Math 1.0 as Math
import List 1.0 as List

Item {
    id: root;
    
    anchors.fill: parent;
    
    Vtk.Viewer {
        anchors.fill: parent;
        
        mouseEnabled: true;
		Vtk.OrientationMarkerWidget {
		}
        Vtk.Actor {
            Vtk.DataSetMapper {
				id: dataSetMapper
                Vtk.UnstructuredGridReader {
                    fileName: SampleData.meshes.unstructuredGrid;
                }
            }
        }
		Vtk.ScalarBarActor {
			id:barActor
			numberOfLabels: 4
			title: "title"
		}
    }
	
	List.FloatArray {
		id: scalars
		numberOfValues:100
	}	
	Vtk.LookupTable {
		id:lookupid
	}
	Component.onCompleted : {
		scalars.numberOfValues = dataSetMapper.numberOfPoints
		barActor.lookupTable = lookupid
		barActor.lookupTable = lookupid
		dataSetMapper.scalars = scalars
	}
}
