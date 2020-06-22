cmake_minimum_required(VERSION 3.10)

# Set the project name
project(KIEX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
cmake_policy(SET CMP0074 OLD)

# Add our cmake functions
list(APPEND CMAKE_MODULE_PATH
  "${CMAKE_SOURCE_DIR}/cmake/macros")

include(AutoCollect)
include(BuildInfoAutomation)

# Specify include directories
set(PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/src")

# Specify output directories
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

# Collect all our source files
CollectSourceFiles( "${CMAKE_SOURCE_DIR}/src" SOURCE )
GroupSources(src)

# Add an executable for the project
add_executable(KIEX ${SOURCE})

# Add our build info script
add_custom_command(
	TARGET KIEX
	PRE_LINK
	COMMAND ${CMAKE_COMMAND}
	-P "${CMAKE_SOURCE_DIR}/cmake/macros/BuildInfoAutomation.cmake"
)

# Config Header
configure_file(KIEXConfig.h.in KIEXConfig.h)

# Add our includes and library links
CollectIncludeDirectories( "${CMAKE_SOURCE_DIR}/src" PUBLIC_INCLUDES )
target_include_directories(
	KIEX PUBLIC
	${PROJECT_BINARY_DIR}
	${PUBLIC_INCLUDES}
)
