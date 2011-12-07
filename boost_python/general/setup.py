#setup.py
from distutils.core import setup
from distutils.extension import Extension
import os.path
import sys
if sys.platform == "win32" :
    include_dirs = ["C:/Boost/include/boost-1_32","."]
    libraries=["boost_python-mgw"]
    library_dirs=['C:/Boost/lib']
else :
    include_dirs = ["/usr/include/boost","."]
    libraries=["boost_python"]
    library_dirs=['/usr/lib']

files = ["myboost.cpp"]

setup(name="myboost",    
      ext_modules=[
                    Extension("myboost",files,
                    library_dirs=library_dirs,
                    libraries=libraries,
                    include_dirs=include_dirs,
                    depends=[]),
                    ]
     )
