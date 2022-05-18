#include "card_premium.h"
#include <bits/stdc++.h>

using namespace std;

CardPremium::CardPremium():CardStandard(){
    cashback = 0;
}

CardPremium::CardPremium(string nrCard, string NumeDetinator, string data_expirarii, int cvv, double credit, int withdrawalLimit, double commission, double cashback):CardStandard(nrCard, NumeDetinator, data_expirarii, cvv, credit, withdrawalLimit, commission){
    this->cashback = cashback;
}

CardPremium::CardPremium(const CardPremium& card){
    nrCard = card.nrCard;
    NumeDetinator = card.NumeDetinator;
    data_expirare = card.data_expirare;
    cvv = card.cvv;
    credit = card.credit;
    withdrawalLimit = card.withdrawalLimit;
    commission = card.commission;
    cashback = card.cashback;
}

CardPremium::~CardPremium(){
    nrCard = "";
    NumeDetinator = "";
    data_expirare = "";
    cvv = 0;
    credit = 0;
    withdrawalLimit = 0;
    commission = 0;
    cashback = 0;
}

double CardPremium::GetCashback() const{
    return cashback;
}

void CardPremium::SetCashback(double cashback){
    this->cashback = cashback;
}

void CardPremium::Citire(){
    cout<<"Numarul cardului: ";
    cin.get();
    getline(cin, nrCard);
        
    cout<<"Numele detinatorului: ";
    getline(cin, NumeDetinator);

    cout<<"Data expirare card: ";
    getline(cin, data_expirare);

    string cvv_invalid = "Cvv-ul introdus trebuie sa fie intre 100 si 999";
    bool ok = false;
    while(ok == false)
    {
        ok = true;
        try{
            cout<<"Cod Cvv: ";
            cin>>cvv;

            if(!(cvv >= 100 && cvv <= 999))
                throw cvv_invalid;
        }
        catch(string x)
        {
            cout<<cvv_invalid<<endl;
            ok = false;
        }
    }
    cout<<"Premium"<<endl;
    string credit_invalid = "Creditul cardului este invalid";
    ok = false;

    while(ok == false)
    {
        ok = true;
        try{
        cout<<"Credit card: ";
        cin>>credit;

        if(credit < 0)
        {
            throw credit_invalid;
        }
        }
        catch(string x){
            cout<<credit_invalid<<endl;
            ok = false;
        }
    }
    cout<<"Limita extragere: ";
    cin>>withdrawalLimit;
    cout<<"Comision extragere: ";
    cin>>commission;

    cout<<"Cashback: ";
    cin>>cashback;
}

void CardPremium::Afisare(){
    cout<<"Numarul cardului: "<<nrCard<<endl;
    cout<<"Numele detinatorului: "<<NumeDetinator<<endl;
    cout<<"Data expirare: "<<data_expirare<<endl;
    cout<<"Cod Cvv: "<<cvv<<endl;
    cout<<"Credit card: "<<credit<<endl;
    cout<<"Limita extragere: "<<withdrawalLimit<<endl;
    cout<<"Comision extragere: "<<commission<<endl;
    cout<<"Cashback: "<<cashback<<endl;
}

void CardPremium::Withdraw(double money)
{
    double new_cashback;
    if(credit < money)
    {
        cout<<"Credit insuficient"<<endl;
        return;
    }
    else{
        credit = credit - money;
        new_cashback = (cashback/100)*money;
        SetCredit(credit + new_cashback);
    }
    cout<<"Extragere reusita! Cashback-ul obtinut in urma tranzatiei este "<<new_cashback<<endl;
    cout<<"Creditul curent: "<<credit<<endl;
}