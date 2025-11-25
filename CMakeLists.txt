cmake_minimum_required(VERSION 3.28)
project(PolyFac)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
        src/polynomial/Polynomial.h
        src/math/Integer.h
        src/math/Rational.h
        src/math/CoefficientDomain.h
        src/math/CoefficientField.h
        lib/imath/imath.h
        lib/imath/imrat.h
)

set(SOURCES
        src/polynomial/Polynomial.tpp
        src/math/Integer.cpp
        src/math/Rational.cpp
        lib/imath/imath.c
        lib/imath/imrat.c
)

set(TEST_HEADERS
        test/polynomial/PolynomialTest.h
        test/math/IntegerTest.h
        test/math/RationalTest.h
        test/Assertions.h
)

set(TEST_SOURCES
        test/polynomial/PolynomialTest.cpp
        test/math/IntegerTest.cpp
        test/math/RationalTest.cpp
)

add_executable(PolyFac src/main.cpp ${HEADERS} ${SOURCES})
add_executable(PolyFacTest test/test.cpp ${HEADERS} ${SOURCES} ${TEST_HEADERS} ${TEST_SOURCES})

enable_testing()

add_test(
        NAME PolyFacTest
        COMMAND $<TARGET_FILE:PolyFacTest>
)
