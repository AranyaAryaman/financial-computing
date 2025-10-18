#pragma once

namespace fre {
    // Compute risk-neutral probability
    double RiskNeutProb(double U, double D, double R);

    // Compute the asset price at node n,i
    double CalculateAssetPrice(double S0, double U, double D, int n, int i);

    // Input and display, check model data
    int GetInputData(double& S0, double& U, double& D, double& R);

    // Validate input data for Binomial Tree Model
    int ValidateInputData(const double& S0, const double& U, const double& D, const double& R);
}
