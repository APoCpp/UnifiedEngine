project(fluid)

add_executable(${PROJECT_NAME} "${PROJECT_NAME}.cpp")
target_link_libraries(${PROJECT_NAME} PUBLIC ${UNIFIED_PROJECT})
