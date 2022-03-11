cmake_minimum_required(VERSION 3.9)

# set the project name
project(Tutorial)
set(Python_ADDITIONAL_VERSIONS 3.7)
find_package(Python COMPONENTS Interpreter Development)
find_package(PythonLibs REQUIRED)
# add the executable
include_directories(${PYTHON_INCLUDE_DIRS})
add_executable(Tutorial readfile.cpp)
target_link_libraries(Tutorial ${PYTHON_LIBRARIES})
message("Python_FOUND:${Python_FOUND}")
message("Python_VERSION:${Python_VERSION}")
message("Python_Development_FOUND:${Python_Development_FOUND}")
message("Python_LIBRARIES:${Python_LIBRARIES}")
message("Python_INCLUDE_DIR:${PYTHON_INCLUDE_DIRS}")