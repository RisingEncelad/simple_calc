#include "RPN.h"
#include <algorithm>

vector<string> parseExpr(const string & expr)
{
    auto endIt = expr.end();
    vector<string> rez;
    for (auto it = expr.begin(); it < endIt; ) {
        if (isdigit(*it)) {
            auto tmp = it + 1;
            while (tmp != endIt && (isdigit(*tmp) || '.' == *tmp))
                ++tmp;
            rez.push_back(string(it, tmp));
            it = tmp;
        }
        else if (isOneSymbolOperator(*it)) {
            rez.push_back(string(1, *it));
            ++it;
        }
        else {
            auto tmp = it + 1;
            while (tmp != endIt && !isOneSymbolOperator(*it))
                ++tmp;
            rez.push_back(string(it, tmp));
            it = tmp;
        }
    }
    return rez;
}

bool isOneSymbolOperator(const char op) {
    auto n = string("(),+-*/^!").find(op);
    return n != string::npos;
}

queue<shared_ptr<Node>> parseTokens(const vector<string> & tokens) {
    stack<shared_ptr<Node>> s;
    queue<shared_ptr<Node>> rpn;

    for (auto tokenIt = tokens.begin(); tokenIt != tokens.end(); ++tokenIt) {
        auto token = *tokenIt;
        if (isdigit(token[0]))
           rpn.push(make_shared<Numerical>(atof(token.c_str())));
        else if (token == ",")
            continue;
        else if (token == "(")
            s.push(make_shared<Bracket_t>(token));
        else if (token == ")") {
            while (typeid(*s.top()) != typeid(Bracket_t)) {
                rpn.push(s.top());
                s.pop();
            }
            s.pop();
        }
        else {
            shared_ptr<Operation_t> op;
            if  (   (token == "+" || token == "-") && ( tokenIt == tokens.begin() ||
                    (isOneSymbolOperator((tokenIt-1)->at(0)) && (tokenIt-1)->at(0) != '!') )
                )
            {
                op = makeUnaryOperation(token);
            }
            else
                op = makeOperation(token);

            while (!s.empty() && dynamic_pointer_cast<Operation_t>(s.top())->priority >= op->priority) {
                rpn.push(s.top());
                s.pop();
            }
            s.push(op);
        }
    }

    while (!s.empty()) {
        rpn.push(s.top());
        s.pop();
    }
    return rpn;
}

double calcRPN(queue<shared_ptr<Node>> rpn) {
    stack<shared_ptr<Node>> s;
    while (!rpn.empty()) {
        if (typeid(*rpn.front()) == typeid(Numerical)) {
            s.push(rpn.front());
        }
        else {
            shared_ptr<Operation_t> op = dynamic_pointer_cast<Operation_t>(rpn.front());
            op->get_arg(s);
            s.push(make_shared<Numerical>(op->evalute()));
        }
        rpn.pop();
    }

    return s.top()->evalute();
}
