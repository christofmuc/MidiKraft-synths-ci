#
#  Copyright (c) 2019 Christof Ruch. All rights reserved.
#
#  Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
#

cmake_minimum_required(VERSION 3.14)

project(MidiKraft-synths-ci)

# Include useful scripts for CMake    
include(FetchContent REQUIRED)

# On Windows, we need to download external dependencies
IF (WIN32)
    FetchContent_Declare(
	  boost
	  URL "https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.zip"
	)
	FetchContent_MakeAvailable(boost)
ENDIF()

# This definitely is required when building the PyTschirp python shared lib on Linux, but I guess it doesn't hurt
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# We need a little bit support for the JUCE library, and also want to put our own CMake helpers on the module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/third_party/juce-cmake/cmake" "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_subdirectory(juce-utils)
add_subdirectory(MidiKraft-base)
add_subdirectory(MidiKraft-behringer-rd8)
add_subdirectory(MidiKraft-sequential-rev2)

# Setup pybind11
IF(WIN32)
	IF(DEFINED ENV{APPVEYOR})
		# Fixed path in Appveyor Windows build machine
		set(PYTHON_EXECUTABLE "C:/Python36-x64/python.exe")
	ELSE()
		set(PYTHON_EXECUTABLE "c:/python/python36/python.exe")
	ENDIF()
ENDIF()
set(PYBIND11_PYTHON_VERSION 3.6)
add_subdirectory(third_party/pybind11)

add_subdirectory(pytschirp)

