CC = g++
CFLAGS = -g -Wall -std=c++11


## RUN PROGRAM BY SIMPLY TYPING "make" INTO TERMINAL
a.out: calculator_main.o transaction.o transaction.h
	$(CC) $(CFLAGS) calculator_main.o transaction.o -o run

transaction.o: transaction.cc transaction.h
	$(CC) -c $(CFLAGS) transaction.cc

calculator_main.o: calculator_main.cc transaction.h
	$(CC) -c $(CFLAGS) calculator_main.cc

run:
	make
	./run
## FOR DEV PURPOSES, REMOVES ALL CURRENT COMPILED FILES
clean:
	rm -f run calculator_main.o transaction.o