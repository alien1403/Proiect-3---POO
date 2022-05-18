#ifndef cardp
#define cardp

#include <bits/stdc++.h>
#include "card_standard.h"

using namespace std;
class CardPremium: public CardStandard{

protected:
    double cashback;

public:
    CardPremium(); // constructor de initializare
    CardPremium(string, string, string, int, double, int, double, double); // constructor parametrizat
    CardPremium(const CardPremium&); // constructor de copiere

    ~CardPremium(); // destructor

    //Getters & Setters

    double GetCashback() const;
    void SetCashback(double);

    CardPremium& operator= (const CardPremium& card) // supraincarcarea lui =
    {
        nrCard = card.nrCard;
        NumeDetinator = card.NumeDetinator;
        data_expirare = card.data_expirare;
        cvv = card.cvv;
        credit = card.cvv;
        withdrawalLimit = card.withdrawalLimit;
        commission = card.commission;
        cashback = card.cashback;
        return *this;
    }

    friend istream& operator>>(istream& in, CardPremium& card)
    {

        in>>dynamic_cast<CardStandard&>(card);

        cout<<"Cashback: ";
        in>>card.cashback;
        cout<<endl;

        return in;
    }
    friend ostream& operator<<(ostream& out, CardPremium& card){
        out<<dynamic_cast<CardStandard&>(card);
        out<<"Cashback: "<<card.cashback<<endl;
        return out;
    }

    void Citire();
    void Afisare();

    // Metoda

    void Withdraw(double);
};

#endif
