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

# We need a little bit support for the JUCE library, and also want to put our own CMake helpers on the module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/third_party/juce-cmake/cmake" "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_subdirectory(juce-utils)
add_subdirectory(MidiKraft-base)
add_subdirectory(MidiKraft-behringer-rd8)
add_subdirectory(MidiKraft-sequential-rev2)


