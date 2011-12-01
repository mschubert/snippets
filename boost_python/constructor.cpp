#include <Python.h>
#include <boost/python.hpp>
using namespace boost::python;

struct Hello
{
    Hello(std::string msg): msg(msg) {} // this is new compared to struct
    void set(std::string msg) { this->msg = msg; }
    std::string greet() { return msg; }
    std::string msg;
};

BOOST_PYTHON_MODULE(constructor)
{
    class_<Hello>("Hello", init<std::string>()) // each init<..> is a constructor
        .def("greet", &Hello::greet)
        .def("set", &Hello::set)
    ;
}
