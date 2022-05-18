#include "card_standard.h"
#include <bits/stdc++.h>

using namespace std;

CardStandard::CardStandard():Card(){
    withdrawalLimit = 0;
    commission = 0;
}

CardStandard::CardStandard(string nrCard, string NumeDetinator, string data_expirarii, int cvv, double credit,int withdrawalLimit, double commission):Card(nrCard, NumeDetinator, data_expirarii, cvv, credit)
{
    this->withdrawalLimit = withdrawalLimit;
    this->commission = commission;
}

CardStandard::CardStandard(const CardStandard& card)
{
    nrCard = card.nrCard;
    NumeDetinator = card.NumeDetinator;
    data_expirare = card.data_expirare;
    cvv = card.cvv;
    credit = card.credit;
    withdrawalLimit = card.withdrawalLimit;
    commission = card.commission;
}

CardStandard::~CardStandard(){
    nrCard = "";
    NumeDetinator = "";
    data_expirare = "";
    cvv = 0;
    credit = 0;
    withdrawalLimit = 0;
    commission = 0;
}

int CardStandard::GetWithdrawalLimit() const{
    return withdrawalLimit;
}

double CardStandard::GetCommission() const{
    return commission;
}

void CardStandard::SetWithdrawalLimit(int withdrawalLimit){
    this->withdrawalLimit = withdrawalLimit;
}

void CardStandard::SetCommission(double commission){
    this->commission = commission;
}

void CardStandard::Citire()
{
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

}

void CardStandard::Afisare()
{
    cout<<"Numarul cardului: "<<nrCard<<endl;
    cout<<"Numele detinatorului: "<<NumeDetinator<<endl;
    cout<<"Data expirare: "<<data_expirare<<endl;
    cout<<"Cod Cvv: "<<cvv<<endl;
    cout<<"Credit card: "<<credit<<endl;
    cout<<"Limita extragere: "<<withdrawalLimit<<endl;
    cout<<"Comision extragere: "<<commission<<endl;
}

void CardStandard::Withdraw(double money)
{
    double creditWithCommission = credit - money - commission/100 * money;
    if(credit < money)
    {
        cout<<"Fonduri insuficiente pe cardul "<<nrCard<<endl;
        return;
    }
    else if(money <= withdrawalLimit){
        credit = credit - money;
    }
    else if(withdrawalLimit < money && credit > money && creditWithCommission>=0)
    {
        credit = creditWithCommission;
    }
    cout<<"Creditul actual de pe cardul "<<nrCard<<" : "<<credit<<endl;
}

