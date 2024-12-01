#ifndef COMPMATH4_STANDARTSCALLER_H
#define COMPMATH4_STANDARTSCALLER_H
#include <vector>

class StandardScaler {
    double std;
    double mean;
    const std::vector<double>& v;
public:
    StandardScaler(const std::vector<double>& v);
    std::vector<double> transform();
    std::vector<double> transform_back(const std::vector<double>& vec) const;
};


#endif //COMPMATH4_STANDARTSCALLER_H
