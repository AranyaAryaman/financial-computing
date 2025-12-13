#include "BinomialTreeModel.h"
#include <iostream>
#include <cmath>
namespace fre{
    double BinomialTreeModel::RiskNeutProb() const {
        return (R - D) / (U - D);
    }
    double BinomialTreeModel::CalculateAssetPrice(int n, int i) const {
        return S0 * pow(U, i) * pow(D, n - i);
    }
    void BinomialTreeModel::UpdateBinomialTreeModel(double S0_, double U_, double D_, double R_) {
        S0 = S0_;
        U = U_;
        D = D_;
        R = R_;
    }
    void BinomialTreeModel::GetInputData(){
        using std::cout;
        using std::cin;
        using std::endl;
        cout << "Enter S0 (Initial Stock Price): ";
        cin >> S0;
        cout << "Enter U (Up Factor): ";
        cin >> U;
        cout << "Enter D (Down Factor): ";
        cin >> D;
        cout << "Enter R (Risk-Free Rate): ";
        cin >> R;  
        cout << endl;
        validateInputData();
    }

    void BinomialTreeModel::validateInputData() const {
        if(S0<=0.0 || D<=0.0 || U<=0.0 || R<=0.0 || U<=D){
            throw std::invalid_argument("Illegal data range: S0, U, D, R must be positive and U>D");
        }
        if(R>=U || U<=D){
            throw std::invalid_argument("Arbitrage exists: Must satisfy D<R<U");
        }
        std::cout << "Input data is valid." << std::endl;
        std::cout << "There is no arbitrage" << std::endl;
    }
}
