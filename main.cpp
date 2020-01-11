#include <iostream>
#include <queue>
#include <ctype.h>
#include <algorithm>
#include "Node.h"
#include "Operations.h"
#include "RPN.h"
#include "test_framework.h"

using namespace std;

int main()
{
    string expr("(2+-5!)");
    cout << "Expression: " << expr << endl;
    try {
        auto tokens = parseExpr(expr);
        auto rpn = parseTokens(tokens);
        cout << "Answer: " << calcRPN(rpn) << endl;
    }  catch (exception & e) {
        cout << "Catch exception: " << e.what() << endl;
    }
    return 0;
}


