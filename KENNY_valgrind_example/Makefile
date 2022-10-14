all: run

run: compile
	./build/main

compile: directory
	g++ -g -O0 main.cpp -o build/main

directory:
	mkdir -p build

