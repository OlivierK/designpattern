#ifndef noeud
#define noeud
#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "composant.hpp"
using namespace std;




class Noeud : public Composant{
public:
  string operation;
  Composant* gauche;
  Composant* droite;
public:
  Noeud(const std::string &op, Composant *g, Composant *d);
  Noeud();
  double calculer();
  Composant* expression(vector<string> &l,int &i) ;
  Composant* terme(vector<string> &l,int &i);
  Composant* facteur(vector<string> &l,int &i);
  Noeud* clone();
  ~Noeud();
};
#endif
