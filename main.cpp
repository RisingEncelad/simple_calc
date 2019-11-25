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
    string expr("7+2.3^1.5-(22/2+3)");
    cout << "Expression: " << expr << endl;

    auto tokens = parseExpr(expr);

    stack<shared_ptr<Node>> s;
    queue<shared_ptr<Node>> rpn;

    for (auto & t : tokens) {
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
            cout << "Try make operation " << t << endl;
            shared_ptr<Operation_t> op = makeOperation(t);
            while (!s.empty() && dynamic_pointer_cast<Operation_t>(s.top())->priority >= op->priority) {
                rpn.push(s.top());
                s.pop();
            }
            s.push(op);
            cout << "end add operation\n";
        }
    }

    while (!s.empty()) {
        rpn.push(s.top());
        s.pop();
    }

    s = stack<shared_ptr<Node>>();
    while (!rpn.empty()) {
        if (typeid(*rpn.front()) == typeid(Numerical)) {
            s.push(rpn.front());
        }
        else {
            shared_ptr<Operation_t> op = dynamic_pointer_cast<Operation_t>(rpn.front());
            op->get_arg(s);
            op->Print();
            cout << endl;
            s.push(make_shared<Numerical>(op->evalute()));
        }
        rpn.pop();
    }

    cout << "Answer: " << s.top()->evalute() << endl;

    return 0;
}
