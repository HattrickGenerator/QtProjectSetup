

set(hdrFiles
TestLibraryFunctionality.h
MainLib.h
)


add_library(${libProject} SHARED ${hdrFiles})

set_target_properties(${libProject} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${libProject}  PUBLIC ${CMAKE_SOURCE_DIR}/${libProject})

target_link_libraries(${libProject} 
${QT_LIBRARIES}
)
