#include <bits/stdc++.h>
#include "card.cpp"
#include "card.h"
#include "card_standard.cpp"
#include "card_standard.h"
#include "card_premium.cpp"
#include "card_premium.h"
#include "gestionare_carduri.cpp"
#include "gestionare_carduri.h"

using namespace std;

// class Card{

// protected:
//     string nrCard, NumeDetinator, data_expirare; // numar card, nume detinator, data expirare card
//     int cvv; // cod de 3 cifre de pe spatele cardului
//     double credit; // valoarea totala de bani care se afla in card

//     static int no_of_cards;

// public:
//     Card(); // constructor de initializare
//     Card(string, string, string, int, double); // constructor in care se initializeaza numarul cardului,
//     //numele detinatorului, data expirarii, cvv-ul si suma totala din acel cont
//     Card(const Card& ); // constructor de copiere

//     virtual ~Card(); // destructor

//     // Getters and Setters

//     string GetNrCard() const; // returneaza numarul cardului
//     string GetNumeDetinator() const; // returneaza numele detinatorului cardului
//     string GetDataExpirare() const; // returneaza data expirarii cardului
//     int GetCvv() const; // returneaza cvv-ul
//     double GetCredit() const; // returneaza suma care se afla in acel cont
//     static int GetNoOfCard(); // returneaza numarul de carduri


//     void SetNrCard(string); // seteaza numarul cardului
//     void SetNumeDetinator(string); // seteaza numele detinatorului cardului
//     void SetDataExpirare(string); // seteaza data de expirare a cardului
//     void SetCvv(int); // seteaza cvv-ul
//     void SetCredit(double); // seteaza valoarea creditului de pe card
//     void static SetNoOfCards(int);

//     Card& operator= (const Card& card) // supraincarcarea operatorului =
//     {
//         no_of_cards = no_of_cards + 1;
//         nrCard = card.nrCard;
//         NumeDetinator = card.NumeDetinator;
//         data_expirare = card.data_expirare;
//         cvv = card.cvv;
//         credit = card.credit;
//         return *this;
//     }

//     friend istream& operator>>(istream& in, Card& card){
//         cout<<"Numarul cardului: ";
//         in.get();
//         getline(in, card.nrCard);

//         cout<<"Numele detinatorului: ";
//         getline(in, card.NumeDetinator);

//         cout<<"Data expirare card (format dd-mm-yyyy): ";
//         getline(in, card.data_expirare);

//         cout<<"Cod Cvv: ";
//         in>>card.cvv;

//         cout<<"Credit card: ";
//         in>>card.credit;

//         return in;

//     }

//     friend ostream& operator<<(ostream& out, const Card& card)
//     {
//         out<<"Numarul cardului : "<<card.nrCard<<endl;
//         out<<"Numele detinatorului cardului : "<<card.NumeDetinator<<endl;
//         out<<"Data de expirare : "<<card.data_expirare<<endl;
//         out<<"CVV-ul cardului : "<<card.cvv<<endl;
//         out<<"Creditul cardului : "<<card.credit<<endl;

//         return out;
//     }

//     virtual void Citire(){}

//     virtual void Afisare(){}

//     // Metoda de withdraw   

//     virtual void Withdraw(double money){}

// };

// int Card::no_of_cards = 0;

// class CardStandard: public Card{
// protected:
//     int withdrawalLimit; // limita extragere de pe card
//     double commission; // comision depasire limita

// public:

//     CardStandard(); // constructor de initializare
//     CardStandard(string, string, string, int, double, int, double); // constructor parametrizat
//     CardStandard(const CardStandard&); // constructor de copiere
//     ~CardStandard(); // destructor

//     // Getters & Setters

//     int GetWithdrawalLimit() const;
//     double GetCommission() const;

//     void SetWithdrawalLimit(int);
//     void SetCommission(double);

//     CardStandard& operator= (const CardStandard& card){
//         nrCard = card.nrCard;
//         NumeDetinator = card.NumeDetinator;
//         data_expirare = card.data_expirare;
//         cvv = card.cvv;
//         credit = card.cvv;
//         withdrawalLimit = card.withdrawalLimit;
//         commission = card.commission;
//         return *this;
//     }

