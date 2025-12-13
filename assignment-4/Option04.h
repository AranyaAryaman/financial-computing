#pragma once
#include "BinomialTreeModel.h"
namespace fre{
    class EurOption{
        private:
            EurOption() : N(0){}
            EurOption(const EurOption& option): N(option.N) {}
        protected:
            int N;
        public:
            EurOption(int N_): N(N_) {}
            int GetN() const { return N; }
            virtual double PayOff(double z) const = 0; 
            virtual ~EurOption() = 0;
    };

    class Call : public EurOption {
        private:
            double K;
        public:
            Call(int N_, double K_): EurOption(N_), K(K_) {}
            ~Call() {}
            double PayOff(double z) const;
    };

    class Put : public EurOption {
        private:
            double K;
        public:
            Put(int N_, double K_): EurOption(N_), K(K_) {}
            ~Put() {}
            double PayOff(double z) const;
    };

    class BullSpread : public EurOption {
        private:
            double K1;
            double K2;
        public:
            BullSpread(int N_, double K1_, double K2_): EurOption(N_), K1(K1_), K2(K2_) {}
            ~BullSpread() {}
            double PayOff(double z) const;
    };

    class BearSpread : public EurOption {
        private:
            double K1;
            double K2;
        public:
            BearSpread(int N_, double K1_, double K2_): EurOption(N_), K1(K1_), K2(K2_) {}
            ~BearSpread() {}
            double PayOff(double z) const;
    };

    class OptionCalculation{
        private:
            EurOption* pOption;
            OptionCalculation(): pOption(nullptr) {}
            OptionCalculation(const OptionCalculation& optionCalc): pOption(optionCalc.pOption) {}
        public:
            OptionCalculation(EurOption* pOption_): pOption(pOption_) {}
            ~OptionCalculation() {}
            double PriceByCRR(const BinomialTreeModel& Model);
            void updateOption(EurOption* pOption_){ pOption = pOption_; }
    };
}