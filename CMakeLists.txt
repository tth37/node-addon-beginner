project(addon)
cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_JS_INC})

file(GLOB SOURCE_FILES "./native/*.cpp" "./native/*.hpp")

add_library(addon SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})

add_executable(addon_debug "./native/main.cpp" "./native/hello.cpp" "./native/hello.hpp")

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})

# Include node-addon-api wrappers
execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${NODE_ADDON_API_DIR})