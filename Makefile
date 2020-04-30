CC=g++
AR=ar
LIBSFML=-lsfml-window -lsfml-system -lsfml-graphics

lib : objects/lib2dgame.a
	@echo "compiling libary"

test : lib objects/test.o
	$(CC) objects/lib2dgame.a test.o -o test $(LIBSFML)

objects/lib2dgame.a : objects/camera.o | objects 
	$(AR) rcs objects/lib2dgame.a $^

objects/camera.o : camera.cpp | objects types.h camera.h
	$(CC) $^ -c -o $@
objects/test.o : test.cpp | objects camera.h types.h
	$(CC) $^ -c -o $@ 
objects:
	mkdir $@

json/json/objects/json.a : 
	make -C json lib
