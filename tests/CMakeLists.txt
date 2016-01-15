# ============================================================================
#
# This file hosts all tests.
#
# If INCLUDE_PILE_SOURCES_DIRECTLY is ON then DBSTRUCT_SOURCES and
# DBSTRUCT_HEADERS are defined we add them to the executable. DBSTRUCT_LIBRARY
# is empty.
#
# On the other hand if INCLUDE_PILE_SOURCES_DIRECTLY is
# OFF then DBSTRUCT_SOURCES and DBSTRUCT_HEADERS are empty and we link
# against DBSTRUCT_LIBRARY that is now the name of the target that
# builds the library.
#
# ============================================================================

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

if (NOT INCLUDE_PILE_SOURCES_DIRECTLY)
    set (DBSTRUCT_LIBRARY dbstruct)
endif()

if (UNIX)
    find_package(Threads REQUIRED)
    list(APPEND GTEST_BOTH_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
    add_definitions(-fPIC)
endif()

enable_testing()
add_subdirectory("unit")
add_subdirectory("integration")

