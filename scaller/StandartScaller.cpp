#include <numeric>
#include <cmath>
#include "StandartScaller.h"

StandardScaler::StandardScaler(const std::vector<double> &v): v(v), std(0) {
    mean = std::reduce(v.begin(), v.end()) / (double) v.size();
    for (auto& a: v) {
        std += std::pow(a - mean, 2);
    }

    std = std::sqrt(std / (double) v.size());
}

std::vector<double> StandardScaler::transform() {
    std::vector<double> res;
    res.reserve(v.size());
    for (auto& a: v) {
        res.push_back((a - mean) / std);
    }
    return res;
}

std::vector<double> StandardScaler::transform_back(const std::vector<double>& vec) const {
    std::vector<double> res;
    res.reserve(vec.size());
    for (auto& a: vec) {
        res.push_back(a * std + mean);
    }
    return res;
}
