all: run

solution: SOLUTION.cpp
	g++ -g -O0 SOLUTION.cpp -o build/solution
	./build/solution

run: compile
	./build/main

compile: directory
	g++ -g -O0 main.cpp -o build/main

directory:
	mkdir -p build

