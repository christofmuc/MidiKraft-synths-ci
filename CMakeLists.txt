#
#  Copyright (c) 2019 Christof Ruch. All rights reserved.
#
#  Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
#

cmake_minimum_required(VERSION 3.14)

project(MidiKraft-synths-ci)

# We need a little bit support for the JUCE library, and also want to put our own CMake helpers on the module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/third_party/juce-cmake/cmake" "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_subdirectory(juce-utils)
add_subdirectory(MidiKraft-base)
add_subdirectory(MidiKraft-behringer-rd8)

SET(JUCE_DIR_HINT "${CMAKE_CURRENT_LIST_DIR}/third_party")
find_package(JUCE REQUIRED 
	COMPONENTS 
		juce_core		
		juce_events
		juce_audio_basics
		juce_audio_devices
		juce_data_structures
)

set(SOURCES
	PluginTest.cpp
)

add_executable(PluginTest PluginTest.cpp)
target_include_directories(PluginTest PUBLIC midikraft-behringer-rd8)
target_link_libraries(PluginTest midikraft-base juce-utils ${JUCE_LIBRARIES})

