cmake_minimum_required(VERSION 3.12)

project(UnifiedEngine VERSION 0.0.3)

set(CMAKE_CXX_STANDARD 17)

set(UNIFIED_PROJECT ${PROJECT_NAME})
set(UNIFIED_VERSION ${PROJECT_VERSION})

set(UNIFIED_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(UNIFIED_CMAKE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(UNIFIED_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(UNIFIED_MODULES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules")

file(GLOB_RECURSE UNIFIED_SRC_FILES "${UNIFIED_SRC_DIR}/*.cpp")

include("${UNIFIED_CMAKE_DIR}/directories.cmake")

message("-- Building the ${UNIFIED_PROJECT} version ${UNIFIED_VERSION}")

add_library(${UNIFIED_PROJECT} STATIC ${UNIFIED_SRC_FILES})
set_property(TARGET ${UNIFIED_PROJECT} PROPERTY CXX_STANDARD 17)
target_include_directories(${UNIFIED_PROJECT} PUBLIC ${UNIFIED_INCLUDE_DIR} ${UNIFIED_MODULES_DIR})

target_compile_definitions(${UNIFIED_PROJECT} PUBLIC "UNIFIED_GDK")
target_compile_definitions(${UNIFIED_PROJECT} PRIVATE "$<$<CONFIG:DEBUG>:_DEBUG_>")
target_compile_definitions(${UNIFIED_PROJECT} PRIVATE "$<$<CONFIG:RELEASE>:_RELEASE_>")

set(UNIFIED_VENDOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor")

# including the 'fmt' library
set(UNIFIED_FMT_DIR "${UNIFIED_VENDOR_DIR}/fmt")
add_subdirectory(${UNIFIED_FMT_DIR})
target_link_libraries(${UNIFIED_PROJECT} PUBLIC fmt)

# including the 'glfw' library
set(UNIFIED_GLFW_DIR "${UNIFIED_VENDOR_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_INSTALL OFF CACHE INTERNAL "")
add_subdirectory(${UNIFIED_GLFW_DIR})
target_link_libraries(${UNIFIED_PROJECT} PRIVATE glfw ${GLFW_LIBRARIES})

# including the 'glad' library
set(UNIFIED_GLAD_DIR "${UNIFIED_VENDOR_DIR}/glad")
add_library(glad STATIC
    "${UNIFIED_GLAD_DIR}/src/glad.c"
    "${UNIFIED_GLAD_DIR}/include/glad/glad.h"
)
target_include_directories(glad PUBLIC "${UNIFIED_GLAD_DIR}/include/")
target_link_libraries(${UNIFIED_PROJECT} PRIVATE glad ${CMAKE_DL_LIBS})

# including the 'stb' library
set(UNIFIED_STB_DIR "${UNIFIED_VENDOR_DIR}/stb")
target_include_directories(${UNIFIED_PROJECT} PRIVATE ${UNIFIED_STB_DIR})

# include current existing modules
directories_list(MODULE_DIRECTORIES ${UNIFIED_MODULES_DIR})
foreach(MODULE_NAME ${MODULE_DIRECTORIES})
    add_subdirectory("${UNIFIED_MODULES_DIR}/${MODULE_NAME}")
    target_link_libraries(${UNIFIED_PROJECT} PUBLIC ${MODULE_NAME})
endforeach()

option(UNIFORM_BUILD_EXAMPLES "Build the ${UNIFIED_PROJECT} test programs" TRUE)

if (UNIFORM_BUILD_EXAMPLES)
 message("-- Build the ${UNIFIED_PROJECT} test programs")
 set(UNIFIED_EXAMPLES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/examples")
 add_subdirectory("${UNIFIED_EXAMPLES_DIR}/interfaces")
 add_subdirectory("${UNIFIED_EXAMPLES_DIR}/layers")
 add_subdirectory("${UNIFIED_EXAMPLES_DIR}/texture")
endif ()
