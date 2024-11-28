#include <fstream>
#include "generator/Generator.h"
#include "functions/func1.h"
#include "pregresion/Polynomial_regression.h"
#include "functions/Polynomial.h"
#include "functions/func2.h"

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
    Generator res_gen(0, &res);

    IFunc* f = new func1;

    auto data = gen.generate(f, start, end, step);
    ans_gen.generate(f, start, end, step);

    Polynomial_regression pr;

    IFunc* p = new Polynomial(pr.fit(data));

    res_gen.generate(p, start, end, step);

    delete f;
    delete p;
    return 0;
}
