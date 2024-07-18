# Set minimum required CMake version
cmake_minimum_required(VERSION 3.21)

# Project name
project(SFML_2D_TOP_DOWN_SHOOTER)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build Shared Libs" OFF)

set(APP_SRC_FILES
	src/main.cpp
	src/bullet.cpp
	src/player.cpp
	src/sprite.cpp)

# Set output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(FETCHCONTENT_QUIET FALSE)

# Include SFML using FetchContent
include(FetchContent)
FetchContent_Declare(SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.6.x
	GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(SFML)

# Configure build
add_executable(${PROJECT_NAME} ${APP_SRC_FILES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Copy the 'img' directory and its files before building
add_custom_command(
	TARGET ${PROJECT_NAME} 
	PRE_BUILD 
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/img $<TARGET_FILE_DIR:SFML_2D_TOP_DOWN_SHOOTER>/img)

# Additional copy for Windows (specifically openal32.dll)
if (CMAKE_SYSTEM_NAME MATCHES "Windows")
	add_custom_command(
		TARGET ${PROJECT_NAME}
		PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
		VERBATIM)
endif()

