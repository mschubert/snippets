#!/usr/bin/env python
import properties

x = properties.Hello("msg?")

print x.msg, x.ro_msg
x.msg = "msg!"
print x.msg, x.ro_msg

try:
    x.ro_msg = "error"
except AttributeError:
    print "trying to change ro_msg produces a AttributeError"
