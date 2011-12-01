#!/usr/bin/env python
import member

x = member.Hello("this is constant")
x.value = 1.511
print x.msg, x.value

try:
    x.msg = "test"
except AttributeError:
    print "Name change raises AttributeError"
