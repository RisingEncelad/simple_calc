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

bool isOneSymbolOperator(char c) {
    static const vector<char> arr = {'(', ')', '+', '-', '*', '/', '^', ','};
    for (auto s : arr)
        if (s == c)
            return true;
    return false;
}


