//TODO: constraint-like hierarchy, see if i can get them in python list
#include <vector>
#include <string>

class Base
{
public:
    Base() {}
    virtual ~Base() {}

    std::string get() { return s; }
    void set(std::string x) { s = x; }
private:
    std::string s;
};

class Derived1: public Base
{
public:
    Derived1() {}
private:
};

class Derived2: public Base
{
public:
    Derived2() {}
};

class Collection
{
public:
    Collection(std::vector<Base*> x): vec(x) {};

    std::vector<Base*> get() { return vec; } // how to get this as property?
    void set(std::vector<Base*> x) { vec = x; }
private:
    std::vector<Base*> vec;
};

/*class PrivateCopyConst
{
public:
    PrivateCopyConst();
    virtual ~PrivateCopyConst();
private:
    PrivateCopyConst(PrivateCopyConst const &);
};

class Test
{
public:
    Test(PrivateCopyConst *pcc) {}
};*/

