SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
CPPFLAGS = -Wall -std=c++11

all: sistema

%.o: %.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

sistema: $(OBJ)
	g++ -o $@ $^

clean:
	rm -rf src/*.o ./sistema