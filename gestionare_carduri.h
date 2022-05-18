#ifndef gestionare_carduri
#define gestionare_carduri

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class GestionareCarduri{
  int index;
  set<pair<int, vector<string>>> *operatii;
public:
  GestionareCarduri();
  GestionareCarduri(int, set<pair<int, vector<string>>>*);
  GestionareCarduri(const GestionareCarduri&);
  ~GestionareCarduri();

  friend istream& operator>>(istream&, GestionareCarduri<T>&);
  friend ostream& operator<<(ostream&, const GestionareCarduri<T>&);

};

#endif