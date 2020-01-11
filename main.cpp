#include <iostream>
#include <queue>
#include <ctype.h>
#include <algorithm>
#include "Node.h"
#include "Operations.h"
#include "RPN.h"
#include "test_framework.h"
#include "test_functions.h"

using namespace std;
void testAll();


int main()
{
    testAll();
    cout << endl;
    string expr("1+2");
    cout << "Expression: " << expr << endl;
    try {
        cout << "Answer: " << calcExpr(expr) << endl;
    }  catch (exception & e) {
        cout << "Catch exception: " << e.what() << endl;
    }
    return 0;
}


void testAll() {
    TestRunner tr;
    tr.RunTest(testParserExpr, "testParserExpr");
    tr.RunTest(testMathFunctions, "testMathFunctions");
}
