project(texture)

add_executable(${PROJECT_NAME} "${PROJECT_NAME}.cpp")
target_link_libraries(${PROJECT_NAME} PUBLIC ${UNIFIED_PROJECT})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/image.png
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
