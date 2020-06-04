CC=g++
AR=ar
LIBSFML=-lsfml-window -lsfml-system -lsfml-graphics
CCFLAGS=-std=c++11

lib : objects/lib2dgame.a
libshared : objects/lib2dgame.so

test : lib objects/test.o
	$(CC) objects/test.o objects/lib2dgame.a -o test $(LIBSFML) 

objects/lib2dgame.a : objects/camera.o objects/lib2dgame.o | objects 
	$(AR) rvs $@ $^

objects/lib2dgame.so : objects/camera_pic.o objects/lib2dgame_pic.o | objects
	$(CC) $^ -shared -o $@

objects/camera_pic.o : camera.cpp | objects types.h camera.h
	$(CC) $^ -c -o $@ $(CCFLAGS) -fPIC
objects/lib2dgame_pic.o : lib2dgame.cpp | camera.h spriteloader.h
	$(CC) $^ -c -o $@ $(CCFLAGS) -fPIC

objects/camera.o : camera.cpp | objects types.h camera.h
	$(CC) $^ -c -o $@ $(CCFLAGS)
objects/test.o : test.cpp | objects camera.h types.h
	$(CC) $^ -c -o $@ $(CCFLAGS)
objects/lib2dgame.o : lib2dgame.cpp | camera.h spriteloader.h
	$(CC) $^ -c -o $@ $(CCFLAGS)

objects:
	mkdir $@
clean:
	rm -f objects/*

json/json/objects/json.a : 
	make -C json lib
