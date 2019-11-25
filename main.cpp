#include <iostream>
#include <queue>
#include <ctype.h>
#include <algorithm>
#include "Node.h"
#include "Operations.h"
#include "tools.h"

using namespace std;

int main()
{
    string expr("7-2.3^0.5-(-22/2+3)");
    cout << "Expression: " << expr << endl;

    auto tokens = parseExpr(expr);
    auto rpn = parseTokens(tokens);
    cout << "Answer: " << calcRPN(rpn) << endl;

    return 0;
}
