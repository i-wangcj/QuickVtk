import QtQuick 2.12

import Vtk 1.0 as Vtk
import Math 1.0 as Math

Item {
    id: root;
    
    anchors.fill: parent;
    
    Vtk.Viewer {
        anchors.fill: parent;
        
        mouseEnabled: true;
        Vtk.Actor {
            Vtk.DataSetMapper {
                Vtk.UnstructuredGridReader {
                    fileName: SampleData.meshes.unstructuredGrid;
                }
            }
        }
    }
}