//     friend istream& operator>>(istream& in, CardStandard& card)
//     {
//         in>>dynamic_cast<Card&>(card);
//         cout<<"Limita extragere: ";
//         in>>card.withdrawalLimit;

//         cout<<"Comision pentru depasirea limitei (valoare procentuala): ";
//         in>>card.commission;

//         return in;
//     }

//     friend ostream& operator<< (ostream& out, CardStandard& card)
//     {
//         out<<dynamic_cast<Card&>(card);
//         out<<"Limita extragere: "<<card.withdrawalLimit<<endl;
//         out<<"Comision depasire limita extragere (valoare procentuala): "<<card.commission<<endl;

//         return out;
//     }

//     void Citire();
//     void Afisare(); 

//     // Metoda

//     void Withdraw(double);
// };

// class CardPremium: public CardStandard{

// protected:
//     double cashback;

// public:
//     CardPremium(); // constructor de initializare
//     CardPremium(string, string, string, int, double, int, double, double); // constructor parametrizat
//     CardPremium(const CardPremium&); // constructor de copiere

//     ~CardPremium(); // destructor

//     //Getters & Setters

//     double GetCashback() const;
//     void SetCashback(double);

//     CardPremium& operator= (const CardPremium& card) // supraincarcarea lui =
//     {
//         nrCard = card.nrCard;
//         NumeDetinator = card.NumeDetinator;
//         data_expirare = card.data_expirare;
//         cvv = card.cvv;
//         credit = card.cvv;
//         withdrawalLimit = card.withdrawalLimit;
//         commission = card.commission;
//         cashback = card.cashback;
//         return *this;
//     }

//     friend istream& operator>>(istream& in, CardPremium& card)
//     {

//         in>>dynamic_cast<CardStandard&>(card);

//         cout<<"Cashback: ";
//         in>>card.cashback;
//         cout<<endl;

//         return in;
//     }
//     friend ostream& operator<<(ostream& out, CardPremium& card){
//         out<<dynamic_cast<CardStandard&>(card);
//         out<<"Cashback: "<<card.cashback<<endl;
//         return out;
//     }

//     void Citire();
//     void Afisare();

//     // Metoda

//     void Withdraw(double);
// };

// #pragma region Card

// Card::Card(){
//     nrCard = "";
//     NumeDetinator = "";
//     data_expirare = "";
//     cvv = 0;
//     credit = 0;
//     no_of_cards = no_of_cards + 1;
// }

// Card::Card(string nrCard, string NumeDetinator, string data_expirare, int cvv, double credit)
// {
//     this->nrCard = nrCard;
//     this->NumeDetinator = NumeDetinator;
//     this->data_expirare = data_expirare;
//     this->cvv = cvv;
//     this->credit = credit;
//     no_of_cards = no_of_cards + 1;
// }

// Card::Card(const Card& card)
// {
//     nrCard = card.nrCard;
//     NumeDetinator = card.NumeDetinator;
//     data_expirare = card.data_expirare;
//     cvv = card.cvv;
//     credit = card.credit;
// }

// Card::~Card()
// {
//     nrCard = "";
//     NumeDetinator = "";
//     data_expirare = "";
//     cvv = 0;
//     credit = 0;
//     no_of_cards = no_of_cards - 1;
// }

// string Card::GetNrCard() const
// {
//     return nrCard;
// }

// string Card::GetNumeDetinator() const{
//     return NumeDetinator;
// }

// string Card::GetDataExpirare() const
// {
//     return data_expirare;
// }

// int Card::GetCvv() const{
//     return cvv;
// }

// double Card::GetCredit() const{
//     return credit;
// }

// int Card::GetNoOfCard()
// {
//     return no_of_cards;
// }

// void Card::SetNrCard(string nrCard)
// {
//     this->nrCard = nrCard;
// }

