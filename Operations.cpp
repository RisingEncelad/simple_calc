#include "Operations.h"

shared_ptr<Operation_t> makeOperation(const string & str){
    if (str == "+")
        return make_shared<Sum_t>();
    else if (str == "-")
        return make_shared<Dif_t>();
    else if (str == "*")
        return make_shared<Mult_t>();
    else if (str == "/")
        return make_shared<Div_t>();
    else if (str == "^")
        return make_shared<Pow_t>();
    else
        return nullptr;
}
