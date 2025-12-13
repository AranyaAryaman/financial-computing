#include "BinomialTreeModel.h"
#include "Option04.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace fre;

int main(){
    int N=8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K = 100.00;
    double K1 = 100.00, K2 = 110.00;
    BinomialTreeModel binModel(S0, U, D, R);
    Call call(N, K);
    Put put(N, K);
    BullSpread bullSpread(N, K1, K2);
    BearSpread bearSpread(N, K1, K2);
    OptionCalculation optionCalculation(&call);
    try{
        binModel.validateInputData();
        cout << "European call option price = " << fixed << setprecision(2) << optionCalculation.PriceByCRR(binModel) << endl;
        optionCalculation.updateOption(&put);
        cout << "European put option price = " << fixed << setprecision(2) << optionCalculation.PriceByCRR(binModel) << endl;
        optionCalculation.updateOption(&bullSpread);
        cout << "European bull spread option price = " << fixed << setprecision(2) << optionCalculation.PriceByCRR(binModel) << endl;
        optionCalculation.updateOption(&bearSpread);
        cout << "European bear spread option price = " << fixed << setprecision(2) << optionCalculation.PriceByCRR(binModel) << endl;
    }
    catch (const exception& e){
        cerr << "Exception: " << e.what() << endl;
        return -1;
    } catch (...){
        cerr << "An unexpected error occurred." << endl;
        return -1;
    }

    return 0;
}

/*
Input data is valid.
There is no arbitrage
European call option price = 21.68
European put option price = 11.43
European bull spread option price = 4.72
European bear spread option price = 4.86
*/