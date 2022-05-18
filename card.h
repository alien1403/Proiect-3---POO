#ifndef cardd
#define cardd
#include <bits/stdc++.h>

using namespace std;

class Card{

protected:
    string nrCard, NumeDetinator, data_expirare; // numar card, nume detinator, data expirare card
    int cvv; // cod de 3 cifre de pe spatele cardului
    double credit; // valoarea totala de bani care se afla in card

    static int no_of_cards;

public:
    Card(); // constructor de initializare
    Card(string, string, string, int, double); // constructor in care se initializeaza numarul cardului,
    //numele detinatorului, data expirarii, cvv-ul si suma totala din acel cont
    Card(const Card& ); // constructor de copiere

    virtual ~Card(); // destructor

    // Getters and Setters

    string GetNrCard() const; // returneaza numarul cardului
    string GetNumeDetinator() const; // returneaza numele detinatorului cardului
    string GetDataExpirare() const; // returneaza data expirarii cardului
    int GetCvv() const; // returneaza cvv-ul
    double GetCredit() const; // returneaza suma care se afla in acel cont
    static int GetNoOfCard(); // returneaza numarul de carduri


    void SetNrCard(string); // seteaza numarul cardului
    void SetNumeDetinator(string); // seteaza numele detinatorului cardului
    void SetDataExpirare(string); // seteaza data de expirare a cardului
    void SetCvv(int); // seteaza cvv-ul
    void SetCredit(double); // seteaza valoarea creditului de pe card
    void static SetNoOfCards(int);

    Card& operator= (const Card& card) // supraincarcarea operatorului =
    {
        no_of_cards = no_of_cards + 1;
        nrCard = card.nrCard;
        NumeDetinator = card.NumeDetinator;
        data_expirare = card.data_expirare;
        cvv = card.cvv;
        credit = card.credit;
        return *this;
    }

    friend istream& operator>>(istream& in, Card& card){
        cout<<"Numarul cardului: ";
        in.get();
        getline(in, card.nrCard);

        cout<<"Numele detinatorului: ";
        getline(in, card.NumeDetinator);

        cout<<"Data expirare card (format dd-mm-yyyy): ";
        getline(in, card.data_expirare);

        string cvv_invalid = "Cvv-ul introdus trebuie sa fie intre 100 si 999";
        try{
            cout<<"Cod Cvv: ";
            in>>card.cvv;

            if(!(card.cvv >= 100 && card.cvv <= 999))
                throw cvv_invalid;
        }
        catch(string x)
        {
            cout<<cvv_invalid<<endl;
        }

        cout<<"Credit card: ";
        in>>card.credit;

        return in;
    }

    friend ostream& operator<<(ostream& out, const Card& card)
    {
        out<<"Numarul cardului : "<<card.nrCard<<endl;
        out<<"Numele detinatorului cardului : "<<card.NumeDetinator<<endl;
        out<<"Data de expirare : "<<card.data_expirare<<endl;
        out<<"CVV-ul cardului : "<<card.cvv<<endl;
        out<<"Creditul cardului : "<<card.credit<<endl;

        return out;
    }

    virtual void Citire(){}

    virtual void Afisare(){}

    // Metoda de withdraw   

    virtual void Withdraw(double money){}

};

#endif