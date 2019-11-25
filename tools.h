#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <string>
#include <queue>
#include <stack>
#include "Operations.h"

using namespace std;

vector<string> parseExpr(const string & expr);
bool isOneSymbolOperator(char c);
queue<shared_ptr<Node>> parseTokens(const vector<string> & tokens);
double calcRPN(queue<shared_ptr<Node>> rpn);

#endif // TOOLS_H
