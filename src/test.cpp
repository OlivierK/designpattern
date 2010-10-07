#define BOOST_TEST_MAIN
#define BOOST_AUTO_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE designp_test
#include <boost/test/unit_test.hpp>
#include <boost/test/auto_unit_test.hpp>
#include "designp.hpp"

BOOST_AUTO_TEST_CASE(designp_test1){
  Evaluator& e =Evaluator::instance();
  BOOST_CHECK_EQUAL(e.eval("0"),0.0);
  Evaluator& e2 =Evaluator::instance();
  Evaluator& e3 =Evaluator::instance();
  BOOST_CHECK_EQUAL(&e2,&e3);
  BOOST_CHECK_EQUAL(&e,&e2);
}
