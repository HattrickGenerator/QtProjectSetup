
qt5_add_resources(QT_RESOURCES qml.qrc)

set(hdrFiles
TestLibraryFunctionality.h
CustomMainWindow.h
Widget3DContainer.h
OrbitTransformController.h
TimedOrbitTransformController.h
Widget3DControlCenter.h
Central3DWidget.h
Window3DSubclass.h
util/LabelSlider.h
)

set(srcFiles
  OrbitTransformController.cpp
  TimedOrbitTransformController.cpp
    Widget3DContainer.cpp
    Widget3DControlCenter.cpp
    Central3DWidget.cpp
Window3DSubclass.cpp

    util/LabelSlider.cpp
)

INCLUDE_DIRECTORIES(util)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(${libProject} STATIC ${hdrFiles} ${srcFiles})

set_property(TARGET ${libProject} PROPERTY CXX_STANDARD 14)

set_target_properties(${libProject} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${libProject}  PUBLIC ${CMAKE_SOURCE_DIR}/${libProject})

target_link_libraries(${libProject} 
${QT_LIBRARIES}
)
