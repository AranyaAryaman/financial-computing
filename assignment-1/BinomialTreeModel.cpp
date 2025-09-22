#include "BinomialTreeModel.h"
#include <iostream>
#include <cmath>

namespace fre {
    // compute risk-neutral probability
    double RiskNeutProb(double U, double D, double R)
    {
        return (R - D) / (U - D);
    }

    // compute the asset price at node n,i
    double CalculateAssetPrice(double S0, double U, double D, int n, int i)
    {
        return S0 * std::pow(U, i) * std::pow(D, n - i);
    }

    // input and display, check model data
    int GetInputData(double& S0, double& U, double& D, double& R)
    {
        // entering data
        std::cout << "Enter S0: "; std::cin >> S0;
        std::cout << "Enter U:  "; std::cin >> U;
        std::cout << "Enter D:  "; std::cin >> D;
        std::cout << "Enter R:  "; std::cin >> R;
        std::cout << std::endl;

        // making sure that S0>0, U>D>0, R>0 
        if (S0 <= 0.0 || U <= 0.0 || D <= 0.0 || U <= D || R <= 0.0)
        {
            std::cerr << "Illegal data ranges" << std::endl;
            std::cerr << "Terminating program" << std::endl;
            return -1;
        }

        // checking for arbitrage
        if (R >= U || U <= D)
        {
            std::cerr << "Arbitrage exists" << std::endl;
            std::cerr << "Terminating program" << std::endl;
            return -1;
        }

        std::cout << "Input data checked" << std::endl;
        std::cout << "There is no arbitrage" << std::endl << std::endl;

        return 0;
    }

    int ValidateInputData(const double& S0, const double& U, const double& D, const double& R)
    {
        // making sure that S0>0, U>D>0, R>0 
        if (S0 <= 0.0 || U <= 0.0 || D <= 0.0 || U <= D || R <= 0.0)
        {
            std::cerr << "Illegal data ranges" << std::endl;
            std::cerr << "Terminating program" << std::endl;
            return -1;
        }

        // checking for arbitrage
        if (R >= U || U <= D)
        {
            std::cerr << "Arbitrage exists" << std::endl;
            std::cerr << "Terminating program" << std::endl;
            return -1;
        }

        std::cout << "Input data checked" << std::endl;
        std::cout << "There is no arbitrage" << std::endl << std::endl;

        return 0;
    }
}
