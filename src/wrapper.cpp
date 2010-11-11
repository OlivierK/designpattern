#include <boost/python.hpp>
#include "designp.hpp"
using namespace boost::python;
double (Evaluator::*evalDefault)()=&Evaluator::eval;
double (Evaluator::*evalPar)(const std::string &)=&Evaluator::eval;
BOOST_PYTHON_MODULE(kernel) {
  class_<Evaluator>("Evaluator", init<>())
    .def("pileDup" , &Evaluator::pileDup)
    .def("store", &Evaluator::store)
    .def("compose", &Evaluator::compose)
    .def("eval", evalDefault)
    .def("eval", evalPar)
     ;
}
