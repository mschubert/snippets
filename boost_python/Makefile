CC = g++
CFLAGS = -fPIC -I/usr/include/python2.7
LFLAGS = -shared -Wl,-soname,
LIBS = -lpython2.7 -lboost_python

ALL_SOURCE = $(wildcard *.cpp)
ALL_LIB = $(ALL_SOURCE:%.cpp=%.so)

all: $(ALL_LIB)

%.so: %.o
	$(CC) $(LFLAGS)$@ -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.so
