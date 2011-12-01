#include <Python.h>
#include <boost/python.hpp>
using namespace boost::python;

struct Hello
{
    Hello(std::string msg): msg(msg), value() {}
    std::string const msg;
    float value;
};

BOOST_PYTHON_MODULE(member)
{
    class_<Hello>("Hello", init<std::string>())
        .def_readonly("msg", &Hello::msg) // msg read only
        .def_readwrite("value", &Hello::value) // value can be changed
    ;
}
