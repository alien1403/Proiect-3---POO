#ifndef cards
#define cards

#include <bits/stdc++.h>
#include "card.h"

using namespace std;

class CardStandard: public Card{
protected:
    int withdrawalLimit; // limita extragere de pe card
    double commission; // comision depasire limita

public:

    CardStandard(); // constructor de initializare
    CardStandard(string, string, string, int, double, int, double); // constructor parametrizat
    CardStandard(const CardStandard&); // constructor de copiere
    ~CardStandard(); // destructor

    // Getters & Setters

    int GetWithdrawalLimit() const;
    double GetCommission() const;

    void SetWithdrawalLimit(int);
    void SetCommission(double);

    CardStandard& operator= (const CardStandard& card){
        nrCard = card.nrCard;
        NumeDetinator = card.NumeDetinator;
        data_expirare = card.data_expirare;
        cvv = card.cvv;
        credit = card.cvv;
        withdrawalLimit = card.withdrawalLimit;
        commission = card.commission;
        return *this;
    }

    friend istream& operator>>(istream& in, CardStandard& card)
    {
        in>>dynamic_cast<Card&>(card);
        cout<<"Limita extragere: ";
        in>>card.withdrawalLimit;

        cout<<"Comision pentru depasirea limitei (valoare procentuala): ";
        in>>card.commission;

        return in;
    }

    friend ostream& operator<< (ostream& out, CardStandard& card)
    {
        out<<dynamic_cast<Card&>(card);
        out<<"Limita extragere: "<<card.withdrawalLimit<<endl;
        out<<"Comision depasire limita extragere (valoare procentuala): "<<card.commission<<endl;

        return out;
    }

    void Citire();
    void Afisare(); 

    // Metoda

    void Withdraw(double);
};


#endif
