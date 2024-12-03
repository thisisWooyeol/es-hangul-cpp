# Find or Fetch Google Benchmark
find_package(benchmark 3 QUIET)
if (NOT benchmark_FOUND)
    message(STATUS "Using FetchContent to load Google Benchmark")
    include(FetchContent)

    # Set options for Google Benchmark
    set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Enable testing for Google Benchmark" FORCE)
    set(CMAKE_BUILD_TYPE Release) # Google Benchmark is built in Release mode

    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
    )
    FetchContent_Declare(
        googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.9.1
    )
    FetchContent_MakeAvailable(
        googletest
        googlebenchmark
    )
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

function(es_hangul_cpp_add_benchmark NAME SOURCE)
    add_executable(${NAME}.bench ${SOURCE})
    target_link_libraries(${NAME}.bench PRIVATE EsHangulCpp benchmark::benchmark)
endfunction()

es_hangul_cpp_add_benchmark(josa josa.bench.cpp)