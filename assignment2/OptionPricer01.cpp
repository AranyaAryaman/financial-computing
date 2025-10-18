// OptionPricer01.cpp
//
#include "BinomialTreeModel.h"
#include "Option01.h"
#include <iostream>
#include <iomanip>

int main()
{
    double u = 1.15125, d = 0.86862, r = 1.00545;
    double s0 = 106.00, k = 100.00;
    const int N = 8;

    double optionPrice = fre::PriceByCRR(s0, u, d, r, N, k);
    std::cout << "European call option price = " << std::fixed << std::setprecision(2) << optionPrice << std::endl;

    return 0;
}

/*
European call option price = 21.68
*/

