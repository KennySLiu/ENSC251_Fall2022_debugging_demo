all: run

solution: SOLUTION.cpp
	g++ -g -O0 SOLUTION.cpp -o build/solution -lgtest
	./build/solution

run: compile
	./build/main

compile: directory
	g++ -g -O0 main.cpp -o build/main -lgtest

directory:
	mkdir -p build

