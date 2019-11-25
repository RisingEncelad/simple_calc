#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "Node.h"
#include <cmath>

shared_ptr<Operation_t> makeOperation(const string & str);
shared_ptr<Operation_t> makeSpecialUnarOperation(const string & str);

class Bracket_t : public Operation_t {
public:
    Bracket_t(const string & s) : Operation_t(s, 0, 0) {}
    string strVal() const override { return name; }
    double evalute() const override { return 0; }
};

class Sum_t : public Operation_t {
public:
    Sum_t() : Operation_t("+", 2, 2) {}
    double evalute() const override {
        return args[0]->evalute() + args[1]->evalute();
    }
};

class Dif_t : public Operation_t {
public:
    Dif_t() : Operation_t("-", 2, 2) {}
    double evalute() const override {
        return args[0]->evalute() - args[1]->evalute();
    }
};

class Mult_t : public Operation_t {
public:
    Mult_t() : Operation_t("*", 3, 2) {}
    double evalute() const override {
        return args[0]->evalute() * args[1]->evalute();
    }
};

class Div_t : public Operation_t {
public:
    Div_t() : Operation_t("/", 3, 2) {}
    double evalute() const override {
        return args[0]->evalute() / args[1]->evalute();
    }
};

class Pow_t : public Operation_t {
public:
    Pow_t() : Operation_t("^", 4, 2) {}
    double evalute() const override {
        return pow(args[0]->evalute(), args[1]->evalute());
    }
};

class Negative_t : public Operation_t {
public:
    Negative_t() : Operation_t("-", 2, 1) {}
    double evalute() const override {
        return -(args[0]->evalute());
    }
};
#endif // OPERATIONS_H
