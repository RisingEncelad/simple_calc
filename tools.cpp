#include "tools.h"

vector<string> parseExpr(const string & expr)
{
    auto endIt = expr.end();
    vector<string> rez;
    for (auto it = expr.begin(); it < endIt; ) {
        if (isdigit(*it)) {
            auto tmp = it+1;
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
            auto tmp = it+1;
            while (tmp != endIt && *tmp != '(')
                ++tmp;
            rez.push_back(string(it, tmp));
            it = tmp;
        }
    }
    return rez;
}

bool isOneSymbolOperator(const char c) {
    static const vector<char> arr = {'(', ')', ',', '+', '-', '*', '/', '^', '!'};
    for (auto s : arr)
        if (s == c)
            return true;
    return false;
}



queue<shared_ptr<Node>> parseTokens(const vector<string> & tokens) {
    stack<shared_ptr<Node>> s;
    queue<shared_ptr<Node>> rpn;

    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        auto t = *it;
        if (isdigit(t[0]))
           rpn.push(make_shared<Numerical>(atof(t.c_str())));
        else if (t[0] == ',')
            continue;
        else if (t == "(")
            s.push(make_shared<Bracket_t>(t));
        else if (t == ")") {
            while (s.top()->strVal() != "(") {
                rpn.push(s.top());
                s.pop();
            }
            s.pop();
        }
        else {
            shared_ptr<Operation_t> op;
            if (it == tokens.begin() || isOneSymbolOperator((it-1)->at(0)))
                op = makeSpecialUnarOperation(t);
            else
                op = makeOperation(t);
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

