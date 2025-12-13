#include "Option04.h"
#include <iostream>
#include <cmath>
#include "BinomialTreeModel.h"

using namespace std;

namespace fre{
    EurOption::~EurOption() {}

    double Call::PayOff(double z) const {
        return std::max(0.0, z - K);
    }

    double Put::PayOff(double z) const {
        return std::max(0.0, K - z);
    }

    double BullSpread::PayOff(double z) const {
        if(z<=K1)   return 0.0;
        else if(z>K1 && z<K2) return z - K1;
        else        return K2 - K1;
    }

    double BearSpread::PayOff(double z) const {
        if(z>=K2)   return 0.0;
        else if(z<K2 && z>K1) return K2 - z;
        else        return K2 - K1;
    }

    double OptionCalculation::PriceByCRR(const BinomialTreeModel& Model){
        if(pOption == nullptr){
            throw std::invalid_argument("OptionCalculation: pOption pointer is null");
        }
        double optionPrice = 0.0;
        double q = Model.RiskNeutProb();
        int N = pOption->GetN();
        double* pPrice = new double[N + 1]{0.0};
        for(int i=0;i<=N;i++)
            pPrice[i] = pOption->PayOff(Model.CalculateAssetPrice(N, i));
        for(int n=N-1;n>=0;n--){
            for(int i=0;i<=n;i++){
                pPrice[i] = (q * pPrice[i + 1] + (1 - q) * pPrice[i]) / Model.GetR();
            }
        }
        optionPrice = pPrice[0];
        delete[] pPrice;
        pPrice = nullptr;
        return optionPrice;
    }
}