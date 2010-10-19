#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "designp.hpp"
#include "feuille.hpp"
#include "noeud.hpp"
using namespace std;

double Evaluator::eval(const string& expr){
   vector<string> vec;
  boost::split(vec,expr,boost::is_any_of(" "));
   Noeud arbre;
  Composant* pCmp;
  for(int j=0;j<vec.size();j++){
    if (vec[j]=="")
        vec.erase(vec.begin()+j);
  }
  int i=0;
  pCmp=arbre.expression(vec,i);
  return pCmp->calculer();
}
Evaluator& Evaluator::instance(){
  static Evaluator evaluator;
  return evaluator;
}
Evaluator::Evaluator(){}
Evaluator::Evaluator(const Evaluator&){}




