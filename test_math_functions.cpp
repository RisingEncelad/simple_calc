#include "test_functions.h"
#include "RPN.h"

void testMathFunctions() {
// Factorial
    AssertEqual(calcExpr("0!"), 1, "Test factorial");
    AssertEqual(calcExpr("1!"), 1, "Test factorial");
    AssertEqual(calcExpr("2!"), 2, "Test factorial");
    AssertEqual(calcExpr("3!"), 6, "Test factorial");
    AssertEqual(calcExpr("4!"), 24, "Test factorial");
    AssertEqual(calcExpr("5!"), 120, "Test factorial");
}
