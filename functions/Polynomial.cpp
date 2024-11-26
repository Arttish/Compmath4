#include "Polynomial.h"



Polynomial::Polynomial(std::vector<double> coeffs): coefficients(std::move(coeffs)) {

}

double Polynomial::calculate(double x) {
    double res = 0;
    for (int i = 0; i < coefficients.size(); ++i) {
        res += coefficients[i] * std::pow(x, i);
    }
    return res;
}
