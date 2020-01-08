#include "Operations.h"

shared_ptr<Operation_t> makeOperation(const string & str){
    if (str_to_binary_operation.find(str) != str_to_binary_operation.end())
        return str_to_binary_operation.at(str)();
    else
        return nullptr;
}

shared_ptr<Operation_t> makeUnaryOperation(const string & str){
    if (str_to_unary_operation.find(str) != str_to_unary_operation.end())
        return str_to_unary_operation.at(str)();
    else
        return nullptr;
}
