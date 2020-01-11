#include "test_functions.h"
#include "RPN.h"

void testParserExpr() {
    AssertEqual(parseExpr(" 1+ 2 "), vector<string>({"1", "+", "2"}));
    AssertEqual(parseExpr(" 1   + 2 "), vector<string>({"1", "+", "2"}));
    AssertEqual(parseExpr(" 1.2 + - 0.5 "), vector<string>({"1.2", "+", "-", "0.5"}));
    AssertEqual(parseExpr("1+2-3+4"), vector<string>({"1", "+", "2", "-", "3", "+", "4"}));
    AssertEqual(parseExpr("1+2-3*4/5^6!"), vector<string>({"1", "+", "2", "-", "3", "*", "4", "/", "5", "^", "6", "!"}));
    AssertEqual(parseExpr("(1+2)"), vector<string>({"(", "1", "+", "2", ")"}));
    AssertEqual(parseExpr("(1+2)*4"), vector<string>({"(", "1", "+", "2", ")", "*", "4"}));
    AssertEqual(parseExpr("sin(1+2)"), vector<string>({"sin", "(", "1", "+", "2", ")"}));
}
