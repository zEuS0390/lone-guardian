cmake_minimum_required(VERSION 3.21)
project(SFML_2D_TOP_DOWN_SHOOTER)

set(CMAKE_CXX_STANDARD 17)
# Download SFML and store it in the libs directory (choosing 32 or 64-bit libraries
# should be based on which platform you want to compile for, not which OS you have)
set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML") 
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML COMPONENTS graphics window system REQUIRED)
add_executable(SFML_2D_TOP_DOWN_SHOOTER src/main.cpp src/bullet.cpp src/player.cpp src/sprite.cpp)
target_include_directories(SFML_2D_TOP_DOWN_SHOOTER PUBLIC include)
target_link_libraries(SFML_2D_TOP_DOWN_SHOOTER sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET SFML_2D_TOP_DOWN_SHOOTER POST_BUILD 
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/img $<TARGET_FILE_DIR:SFML_2D_TOP_DOWN_SHOOTER>/img)
