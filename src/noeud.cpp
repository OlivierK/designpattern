#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "noeud.hpp"
#include "feuille.hpp"
using namespace std;


Noeud::Noeud(const string &op, Composant* g, Composant* d){
  operation=op;
  gauche=g;
  droite=d;
}

Noeud::Noeud(){
    operation="";
    gauche=NULL;
    droite=NULL;
}


Composant* Noeud::expression(vector<string> &l,int &i){
 Composant* gauche = terme(l,i);
 if(i<l.size() && (l[i]=="+" or l[i]=="-")){
    string str=l[i];
    i++;
    Composant* droite=expression(l,i);
    return new Noeud(str,gauche,droite);
  }
  else{
	return gauche;
  }
}

Composant* Noeud::terme(vector<string> &l,int &i){
	Composant* gauche = facteur(l,i);
  if(i<l.size() && (l[i]=="*" or l[i]=="/")){
	  string str=l[i];
    i++;
    Composant* droite=terme(l,i);
    return new Noeud(str,gauche,droite);
  }
  else{
	  return gauche;
  }
}

Composant* Noeud::facteur(vector<string> &l,int &i){
	i++;
	return new Feuille(l[i-1]);
}


double Noeud::calculer(){
  if(operation.compare( "+")==0)
    return gauche->calculer() + droite->calculer();
  else if(operation.compare( "-")==0)
    return gauche->calculer() - droite->calculer();
  else if(operation.compare( "*")==0)
    return gauche->calculer() * droite->calculer();
  else if(operation.compare( "/")==0)
    return gauche->calculer() / droite->calculer();
}

