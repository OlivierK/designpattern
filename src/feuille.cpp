#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "feuille.hpp"
using namespace std;

double Feuille::calculer(){
      return boost::lexical_cast<double>(this->valeur);
}

Feuille::Feuille(const string &val){
  valeur=val;
}


