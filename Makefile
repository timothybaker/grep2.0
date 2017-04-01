all: grep2


grep2: main.o options.o file.o lines.o grep2.o
	g++  -o bin/grep2 obj/main.o obj/options.o obj/file.o obj/lines.o obj/grep2.o

main.o: src/main.cpp
	g++ -c -o obj/main.o src/main.cpp

options.o: src/options.cpp
	g++ -c -o obj/options.o src/options.cpp

file.o: src/file.cpp
	g++ -c -o obj/file.o src/file.cpp

lines.o: src/lines.cpp
	g++ -c -o obj/lines.o src/lines.cpp

grep2.o: src/grep2.cpp
	g++ -c -o obj/grep2.o src/grep2.cpp

clean:
	rm obj/*.o bin/grep2

install:
	cp bin/grep2 /usr/local/bin/
