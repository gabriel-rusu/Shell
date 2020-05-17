CXX = g++
CXXFLAGS = -Wall -g -std=c++11
EXE = shell

build: main.o
	$(CXX) $(CXXFLAGS) main.o -o shell

main.o: main.cpp

.PHONy: clean

clean:
	rm *.o shell

