#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "feuille.hpp"
#include "designp.hpp"
using namespace std;

double Feuille::calculer(){
	try{
       double result=boost::lexical_cast<double>(this->valeur);
       return result;
	}
	catch(boost::bad_lexical_cast){
		Evaluator& e=e.instance();
		return e.getValeur(this->valeur);
	}

}

Feuille* Feuille::clone(){
	return new Feuille(valeur);
}

Feuille::Feuille(const string &val){
  valeur=val;
}


