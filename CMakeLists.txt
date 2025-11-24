cmake_minimum_required(VERSION 3.28)
project(PolyFac)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
    src/polynomial/Polynomial.h
)

set(SOURCES
    src/polynomial/Polynomial.cpp
)

set(TEST_HEADERS
    test/polynomial/PolynomialTest.h
)

set(TEST_SOURCES
    test/polynomial/PolynomialTest.cpp
)

add_executable(PolyFac src/main.cpp ${HEADERS} ${SOURCES})
add_executable(PolyFacTest test/test.cpp ${HEADERS} ${SOURCES} ${TEST_HEADERS} ${TEST_SOURCES})

enable_testing()

add_test(
        NAME PolyFacTest
        COMMAND $<TARGET_FILE:PolyFacTest>
)
