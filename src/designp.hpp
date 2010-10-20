#include <iostream>
#include <vector>
#ifndef designp_hpp
#define designp_hpp
#include "variable.hpp"
using namespace std;

class Evaluator{
public:
	string derniereOp;
	vector<Variable> variables;
  double eval(const string& expr);
  double eval();
  static Evaluator& instance();
  void set(const string& var,double val);
  void store(const string& var,double val);
  double getValeur(const string& var) throw(exception);
private:
  Evaluator();
  Evaluator(const Evaluator&);
  int varIndex(const string& var);
};
#endif






