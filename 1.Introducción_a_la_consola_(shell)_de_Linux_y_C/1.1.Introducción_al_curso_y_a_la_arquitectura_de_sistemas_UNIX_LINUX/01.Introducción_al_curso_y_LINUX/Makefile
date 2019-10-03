hello_world: hello_world.o
	gcc hello_world.o -o hello_world

hello_world.o: hello_world.c
	gcc -Wall -c hello_world.c -g -o hello_world.o

.PHONY: clean
clean:
	rm -f hello_world
	rm -f hello_world.o
