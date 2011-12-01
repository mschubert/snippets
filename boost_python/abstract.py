#!/usr/bin/env python
import abstract

try:
    planet = abstract.Hello("this is my 2nd greeting")
except RuntimeError:
    print "RuntimeError caught upon class instantiation"
