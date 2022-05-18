#include "gestionare_carduri.h"
#include <bits/stdc++.h>

using namespace std;

template <typename T>
GestionareCarduri<T>::GestionareCarduri(){
  index = 0;
  operatii = new set<pair<int, vector<string>>>[0];
}

template <typename T>
GestionareCarduri<T>::GestionareCarduri(int index, set<pair<int, vector<string>>> *v)
{
  this->index = index;
  operatii = new set<pair<int, vector<string>>>[v->size()];
  for(int i=0;i<v->size();i++)
  {
    for(auto it = v[i].begin(); it != v[i].end(); it++)
    {
      pair<int, vector<string>> aux(it->first, it->second);
      operatii[i].insert(aux);
    }
  }
}

template <typename T>
GestionareCarduri<T>::GestionareCarduri(const GestionareCarduri& card_nou)
{
  index = card_nou.index;
  operatii = new set<pair<int, vector<string>>>[card_nou.operatii->size()];
  for(int i=0;i<card_nou.operatii->size();i++)
  {
    for(auto it = card_nou.operatii[i].begin(); it != card_nou.operatii[i].end(); it++)
    {
      pair<int, vector<string>> aux(it->first, it->second);
      operatii[i].insert(aux);
    }
  }
}

template <typename T>
GestionareCarduri<T>::~GestionareCarduri(){
  index = 0;
  delete []operatii;
  operatii = nullptr;
}

template <typename T>
istream& operator>>(istream& in, GestionareCarduri<T>& card_nou)
{
  in>>card_nou.index;
  vector<string> v;
  v.push_back("Citire");
  v.push_back("Afisare");
  v.push_back("Extragere");
  card_nou.operatii->insert(index, v);
  return in;
}

template <typename T>
ostream& operator<< (ostream& out, const GestionareCarduri<T>& card_nou)
{
  out<<card_nou.index<<endl;
  for(int i=0;i<card_nou.operatii->size();i++)
  {
    out<<card_nou[i].operatii<<endl;
  }
}