#ifndef COMPMATH4_POLYNOMIAL_REGRESSION_H
#define COMPMATH4_POLYNOMIAL_REGRESSION_H
#include <vector>
#include <cmath>

class Polynomial_regression {
    double mean;
    double std;

    std::vector<double> fit(
            const std::vector<double>& data_x,
            const std::vector<double>& data_y,
            int degree
    );
public:
    static double residual_square_sum(const std::vector<double> &coeffs, const std::vector<double> &X, const std::vector<double> &Y);
    Polynomial_regression() = default;
    std::vector<double> fit(const std::vector<double>& data_x,
                            const std::vector<double>& data_y);
    std::vector<double> fit(const std::pair<std::vector<double>, std::vector<double>>& data);
};


#endif //COMPMATH4_POLYNOMIAL_REGRESSION_H
