#ifndef COMPMATH4_POLYNOMIAL_H
#define COMPMATH4_POLYNOMIAL_H
#include "IFunc.h"
#include <vector>
#include <utility>
#include <cmath>

class Polynomial: public IFunc{
    std::vector<double> coefficients;
public:
    explicit Polynomial(std::vector<double> coeffs);
    double calculate(double x) override;
};


#endif //COMPMATH4_POLYNOMIAL_H
