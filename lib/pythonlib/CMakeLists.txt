cmake_minimum_required(VERSION 3.9)

# set the project name
project(pythonLib)
set(Python_ADDITIONAL_VERSIONS 3.7)
find_package(Python COMPONENTS Interpreter Development)
find_package(PythonLibs REQUIRED)
# add the executable
include_directories(${PYTHON_INCLUDE_DIRS} include)
#add_executable(Tutorial py_test.cpp)
add_library(pythonLib OBJECT py_test.cpp)
target_link_libraries(pythonLib ${PYTHON_LIBRARIES})
