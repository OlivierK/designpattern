#include <iostream>
#include <vector>

using namespace std;

class Evaluator{
public:
  double eval(const string& expr);
  static Evaluator& instance();
private:
  Evaluator();
  Evaluator(const Evaluator&);

};
