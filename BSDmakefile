CPPFLAGS = -Wall -std=c++11 -D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH -D_GLIBCXX_USE_C99_MATH_TR1

all: sistema

src/Paciente.o: src/Paciente.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

src/main.o: src/main.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

sistema: src/Paciente.o src/main.o
	g++ -o $@ src/*.o

clean:
	rm -rf src/*.o ./sistema