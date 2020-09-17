
qt5_add_resources(QT_RESOURCES qml.qrc)

set(hdrFiles
TestLibraryFunctionality.h
MainLib.h
Widget3DContainer.h
OrbitTransformController.h
)

set(srcFiles
  OrbitTransformController.cpp
    Widget3DContainer.cpp
)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(${libProject} SHARED ${hdrFiles} ${srcFiles})

set_target_properties(${libProject} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${libProject}  PUBLIC ${CMAKE_SOURCE_DIR}/${libProject})

target_link_libraries(${libProject} 
${QT_LIBRARIES}
)
