#include <cstdio>
#include "polynomial/PolynomialTest.h"
#include "math/IntegerTest.h"

typedef bool (*TestFunction)();

int main() {
    static TestFunction tests[] = { testInteger, testPolynomial };
    static char const *testNames[] = { "testInteger", "testPolynomial" };
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        printf("Running %s: ", testNames[i]);
        bool success = tests[i]();
        printf("%s\n", success ? "PASS" : "FAIL");
    }
    return 0;
}
