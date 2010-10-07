#include <iostream>
#include <vector>
#include "designp.hpp"


double Evaluator::eval(const string& expr){
  return 0.0;
}
Evaluator& Evaluator::instance(){
  static Evaluator evaluator;
  return evaluator;
}
Evaluator::Evaluator(){}
Evaluator::Evaluator(const Evaluator&){}


