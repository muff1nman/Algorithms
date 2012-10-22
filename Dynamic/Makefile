all : driver

driver : driver.o Flowdown.o TableMatch.o
	g++ -std=c++0x driver.o Flowdown.o TableMatch.o -o driver -g -Wall

driver.o : driver.cpp Palindrome.h TableMatch.h Flowdown.h
	g++ -std=c++0x -c driver.cpp -g -Wall

Flowdown.o : Flowdown.cpp Flowdown.h
	g++ -std=c++0x -c Flowdown.cpp -g -Wall

TableMatch.o : TableMatch.cpp TableMatch.h
	g++ -std=c++0x -c TableMatch.cpp -g -Wall

clean : 
	@rm -f *.o
	@rm -f driver
