#include <boost/python.hpp>
#include "designp.hpp"
using namespace boost::python;
double (Evaluator::Evaluator::*evalDefault)()=&Evaluator::Evaluator::eval;
double (Evaluator::Evaluator::*evalPar)(const std::string &)=&Evaluator::Evaluator::eval;
BOOST_PYTHON_MODULE(kernel) {
  class_<Evaluator>("Evaluator", init<>())
    .def("pileDup" , &Evaluator::pileDup)
    .def("store", &Evaluator::store)
    .def("compose", &Evaluator::compose)
    .def("eval", &Evaluator::evalDefault)
    .def("eval", &Evaluator::evalPar)
     ;
}
