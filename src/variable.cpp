/*
 * variable.cpp
 *
 *  Created on: 20 oct. 2010
 *      Author: mathieu
 */
#include "variable.hpp"

Variable::Variable(string aNom, double aVal){
	nom=aNom;
	valeur=aVal;
}
void Variable::setValeur(double aVal){
	valeur=aVal;
}
