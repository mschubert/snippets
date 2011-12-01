#include <Python.h>
#include <boost/python.hpp>
using namespace boost::python;

struct Hello
{
    Hello(std::string msg): msg(msg) {}
    std::string get() const { return msg; }
    void set(std::string msg) { this->msg = msg; }
    private: std::string msg;
};

BOOST_PYTHON_MODULE(properties)
{
    class_<Hello>("Hello", init<std::string>())
        .add_property("ro_msg", &Hello::get) // msg read only
        .add_property("msg", &Hello::get, &Hello::set) // msg can be changed
    ;
}
