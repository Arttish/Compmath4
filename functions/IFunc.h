#ifndef IFUNC
#define IFUNC
#include <ostream>

class IFunc {
public:
    virtual double calculate(double x) = 0;
    virtual ~IFunc() = default;
};

#endif //IFUNC
