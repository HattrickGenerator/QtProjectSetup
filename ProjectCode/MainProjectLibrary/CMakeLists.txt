
qt5_add_resources(QT_RESOURCES qml.qrc)

set(hdrFiles
TestLibraryFunctionality.h
CustomMainWindow.h
Widget3DContainer.h
OrbitTransformController.h
Widget3DControlCenter.h
Central3DWidget.h

util/LabelSlider.h
)

set(srcFiles
  OrbitTransformController.cpp
    Widget3DContainer.cpp
    Widget3DControlCenter.cpp
    Central3DWidget.cpp


    util/LabelSlider.cpp
)

INCLUDE_DIRECTORIES(util)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(${libProject} SHARED ${hdrFiles} ${srcFiles})

set_target_properties(${libProject} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${libProject}  PUBLIC ${CMAKE_SOURCE_DIR}/${libProject})

target_link_libraries(${libProject} 
${QT_LIBRARIES}
)
