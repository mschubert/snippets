#include <boost/python/detail/wrap_python.hpp>
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
//#include <Python.h>

#include "boost_test.h"


namespace bp = boost::python;

BOOST_PYTHON_MODULE(myboost){
    { //::std::vector< Base* >
        typedef bp::class_< std::vector< Base* > > 
vector_less__Base_ptr___greater__exposer_t;
        vector_less__Base_ptr___greater__exposer_t 
vector_less__Base_ptr___greater__exposer = 
vector_less__Base_ptr___greater__exposer_t( 
"vector_less__Base_ptr___greater_" );
        bp::scope vector_less__Base_ptr___greater__scope( 
vector_less__Base_ptr___greater__exposer );
        vector_less__Base_ptr___greater__exposer.def( 
bp::vector_indexing_suite< ::std::vector< Base* > >() );
    }

    bp::class_< Base >( "Base", bp::init< >() )    
        .def( 
            "get"
            , (::std::string ( ::Base::* )(  ) )( &::Base::get ) )    
        .def( 
            "set"
            , (void ( ::Base::* )( ::std::string ) )( &::Base::set )
            , ( bp::arg("x") ) );

    { //::Collection
        typedef bp::class_< Collection > Collection_exposer_t;
        Collection_exposer_t Collection_exposer = Collection_exposer_t( 
"Collection", bp::init< std::vector< Base* > >(( bp::arg("x") )) );
        bp::scope Collection_scope( Collection_exposer );
        bp::implicitly_convertible< std::vector< Base* >, Collection 
>();
        { //::Collection::get
        
            typedef ::std::vector< Base* > ( 
::Collection::*get_function_type )(  ) ;
            
            Collection_exposer.def( 
                "get"
                , get_function_type( &::Collection::get ) );
        
        }
        { //::Collection::set
        
            typedef void ( ::Collection::*set_function_type )( 
::std::vector< Base* > ) ;
            
            Collection_exposer.def( 
                "set"
                , set_function_type( &::Collection::set )
                , ( bp::arg("x") ) );
        
        }
    }

    bp::class_< Derived1, bp::bases< Base > >( "Derived1", bp::init< >() 
);

    bp::class_< Derived2, bp::bases< Base > >( "Derived2", bp::init< >() 
);
}

