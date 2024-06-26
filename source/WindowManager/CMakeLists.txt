# Set the name and the supported language of the project
PROJECT(template C)
# Set the minimum version of cmake required to build this project
CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

# Add an executable compiled from template.c
ADD_EXECUTABLE(template src/main.c)

# Link the target to the GTK+ libraries
TARGET_LINK_LIBRARIES(template ${GTK3_LIBRARIES})

# copy glade data to build
#add_custom_target(glade ALL
#	COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/glade ${CMAKE_BINARY_DIR}/glade
#	DEPENDS ${MY_TARGET}
#)
