#include "Option01.h"
#include "BinomialTreeModel.h"
#include <iostream>
#include <cmath>

namespace fre {

    double nck(double n, double k)
    {
        int nMinusk = n - k;
        if (k > nMinusk) k = nMinusk;
        double ans = 1.0;
        for(int i=1;i<=n-k;i++){
            ans *= (double)(k+i);
            ans /= (double)(i);
        }
        return ans;
    }

    double PriceByCRR(double S0, double U, double D, double R, const int N, double K)
    {
        double q = RiskNeutProb(U, D, R);
        double Price[N+1] = { 0.0 };
           
        for (int i = 0; i <= N; i++)
        {
            Price[i] = CallPayoff(CalculateAssetPrice(S0, U, D, N, i), K);
        }
        double PriceToday = 0.0;
        for(int i=0;i<=N;i++){
            PriceToday += nck(N,i)*(double)pow(q,i)*(double)pow(1-q,N-i)*Price[i];
        }
        return PriceToday/(double)pow(R,N);
    }

    double CallPayoff(double z, double K)
    {
        if (z > K) return z - K;
        return 0.0;
    }
}
