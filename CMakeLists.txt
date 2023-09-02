cmake_minimum_required(VERSION 3.26.3)

project(square_jump)

# Find SDL2 package
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Include SDL2 directories
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# Add your source file(s)
add_executable(${PROJECT_NAME} sjump.c)

# Link SDL2 libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SDL2_image)