// void Card::SetNumeDetinator(string NumeDetinator)
// {
//     this->NumeDetinator = NumeDetinator;
// }

// void Card::SetDataExpirare(string data_expirare)
// {
//     this->data_expirare = data_expirare;
// }

// void Card::SetCvv(int cvv)
// {
//     this->cvv = cvv;
// }

// void Card::SetCredit(double credit)
// {
//     this->credit = credit;
// }

// void Card::SetNoOfCards(int nr)
// {
//     no_of_cards = nr;
// }

// #pragma endregion

// #pragma region CardStandard

// CardStandard::CardStandard():Card(){
//     withdrawalLimit = 0;
//     commission = 0;
// }

// CardStandard::CardStandard(string nrCard, string NumeDetinator, string data_expirarii, int cvv, double credit,int withdrawalLimit, double commission):Card(nrCard, NumeDetinator, data_expirarii, cvv, credit)
// {
//     this->withdrawalLimit = withdrawalLimit;
//     this->commission = commission;
// }

// CardStandard::CardStandard(const CardStandard& card)
// {
//     nrCard = card.nrCard;
//     NumeDetinator = card.NumeDetinator;
//     data_expirare = card.data_expirare;
//     cvv = card.cvv;
//     credit = card.credit;
//     withdrawalLimit = card.withdrawalLimit;
//     commission = card.commission;
// }

// CardStandard::~CardStandard(){
//     nrCard = "";
//     NumeDetinator = "";
//     data_expirare = "";
//     cvv = 0;
//     credit = 0;
//     withdrawalLimit = 0;
//     commission = 0;
// }

// int CardStandard::GetWithdrawalLimit() const{
//     return withdrawalLimit;
// }

// double CardStandard::GetCommission() const{
//     return commission;
// }

// void CardStandard::SetWithdrawalLimit(int withdrawalLimit){
//     this->withdrawalLimit = withdrawalLimit;
// }

// void CardStandard::SetCommission(double commission){
//     this->commission = commission;
// }

// void CardStandard::Citire()
// {
//     cout<<"Numarul cardului: ";
//     cin.get();
//     getline(cin, nrCard);
        
//     cout<<"Numele detinatorului: ";
//     getline(cin, NumeDetinator);

//     cout<<"Data expirare card: ";
//     getline(cin, data_expirare);

//     cout<<"Cod Cvv: ";
//     cin>>cvv;

//     cout<<"Credit card: ";
//     cin>>credit;
//     cout<<"Limita extragere: ";
//     cin>>withdrawalLimit;
//     cout<<"Comision extragere: ";
//     cin>>commission;

// }

// void CardStandard::Afisare()
// {
//     cout<<"Numarul cardului: "<<nrCard<<endl;
//     cout<<"Numele detinatorului: "<<NumeDetinator<<endl;
//     cout<<"Data expirare: "<<data_expirare<<endl;
//     cout<<"Cod Cvv: "<<cvv<<endl;
//     cout<<"Credit card: "<<credit<<endl;
//     cout<<"Limita extragere: "<<withdrawalLimit<<endl;
//     cout<<"Comision extragere: "<<commission<<endl;
// }

// void CardStandard::Withdraw(double money)
// {
//     double creditWithCommission = credit - money - commission/100 * money;
//     if(credit < money)
//     {
//         cout<<"Fonduri insuficiente pe cardul "<<nrCard<<endl;
//         return;
//     }
//     else if(money <= withdrawalLimit){
//         credit = credit - money;
//     }
//     else if(withdrawalLimit < money && credit > money && creditWithCommission>=0)
//     {
//         credit = creditWithCommission;
//     }
//     cout<<"Creditul actual de pe cardul "<<nrCard<<" : "<<credit<<endl;
// }

// #pragma endregion

// #pragma region CardPremium

// CardPremium::CardPremium():CardStandard(){
//     cashback = 0;
// }

// CardPremium::CardPremium(string nrCard, string NumeDetinator, string data_expirarii, int cvv, double credit, int withdrawalLimit, double commission, double cashback):CardStandard(nrCard, NumeDetinator, data_expirarii, cvv, credit, withdrawalLimit, commission){
//     this->cashback = cashback;
// }

