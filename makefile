CXX = g++
CXXFLAGS = -Wall -g -std=c++11
EXE = mini-shell
SOURCE_PATH = ./src/

build: $(SOURCE_PATH)command.o
	$(CXX) $(CXXFLAGS) main.cpp $^ -o mini-shell

$(SOURCE_PATH)command.o: $(SOURCE_PATH)command.cpp

.PHONy: clean

clean:
	rm *.o $(SOURCE_PATH)*.o mini-shell

