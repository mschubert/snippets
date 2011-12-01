#include <Python.h>
#include <boost/python.hpp>
using namespace boost::python;

struct Hello
{
    void set(std::string msg) { this->msg = msg; }
    std::string greet() { return msg; }
    std::string msg;
};

BOOST_PYTHON_MODULE(struct)
{
    class_<Hello>("Hello")
        .def("greet", &Hello::greet)
        .def("set", &Hello::set)
    ;
}
