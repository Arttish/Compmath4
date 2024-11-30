#include "Polynomial_regression.h"

#include <utility>
#include <algorithm>
#include "../functions/Polynomial.h"

std::vector<double> Polynomial_regression::fit(const std::vector<double>& data_x, const std::vector<double>& data_y, int degree) {
    std::vector<std::vector<double>> XT, XTX,L(degree + 1, std::vector<double>(degree + 1, 0));
    std::vector<double> XTY, B(degree + 1, 0), z(degree + 1, 0);
    std::vector<double> tmp;
    double a;
    for (int j = 0; j <= degree; ++j) {
        tmp.clear();
        tmp.reserve(data_x.size());
        for (const double &i: data_x)
            tmp.push_back(std::pow(i, j));
        XT.push_back(tmp);
    }

    XTX.reserve(XT.size());
    for (int i = 0; i < XT.size(); ++i) {
        tmp.clear();
        tmp.reserve(XT.size());
        for (int j = 0; j < XT.size(); ++j) {
            a = 0;
            for (int k = 0; k < XT[0].size(); ++k) {
                a += XT[i][k] * XT[j][k];
            }
            tmp.push_back(a);
        }
        XTX.push_back(tmp);
    }

    XTY.reserve(XT.size());
    for (int i = 0; i < XT.size(); ++i) {
        a = 0;
        for (int k = 0; k < XT[0].size(); ++k) {
            a += XT[i][k] * data_y[k];
        }
        XTY.push_back(a);
    }

    for (int j = 0; j < L.size(); ++j) {
        for (int i = 0; i < L.size(); ++i){
            if (j > i) continue;
            if (i == j) {
                a = XTX[i][j];
                for (int k = 0; k < i; ++k) {
                    a -= L[i][k] * L[i][k];
                }
                L[i][j] = std::sqrt(a);
            }
            else {
                a = XTX[i][j];
                for (int k = 0; k < j; ++k) {
                    a -= L[i][k] * L[j][k];
                }
                L[i][j] = a / L[j][j];
            }
        }
    }



    for (int i = 0; i < L.size(); ++i) {
        a = XTY[i];
        for (int j = 0; j < i; ++j) {
            a -= L[i][j] * z[j];
        }
        z[i] = a / L[i][i];
    }

    for (int i = L.size() - 1; i >= 0 ; --i) {
        a = z[i];
        for (int j = L.size() - 1; j > i ; --j) {
            a -= L[j][i] * B[j];
        }
        B[i] = a / L[i][i];
    }

    return B;
}

std::vector<double> Polynomial_regression::fit(const std::vector<double> &data_x, const std::vector<double> &data_y) {
    std::vector<double> res, tmp;
    double bic_res, bic_tmp, rss;
    unsigned int n = data_x.size();

    res = fit(data_x, data_y, 0);
    bic_res = n * std::log(residual_square_sum(res, data_x, data_y) / n) + std::log(n);

    for (int i = 1; i <= 5; ++i) {
        tmp = fit(data_x, data_y, i);
        rss = residual_square_sum(tmp, data_x, data_y);
        bic_tmp = n * std::log( rss / n) + (i + 1) * std::log(n);
        if (bic_tmp < bic_res){
            res = std::move(tmp);
            bic_res = bic_tmp;
        }
    }
    return res;
}

std::vector<double> Polynomial_regression::fit(const std::pair<std::vector<double>, std::vector<double>>& data) {
    return fit(data.first, data.second);
}

double Polynomial_regression::residual_square_sum(const std::vector<double> &coeffs,
                                                  const std::vector<double> &X,
                                                  const std::vector<double> &Y) {
    Polynomial p(coeffs);
    double res = 0;
    for (int i = 0; i < X.size(); ++i) {
        res += std::pow(p.calculate(X[i]) - Y[i], 2);
    }
    return res;
}