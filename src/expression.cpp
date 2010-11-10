#include "expression.hpp" 

Expression::Expression(Composant* pCmp){
  pRacine=pCmp;
  ref=1;
}
  
Expression::~Expression(){
  ref--;
  if(ref==0)
    delete pRacine;
}
