PATH_SRC = src/
PATH_BUILD_SRC = build/
PATH_LIB = src/Lab2Lib/

all: build pr

pr: $(PATH_BUILD_SRC)main.o $(PATH_BUILD_SRC)Lab3.o libfs.so
	g++ $(PATH_BUILD_SRC)main.o $(PATH_BUILD_SRC)Lab3.o -L. -lfs -o pr -ldl -pthread

libfs.so: $(PATH_BUILD_SRC)Lab2.o
	g++ -shared -o libfs.so $(PATH_BUILD_SRC)Lab2.o

$(PATH_BUILD_SRC)Lab2.o: $(PATH_LIB)Lab2.cpp
	g++ -Wall -fPIC -c $(PATH_LIB)Lab2.cpp -o $(PATH_BUILD_SRC)Lab2.o

$(PATH_BUILD_SRC)Lab3.o: $(PATH_SRC)Lab3.cpp
	g++ -Wall -c $(PATH_SRC)Lab3.cpp -o $(PATH_BUILD_SRC)Lab3.o

$(PATH_BUILD_SRC)main.o: $(PATH_SRC)main.cpp
	g++ -Wall -c $(PATH_SRC)main.cpp -o $(PATH_BUILD_SRC)main.o

build:
	mkdir build

clean:
	rm -rf build/*.o

.PHONY: clean
