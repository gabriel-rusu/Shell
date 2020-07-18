CXX = g++
CXXFLAGS = -Wall -g -std=c++14
EXE = shell
SOURCE_PATH = ./src/

build:$(SOURCE_PATH)utils.o $(SOURCE_PATH)simple_command.o $(SOURCE_PATH)shell.o $(SOURCE_PATH)builtin.o
	$(CXX) $(CXXFLAGS) main.cpp $^ -o  $(EXE)

$(SOURCE_PATH)simple_command.o: $(SOURCE_PATH)utils.o $(SOURCE_PATH)simple_command.cpp

$(SOURCE_PATH)shell.o: $(SOURCE_PATH)shell.cpp

$(SOURCE_PATH)builtin.o: $(SOURCE_PATH)shell.o $(SOURCE_PATH)builtin.cpp

$(SOURCE_PATH)utils.o: $(SOURCE_PATH)utils.cpp

save: clean
	git add -A	&&\
	echo Enter commit message: &&\
	read line &&\
	git commit -m "$$line" &&\
	git push

.PHONy: clean
clean:
	rm -f *.o $(SOURCE_PATH)*.o $(EXE)

