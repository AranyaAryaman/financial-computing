#pragma once
namespace fre{
    class BinomialTreeModel {
    private:
        double S0;
        double U;
        double D;
        double R;
    public:
        BinomialTreeModel():S0(0), U(0), D(0), R(0) {}
        BinomialTreeModel(double S0_, double U_, double D_, double R_): S0(S0_), U(U_), D(D_), R(R_) {}
        BinomialTreeModel(const BinomialTreeModel& model): S0(model.S0), U(model.U), D(model.D), R(model.R) {}
        ~BinomialTreeModel() {}
        double RiskNeutProb() const;
        double CalculateAssetPrice(int n, int i) const;
        void UpdateBinomialTreeModel(double S0_, double U_, double D_, double R_);
        void validateInputData() const;
        void GetInputData();
        double GetS0() const { return S0; }
        double GetU() const { return U; }
        double GetD() const { return D; }
        double GetR() const { return R; }
    };
}