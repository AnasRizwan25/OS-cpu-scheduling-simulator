CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: scheduler

scheduler: main.o scheduler.o
	$(CXX) $(CXXFLAGS) -o scheduler main.o scheduler.o

main.o: main.cpp scheduler.h
	$(CXX) $(CXXFLAGS) -c main.cpp

scheduler.o: scheduler.cpp scheduler.h
	$(CXX) $(CXXFLAGS) -c scheduler.cpp

clean:
	rm -f *.o scheduler
