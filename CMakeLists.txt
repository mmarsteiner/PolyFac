cmake_minimum_required(VERSION 3.28)
project(PolyFac)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
        src/polynomial/Polynomial.h
        src/math/Integer.h
        lib/imath/imath.h
        lib/imath/imrat.h
)

set(SOURCES
        src/polynomial/Polynomial.cpp
        src/math/Integer.cpp
        lib/imath/imath.c
        lib/imath/imrat.c
)

set(TEST_HEADERS
        test/polynomial/PolynomialTest.h
        test/math/IntegerTest.h
)

set(TEST_SOURCES
        test/polynomial/PolynomialTest.cpp
        test/math/IntegerTest.cpp
)

add_executable(PolyFac src/main.cpp ${HEADERS} ${SOURCES})
add_executable(PolyFacTest test/test.cpp ${HEADERS} ${SOURCES} ${TEST_HEADERS} ${TEST_SOURCES})

enable_testing()

add_test(
        NAME PolyFacTest
        COMMAND $<TARGET_FILE:PolyFacTest>
)
