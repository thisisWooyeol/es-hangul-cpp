# Find ICU Libraries
# ! NOTE: You need to set the ICU_ROOT variable to the root directory of the ICU installation
find_package(ICU REQUIRED COMPONENTS uc i18n)

# Include ICU directories and libraries
set(ICU_INCLUDE_DIRS "${ICU_INCLUDE_DIRS}")
set(ICU_LIBRARIES "${ICU_LIBRARIES}")

# Create an EsHangulCpp library
file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

add_library(EsHangulCpp STATIC ${SOURCES})

target_include_directories(EsHangulCpp PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${ICU_INCLUDE_DIRS}
)
target_link_libraries(EsHangulCpp PUBLIC
    ${ICU_LIBRARIES}
)