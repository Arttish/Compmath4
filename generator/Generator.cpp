#include "Generator.h"
#include <fstream>
#include <random>

std::random_device rd;

std::pair<std::vector<double>, std::vector<double>> Generator::generate(IFunc *func, double start, double end, double step) {
    std::pair<std::vector<double>, std::vector<double>> data;
    double x = start;
    while (x <= end) {
        data.first.push_back(x);
        data.second.push_back(func->calculate(x) + dist(gen));
        x += step;
    }

    if (stream)
        for (int i = 0; i < data.first.size(); ++i)
            *stream << data.first[i] << ' ' << data.second[i] << '\n';

    return data;
}

Generator::Generator(double noise, std::ostream *stream) : stream(stream), gen(rd()), dist(-noise, noise) {}