// CardPremium::CardPremium(const CardPremium& card){
//     nrCard = card.nrCard;
//     NumeDetinator = card.NumeDetinator;
//     data_expirare = card.data_expirare;
//     cvv = card.cvv;
//     credit = card.credit;
//     withdrawalLimit = card.withdrawalLimit;
//     commission = card.commission;
//     cashback = card.cashback;
// }

// CardPremium::~CardPremium(){
//     nrCard = "";
//     NumeDetinator = "";
//     data_expirare = "";
//     cvv = 0;
//     credit = 0;
//     withdrawalLimit = 0;
//     commission = 0;
//     cashback = 0;
// }

// double CardPremium::GetCashback() const{
//     return cashback;
// }

// void CardPremium::SetCashback(double cashback){
//     this->cashback = cashback;
// }

// void CardPremium::Citire(){
//     cout<<"Numarul cardului: ";
//     cin.get();
//     getline(cin, nrCard);
        
//     cout<<"Numele detinatorului: ";
//     getline(cin, NumeDetinator);

//     cout<<"Data expirare card: ";
//     getline(cin, data_expirare);

//     cout<<"Cod Cvv: ";
//     cin>>cvv;

//     cout<<"Credit card: ";
//     cin>>credit;
//     cout<<"Limita extragere: ";
//     cin>>withdrawalLimit;
//     cout<<"Comision extragere: ";
//     cin>>commission;

//     cout<<"Cashback: ";
//     cin>>cashback;
// }

// void CardPremium::Afisare(){
//     cout<<"Numarul cardului: "<<nrCard<<endl;
//     cout<<"Numele detinatorului: "<<NumeDetinator<<endl;
//     cout<<"Data expirare: "<<data_expirare<<endl;
//     cout<<"Cod Cvv: "<<cvv<<endl;
//     cout<<"Credit card: "<<credit<<endl;
//     cout<<"Limita extragere: "<<withdrawalLimit<<endl;
//     cout<<"Comision extragere: "<<commission<<endl;
//     cout<<"Cashback: "<<cashback<<endl;
// }

// void CardPremium::Withdraw(double money)
// {
//     double new_cashback;
//     if(credit < money)
//     {
//         cout<<"Credit insuficient"<<endl;
//         return;
//     }
//     else{
//         credit = credit - money;
//         new_cashback = (cashback/100)*money;
//         SetCredit(credit + new_cashback);
//     }
//     cout<<"Extragere reusita! Cashback-ul obtinut in urma tranzatiei este "<<new_cashback<<endl;
//     cout<<"Creditul curent: "<<credit<<endl;
// }

// #pragma endregion

template <class T> void AfisareCarduri(vector<T*> a){} 

template <> void AfisareCarduri(vector<Card*> a)
{
    bool ok = false;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]->GetCredit() >= 1000)
        {
            ok = true;
            a[i]->Afisare();
        }
    }
    if(ok == false)
    {
        cout<<"Nu sunt carduri cu credit mai mare de 1000 de lei"<<endl;
    }
}

