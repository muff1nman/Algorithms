all : driver

driver : driver.o Flowdown.o
	g++ driver.o Flowdown.o -o driver -g -Wall

driver.o : driver.cpp Palindrome.h
	g++ -c driver.cpp -g -Wall

Flowdown.o : Flowdown.cpp Flowdown.h
	g++ -c Flowdown.cpp -g -Wall

clean : 
	@rm -f *.o
	@rm -f driver
