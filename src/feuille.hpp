#ifndef feuille
#define feuille
#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "composant.hpp"
using namespace std;


class Feuille : public Composant{
public:
  std::string valeur;
public:
  Feuille(const std::string &valeur);
  Feuille* clone();
  double calculer();
  ~Feuille();
};

#endif
