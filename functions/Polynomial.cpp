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

std::ostream &operator<<(std::ostream &os, Polynomial &p) {
    os << p.coefficients[0];
    for (int i = 1; i < p.coefficients.size(); ++i) {
        os << (p.coefficients[i] < 0? " - " : " + ") << std::abs(p.coefficients[i]) << "x^" << i;
    }
    return os;
}
