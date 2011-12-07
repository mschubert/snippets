void massadd(boost::python::list& ns)
{
    for (int i = 0; i < len(ns); ++i)
    {
        add(boost::python::extract<double>(ns[i]));
    }
}

