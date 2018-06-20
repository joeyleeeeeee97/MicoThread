CXXFLAGS=-g -Wall -rdynamic -march=native
CXXFLAGS+=-O0
HEADERS=$(wildcard *.h)
TESTS = test1 \


all : $(TESTS)

$(TESTS) : $(HEADERS)

$(TESTS):
	g++ $(CXXFLAGS) -o  $@ $(filter %.cc,$^) $(LDFLAGS) -lpthread -std=c++11 -w 

test1 :  test/test1.cc  Scheduler.cc 
