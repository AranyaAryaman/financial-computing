#pragma once

namespace fre {
	//pricing European option
	double PriceByCRR(double S0, double U, double D, double R, const int N, double K);

	//computing call payoff
	double CallPayoff(double z, double K);

	//helper function for computing binomial coefficient
	double PricyByCRRHelper(double q, double i, double N);

	double nck(double n, double k);
}