void Menu()
{
    vector<Card*> carduri; // upcasting
    vector<int> pozitii_standard;
    vector<int> pozitii_premium;

    int command = -1;
    while(command != 0)
    {
        cout<<endl;
        cout<<"Introduceti numarul comenzii: "<<endl;
        cout<<"0. Iesire"<<endl;
        cout<<"1. Citire si memorare a N carduri"<<endl;
        cout<<"2. Afisarea detaliilor unui card"<<endl;
        cout<<"3. Extragerea creditului de pe un card"<<endl;
        cout<<"4. Introducere carduri"<<endl;
        cout<<"5. Afisare carduri care au credit mai mare de 1000 de lei"<<endl;
        cin>>command;
        if(command == 0)
            break;
        else if(command == 1)
        {
            int tip = 0;
            int dimensiune;
            cout<<"Cate carduri vreti sa introduceti?: ";
            cin>>dimensiune;
            cout<<endl;
            for(int i=0;i<dimensiune;i++)
            {
                cout<<"Ce tip de carduri doriti sa introduceti? "<<endl;
                cout<<"1. Card Standard"<<endl;
                cout<<"2. Card Premium"<<endl;
                cin>>tip;
                if(tip == 1 || tip == 2)
                    cout<<"Cardul curent este "<<i+1<<endl;
                else{
                    cout<<"Tip de card invalid. Va rugam sa reincercati"<<endl;
                    i = i -1;
                }
                if(tip == 1)
                {
                    CardStandard *card_standard = new CardStandard();
                    card_standard->Citire();
                    carduri.push_back(card_standard);
                }
                else if(tip == 2)
                {
                    CardPremium *card_premium = new CardPremium();
                    card_premium->Citire();
                    carduri.push_back(card_premium);
                }
            }
            cout<<"Afisez elementele din vectorul de tip card"<<endl;
            cout<<endl;
            for(int i=0;i<carduri.size();i++)
            {
                if(CardPremium *p = dynamic_cast<CardPremium*>(carduri[i]))
                {
                    cout<<"CARD PREMIUM"<<endl;
                    p->Afisare();
                    cout<<endl;
                }   
                else if(CardStandard *p = dynamic_cast<CardStandard*>(carduri[i]))
                {
                    cout<<"CARD STANDARD"<<endl;
                    p->Afisare();
                    cout<<endl;
                }
            }

            for(int i=0;i<carduri.size();i++)
            {
                if(CardPremium *p = dynamic_cast<CardPremium*>(carduri[i]))
                    pozitii_premium.push_back(i);
                else if(CardStandard *p = dynamic_cast<CardStandard*>(carduri[i]))
                {
                    pozitii_standard.push_back(i);
                }
            }
        }
        else if(command == 2)
        {
            int cardIndex;
            char tipCard;
            cout<<"Alegeti cardul pentru care vreti sa vedeti detaliile"<<endl;

            cout<<"a. Carduri standard:"<<endl;
            for(int i=0;i<pozitii_standard.size();i++)
            {
                cout<<i+1<<": "<<carduri[pozitii_standard[i]]->GetNumeDetinator()<<endl;
            }
            cout<<"b. Carduri premium:"<<endl;
            for(int i=0;i<pozitii_premium.size();i++)
            {
                cout<<i+1<<": "<<carduri[pozitii_premium[i]]->GetNumeDetinator()<<endl;
            }
            cout<<"Tipul cardului (litera): ";
            cin>>tipCard;
            while(tipCard <'a' || tipCard > 'b')
            {
                cout<<"Tipul cardului (litera): ";
                cin>>tipCard;
                if(tipCard < 'a' || tipCard > 'b')
                {
                    cout<<"Comanda invalida"<<endl;
                }
            }

            cout<<"Indexul cardului pe care doriti sa-l afisati: ";
            cin>>cardIndex;

            while(cardIndex < 1)
            {
                cout<<"Introduceti indexul cardului pe care doriti sa-l afisati: ";
                cin>>cardIndex;
                if(cardIndex < 1)
                {
                    cout<<"Comanda invalida"<<endl;
                }
            }

            if(tipCard == 'a')
            {
                if(cardIndex > pozitii_standard.size())
                {
                    cout<<"Index invalid"<<endl;
                }
                else{
                    cout<<"Detaliile cardului sunt: "<<endl;
                    cout<<*carduri[pozitii_standard[cardIndex-1]];
                }
            }
            else{
                if(cardIndex > pozitii_premium.size())
                {
                    cout<<"Index invalid"<<endl;
                }
                else{
                    cout<<"Detaliile cardului sunt: "<<endl;
                    cout<<*carduri[pozitii_premium[cardIndex-1]];
                }
            }
        }
        else if(command == 3)
        {
            int cardIndex;
            char tipCard;
            double moneyExtract = 0;
            cout<<"Alegeti cardul din care doriti sa efectuati tranzactia: "<<endl;
            if(pozitii_standard.size() != 0)
            {
                cout<<"a. Carduri Standard"<<endl;
                for(int i=0;i<pozitii_standard.size();i++)
                {
                    cout<<i+1<<": ";
                    cout<<carduri[pozitii_standard[i]]->GetNumeDetinator()<<endl;
                }
            }
            if(pozitii_premium.size() != 0)
            {
                cout<<"b. Carduri Premium"<<endl;
                for(int i=0;i<pozitii_premium.size();i++)
                {
                    cout<<i+1<<". ";
                    cout<<carduri[pozitii_premium[i]]->GetNumeDetinator()<<endl;
                }
            }

            cout<<"Tipul cardului (litera): ";
            cin>>tipCard;
            while(tipCard <'a' || tipCard >'b')
            {
                cout<<"Tipul cardului (litera): ";
                cin>>tipCard;
                if(tipCard < 'a' || tipCard > 'b')
                {
                    cout<<"Comanda invalida"<<endl;
                }
            }

            cout<<"Indexul cardului de pe care vreti sa scoateti bani: ";
            cin>>cardIndex;
            while(cardIndex < 1)
            {
                cout<<"Indexul cardului de pe care vreti sa scoateti bani:";
                cin>>cardIndex;
                if(cardIndex < 1)
                {
                    cout<<"Comanda invalida"<<endl;
                }
            }

            cout<<"Introduceti suma pe care doriti sa o extrageti: ";
            cin>>moneyExtract;
            if(toupper(tipCard) == 'A')
            {
                if(cardIndex > pozitii_standard.size())
                {
                    cout<<"Index invalid"<<endl;
                }
                else{
                    carduri[pozitii_standard[cardIndex-1]]->Withdraw(moneyExtract);
                }
            }
            else{
                if(cardIndex > pozitii_premium.size())
                {
                    cout<<"Index invalid"<<endl;
                }
                else{
                    carduri[pozitii_premium[cardIndex-1]]->Withdraw(moneyExtract);
                }
            }
        }
        else if(command == 4)
        {
            int tip = 0;
            int dimensiune;
            cout<<"Cate carduri vreti sa introduceti?: ";
            cin>>dimensiune;
            cout<<endl;
            for(int i=0;i<dimensiune;i++)
            {
                cout<<"Ce tip de carduri doriti sa introduceti? "<<endl;
                cout<<"1. Card Standard"<<endl;
                cout<<"2. Card Premium"<<endl;
                cin>>tip;
                if(tip == 1 || tip == 2)
                    cout<<"Cardul curent este "<<i+1<<endl;
                else{
                    cout<<"Tip de card invalid. Va rugam sa reincercati"<<endl;
                    i = i -1;
                }
                if(tip == 1)
                {
                    CardStandard *card_standard = new CardStandard();
                    cin>>*card_standard;
                    carduri.push_back(card_standard);
                }
                else if(tip == 2)
                {
                    CardPremium *card_premium = new CardPremium();
                    cin>>*card_premium;
                    carduri.push_back(card_premium);
                }
            }

            for(int i=carduri.size()-dimensiune;i<carduri.size();i++)
            {
                if(CardPremium *p = dynamic_cast<CardPremium*>(carduri[i]))
                    pozitii_premium.push_back(i);
                else if(CardStandard *p = dynamic_cast<CardStandard*>(carduri[i]))
                {
                    pozitii_standard.push_back(i);
                }
            }
        }
        else if(command == 5)
        {
            AfisareCarduri(carduri);
        }
        else{
            cout<<"Comanda invalida"<<endl;
        }
    }
    cout<<"Iesire program";
}

int main()
{
    char command;
    cout<<"Introduceti y pentru a porni sau n pentru a iesi: ";
    cin>>command;
    while(toupper(command) != 'Y')
    {
        if(toupper(command) == 'N')
            return 0;
        else{
            cout<<"Comanda invalida"<<endl;
        }
        cout<<"Introduceti y pentru a porni sau n pentru a iesi: ";
        cin>>command;
    }
    Menu();

    return 0;
}
