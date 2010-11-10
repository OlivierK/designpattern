#ifndef expr
#define expr
#include "composant.hpp"

class Expression{
public:
  Composant* pRacine;
  int ref;
  Expression(Composant* pCmp);
  ~Expression();
};

#endif
