# Find or Fetch Catch2
find_package(Catch2 3 QUIET)
if (NOT Catch2_FOUND)
    message(STATUS "Using FetchContent to load Catch2")
    include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
        GIT_TAG         v3.4.0
    )
    FetchContent_MakeAvailable(Catch2)
endif()

# Discover and Add All Test Executables
file(GLOB_RECURSE TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.test.cpp"
)

foreach(test_src ${TEST_SOURCES})
    message(STATUS "Discovered test file: ${test_src}")

    get_filename_component(test_name ${test_src} NAME_WE) # Extract filename without extension
    string(REPLACE ".test" "" test_name ${test_name}) # Remove '.test' from the name

    add_executable(${test_name}.test ${test_src})
    target_link_libraries(${test_name}.test PRIVATE EsHangulCpp Catch2::Catch2WithMain)
    add_test(NAME ${test_name} COMMAND ${test_name}.test)
endforeach()