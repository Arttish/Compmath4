#include "func1.h"
#include <cmath>

double func1::calculate(double x) {
    double y = x - 1e6;
    return 1e8 - (y * y * y) + 5 * y * y;
}
