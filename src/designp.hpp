#include <iostream>
#include <vector>
#ifndef designp_hpp
#define designp_hpp
#include "variable.hpp"
#include "expression.hpp"
using namespace std;

class Evaluator{
public:
  vector<Variable> variables;
  vector<Expression*> pile;
  double eval(const string& expr);
  double eval();
  static Evaluator& instance();
  void set(const string& var,double val);
  void store(const string& var,double val);
  double getValeur(const string& var) throw(exception);
  void pileDup();
  void pilePop();
  void compose(const string &op);
  ~Evaluator();
  Evaluator();
  Evaluator(const Evaluator&);
private:
  int varIndex(const string& var);
};
#endif






