---  

### 3️⃣ `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.20)
project(RC7_Remake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
endif()

file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME}
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Link common Windows libraries – add more later (e.g., DirectX)
target_link_libraries(${PROJECT_NAME} PRIVATE winmm)

# Copy the whole resources folder next to the executable after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/resources"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)
