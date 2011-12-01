#include <Python.h>
#include <boost/python.hpp>
using namespace boost::python;

class Base { virtual ~Base(); };
class Derived: Base {};


BOOST_PYTHON_MODULE(properties)
{
    class_<Hello>("Hello", init<std::string>())
        .add_property("ro_msg", &Hello::get) // msg read only
        .add_property("msg", &Hello::get, &Hello::set) // msg can be changed
    ;
}

// class_<Derived, bases<Base> >("Derived")
// -> for the derived, gets exposed base methods as well
