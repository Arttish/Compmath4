#include "func1.h"
#include <cmath>

double func1::calculate(double x) {
    return std::pow(x, 4) + std::pow(x, 3) - 5 * std::pow(x, 2) - x + 5;
}
