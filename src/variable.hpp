/*
 * variable.hpp
 *
 *  Created on: 20 oct. 2010
 *      Author: mathieu
 */
#ifndef VARIABLE_HPP_
#define VARIABLE_HPP_
#include <string>
using namespace std;

class Variable{
public:
	string nom;
	double valeur;
public:
  Variable(string aNom, double aVal);
  void setValeur(double aVal);
};

#endif /* VARIABLE_HPP_ */
