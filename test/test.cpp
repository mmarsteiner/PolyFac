#include <cstdio>
#include "polynomial/PolynomialTest.h"
#include "math/IntegerTest.h"
#include "math/RationalTest.h"

typedef bool (*TestFunction)();

int main() {
    static TestFunction tests[] = { testInteger, testRational, testPolynomial, testPolynomialDiv };
    static char const *testNames[] = { "testInteger", "testRational", "testPolynomial", "testPolynomialDiv" };
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        printf("Running %s: ", testNames[i]);
        bool success = tests[i]();
        printf("%s\n", success ? "PASS" : "FAIL");
    }
    return 0;
}
