#include <iostream>
#include <vector>
#ifndef designp_hpp
#define designp_hpp
#include "variable.hpp"
#include "expression.hpp"
using namespace std;

class Evaluator{
public:
  string derniereOp;
  vector<Variable> variables;
  vector<Expression*> pile;
  double eval(const string& expr);
  double eval();
  static Evaluator& instance();
  void set(const string& var,double val);
  void store(const string& var,double val);
  double getValeur(const string& var) throw(exception);
  void pileDup();
  void compose(const string &op);
private:
  Evaluator();
  Evaluator(const Evaluator&);
  int varIndex(const string& var);
};
#endif






