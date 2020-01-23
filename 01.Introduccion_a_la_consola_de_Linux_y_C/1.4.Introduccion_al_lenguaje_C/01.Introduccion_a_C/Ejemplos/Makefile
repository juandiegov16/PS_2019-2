fahr2cel: fahrenheit.o
	gcc fahrenheit.o -o fahr2cel

fahrenheit.o: fahrenheit.c
	gcc -Wall -c fahrenheit.c -g -o fahrenheit.o

.PHONY: clean
clean:
	rm -f fahrenheit
	rm -f fahr2cel
	rm -f fahrenheit.o
