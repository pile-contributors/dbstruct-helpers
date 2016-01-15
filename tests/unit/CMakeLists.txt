
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Will accumulate the source files
list(APPEND modules_testing_src
    "dbcolumn-ctors-tests.cc"
    "dbcolumn-set-tests.cc")

if (modules_testing_src)
    list( REMOVE_DUPLICATES modules_testing_src )
    add_executable("internal-test"
        ${modules_testing_src}
    )
    qt5_use_modules("internal-test" Core Widgets Sql)
    target_link_libraries ( "internal-test"
        ${GTEST_BOTH_LIBRARIES}
        ${DBSTRUCT_LIBRARY}
    )
    set ( props "${PROJECT_NAME_UPPER}_INTERNAL_TESTS=1")
    set_target_properties ( internal-test
        PROPERTIES COMPILE_DEFINITIONS "${props}"
    )
endif (modules_testing_src)

