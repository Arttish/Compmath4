#include "Generator.h"
#include <fstream>
#include <random>

std::random_device rd;

std::pair<std::vector<double>, std::vector<double>> Generator::generate(IFunc *func, double start, double end, double step, bool transform) {
    std::pair<std::vector<double>, std::vector<double>> data;
    double x = start;
    while (x <= end) {
        data.first.push_back(x);
        data.second.push_back(func->calculate(x) + dist(gen));
        x += step;
    }

    if (transform){
        double mean_x, mean_y, std_x = 0, std_y = 0;
        mean_x = std::reduce(data.first.begin(), data.first.end()) / (double) data.first.size();
        mean_y = std::reduce(data.second.begin(), data.second.end()) / (double) data.second.size();

        for (auto& a: data.first) {
            std_x += std::pow(a - mean_x, 2);
        }

        std_x = std::sqrt(std_x / (double) data.first.size());

        for (auto& a: data.first) {
            a = (a - mean_x) / std_x;
        }



        for (auto& a: data.second) {
            std_y += std::pow(a - mean_y, 2);
        }

        std_y = std::sqrt(std_y / (double) data.first.size());

        for (auto& a: data.second) {
            a = (a - mean_y) / std_y;
        }
    }

    if (stream)
        for (int i = 0; i < data.first.size(); ++i)
            *stream << data.first[i] << ' ' << data.second[i] << '\n';

    return data;
}

Generator::Generator(double noise, std::ostream *stream) : stream(stream), gen(rd()), dist(-noise, noise) {}

std::pair<std::vector<double>, std::vector<double>> Generator::generate(IFunc *func, std::vector<double> X) {
    std::vector<double> res;
    res.reserve(X.size());
    for (auto& x: X) {
        res.push_back(func->calculate(x));
    }

    if (stream)
        for (int i = 0; i < X.size(); ++i)
            *stream << X[i] << ' ' << res[i] << '\n';
    return std::make_pair(X, res);
}





