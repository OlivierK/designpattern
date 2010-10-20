#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "designp.hpp"
#include "feuille.hpp"
#include "noeud.hpp"
#include "variable.hpp"
using namespace std;

double Evaluator::eval(const string& expr){
	if(expr.compare("")==0){
		return 0.0;
	}
	derniereOp=expr;
	vector<string> vec;
	boost::split(vec,expr,boost::is_any_of(" "));
	Noeud arbre;
	Composant* pCmp;
	for(int j=0;j<vec.size();j++){
		if (vec[j].compare("")==0)
		vec.erase(vec.begin()+j);
	}
	int i=0;
	pCmp=arbre.expression(vec,i);
	double res= pCmp->calculer();
	delete pCmp;
	return res;
}
double Evaluator::eval(){
	return eval(derniereOp);
}

int Evaluator::varIndex(const string& var){

	for(int j=0;j<variables.size();j++){
			if (variables[j].nom.compare(var)==0)
				return j;
	}
	return -1;
}

void Evaluator::set(const string& var,double val){
	int place=varIndex(var);
	if(place>-1)
		variables[place].setValeur(val);
}

void Evaluator::store(const string& var,double val){
	int place=varIndex(var);
	if(place==-1)
		variables.push_back(Variable(var,val));
}

double Evaluator::getValeur(const string& var) throw(exception){
	int place=varIndex(var);
	if(place>-1)
		return variables[place].valeur;
	else
		throw "variable inconnue";
}

Evaluator& Evaluator::instance(){
  static Evaluator evaluator;
  return evaluator;
}
Evaluator::Evaluator(){
	derniereOp="";
}
Evaluator::Evaluator(const Evaluator&){}




