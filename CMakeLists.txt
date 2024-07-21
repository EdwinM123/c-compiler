cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME C_Compiler)
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES C)

set(SOURCES main.c chunk.c chunk.h common.h debug.c debug.h memory.c memory.h value.c value.h)
  
add_executable(${PROJECT_NAME} ${SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
if (UNIX)
   target_link_libraries(${PROJECT_NAME} pthread)
endif (UNIX)