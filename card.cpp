#include <bits/stdc++.h>
#include "card.h"

Card::Card(){
    nrCard = "";
    NumeDetinator = "";
    data_expirare = "";
    cvv = 0;
    credit = 0;
    no_of_cards = no_of_cards + 1;
}

Card::Card(string nrCard, string NumeDetinator, string data_expirare, int cvv, double credit)
{
    this->nrCard = nrCard;
    this->NumeDetinator = NumeDetinator;
    this->data_expirare = data_expirare;
    this->cvv = cvv;
    this->credit = credit;
    no_of_cards = no_of_cards + 1;
}

Card::Card(const Card& card)
{
    nrCard = card.nrCard;
    NumeDetinator = card.NumeDetinator;
    data_expirare = card.data_expirare;
    cvv = card.cvv;
    credit = card.credit;
}

Card::~Card()
{
    nrCard = "";
    NumeDetinator = "";
    data_expirare = "";
    cvv = 0;
    credit = 0;
    no_of_cards = no_of_cards - 1;
}

string Card::GetNrCard() const
{
    return nrCard;
}

string Card::GetNumeDetinator() const{
    return NumeDetinator;
}

string Card::GetDataExpirare() const
{
    return data_expirare;
}

int Card::GetCvv() const{
    return cvv;
}

double Card::GetCredit() const{
    return credit;
}

int Card::GetNoOfCard()
{
    return no_of_cards;
}

void Card::SetNrCard(string nrCard)
{
    this->nrCard = nrCard;
}

void Card::SetNumeDetinator(string NumeDetinator)
{
    this->NumeDetinator = NumeDetinator;
}

void Card::SetDataExpirare(string data_expirare)
{
    this->data_expirare = data_expirare;
}

void Card::SetCvv(int cvv)
{
    this->cvv = cvv;
}

void Card::SetCredit(double credit)
{
    this->credit = credit;
}

void Card::SetNoOfCards(int nr)
{
    no_of_cards = nr;
}

int Card::no_of_cards = 0;