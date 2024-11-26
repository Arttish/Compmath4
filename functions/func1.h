#ifndef COMPMATH4_FUNC1_H
#define COMPMATH4_FUNC1_H
#include "IFunc.h"

class func1: public IFunc{
    double calculate(double x) override;
    ~func1() override = default;
};


#endif //COMPMATH4_FUNC1_H
