#include "Operations.h"

shared_ptr<Operation_t> makeOperation(const string & str){
    if (strToOperation.find(str) != strToOperation.end())
        return strToOperation.at(str)();
    else
        return nullptr;
}

shared_ptr<Operation_t> makeUnaryOperation(const string & str){
    if (strToUnaryOperation.find(str) != strToUnaryOperation.end())
        return strToUnaryOperation.at(str)();
    else
        return nullptr;
}
