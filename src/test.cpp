#define BOOST_TEST_MAIN
#define BOOST_AUTO_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE designp_test
#include <boost/test/unit_test.hpp>
#include <boost/test/auto_unit_test.hpp>
#include "designp.hpp"


BOOST_AUTO_TEST_CASE(designp_test1){
  Evaluator& e =Evaluator::instance();
  BOOST_CHECK_EQUAL(e.eval(" 0 "),0.0);
  Evaluator& e2 =Evaluator::instance();
  Evaluator& e3 =Evaluator::instance();
  BOOST_CHECK_EQUAL(&e2,&e3);
  BOOST_CHECK_EQUAL(&e,&e2);


  //histoire2
  double r1 = e.eval ( "1 + 1" ); // r1 = 2
  double r2 = e.eval ( "2 * 3 + 1" ); // r2 = 7
  double r3 = e.eval ( "5 + 3 * 4.5" ); // r3 = 18.5
  BOOST_CHECK_EQUAL(r1,2.0);
  BOOST_CHECK_EQUAL(r2,7.0);
  BOOST_CHECK_EQUAL(r3,18.5);
  e.store("a",2.);
  double r4 = e.eval("a + 6. / a"); // r1 = 5.
  BOOST_CHECK_EQUAL(r4,5.0);
  e.set("a",6.);
  double r5 = e.eval(); // r2 = 7.
  BOOST_CHECK_EQUAL(r5,7);

}
