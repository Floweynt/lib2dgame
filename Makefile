CC=g++
AR=ar
LIBSFML=-lsfml-window -lsfml-system -lsfml-graphics
CCFLAGS=-std=c++11

lib : objects/lib2dgame.a
	@echo "compiling libary"

test : lib objects/test.o
	$(CC) objects/test.o objects/lib2dgame.a -o test $(LIBSFML) 

objects/lib2dgame.a : objects/camera.o | objects 
	$(AR) rvs $@ $^

objects/camera.o : camera.cpp | objects types.h camera.h
	$(CC) $^ -c -o $@ $(CCFLAGS)
objects/test.o : test.cpp | objects camera.h types.h
	$(CC) $^ -c -o $@ $(CCFLAGS)
objects:
	mkdir $@
clean:
	rm -f objects/*

json/json/objects/json.a : 
	make -C json lib
