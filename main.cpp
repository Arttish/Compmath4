#include <fstream>
#include "generator/Generator.h"
#include "functions/func1.h"
#include "pregresion/Polynomial_regression.h"
#include "functions/Polynomial.h"
#include "scaller/StandartScaller.h"

int main(int argc, char** argv) {
    int i = 1;
    double start, end, step, noise;

    start = std::stod(argv[i++]);
    end = std::stod(argv[i++]);
    step = std::stod(argv[i++]);
    noise = std::stod(argv[i++]);

    std::ofstream s("../data.txt");
    std::ofstream answer("../ans.txt");
    std::ofstream res("../res.txt");

    Generator gen(noise, &s);
    Generator ans_gen(0, &answer);
    Generator res_gen(0);

    IFunc* f = new func1;

    auto data = gen.generate(f, start, end, step);
    ans_gen.generate(f, start, end, step);

    StandardScaler sx(data.first), sy(data.second);
    Polynomial_regression pr{};

    IFunc* p = new Polynomial(pr.fit(sx.transform(), sy.transform()));

    auto result = res_gen.generate(p, sx.transform());

    result = std::make_pair(sx.transform_back(result.first), sy.transform_back(result.second));

    for (int j = 0; j < result.first.size(); ++j) {
        res << result.first[j] << " " << result.second[j] << '\n';
    }

    std::cout << (*(dynamic_cast<Polynomial*>(p)));
    delete f;
    delete p;
    return 0;
}
