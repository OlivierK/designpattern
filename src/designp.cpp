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
#include "expression.hpp"
using namespace std;

double Evaluator::eval(const string& ex){
	if(ex.compare("")==0)
		return 0.0;
	vector<string> vec;
	boost::split(vec,ex,boost::is_any_of(" "));
	Noeud arbre;
	Composant* pCmp;
	for(int j=0;j<vec.size();j++){
		if (vec[j].compare("")==0)
			vec.erase(vec.begin()+j);
	}
	int i=0;
	pCmp=arbre.expression(vec,i);
	Expression* aExpr=new Expression(pCmp);
	pile.push_back(aExpr);
	return pCmp->calculer();
}
double Evaluator::eval(){
	return pile.back()->pRacine->calculer();
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
}
Evaluator::~Evaluator(){
  for(int i=0;i<pile.size();i++)
    delete pile.at(i);
}
Evaluator::Evaluator(const Evaluator&){}

void Evaluator::pileDup(){
  if(pile.size()>0){
    Expression *pExpr=pile.back();
    pExpr->ref++;
    pile.push_back(pExpr);
  }
}
void Evaluator::pilePop(){
  pile.pop_back();
}
void Evaluator::compose(const string &op){
	if(pile.size()>1){
		//cloner gauche
		Composant *G=pile.back()->pRacine->clone();
		//cloner droite
		Composant *D=pile.at(pile.size()-2)->pRacine->clone();
		Noeud *racineCompo=new Noeud(op,G,D);
		Expression* aExpr=new Expression(racineCompo);
		pile.push_back(aExpr);
	}
}

