#ifndef composant
#define composant
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Composant{
public:
  virtual Composant* expression(vector<string> &l,int &i){}
  virtual Composant* terme(vector<string> &l,int &i){}
  virtual Composant* facteur(vector<string> &l,int &i){}
  virtual double calculer(){}
protected:
  Composant();
};

#endif
