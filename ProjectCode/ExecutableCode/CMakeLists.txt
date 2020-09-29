add_executable(${PROJECT_NAME} QtProject.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)



target_link_libraries(${PROJECT_NAME} 
${libProject}
)


if(WIN32)

#A bit hacky solution: As visual studio has its generator based approach, it is very difficult to find out if we are in debug or release mode.
#We will try to run the script for all kinds of configurations. This is ok as Windows is not the main development platform

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND  cmd /c ${CMAKE_BINARY_DIR}/DeploymentScriptWindows.bat ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} ${PROJECT_NAME} 
    )

endif()