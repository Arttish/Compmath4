#ifndef COMPMATH4_GENERATOR_H
#define COMPMATH4_GENERATOR_H
#include <iostream>
#include <vector>
#include "../functions/IFunc.h"
#include <random>



class Generator {
protected:
    std::ostream* stream;

    std::mt19937_64 gen;
    std::uniform_real_distribution<double> dist;

public:
    explicit Generator(double noise, std::ostream *stream = nullptr);
    std::pair<std::vector<double>, std::vector<double>> generate(IFunc* func, double start, double end, double step, bool transform = false);
    std::pair<std::vector<double>, std::vector<double>> generate(IFunc* func, std::vector<double> X);
    ~Generator() = default;
};


#endif //COMPMATH4_GENERATOR_H
