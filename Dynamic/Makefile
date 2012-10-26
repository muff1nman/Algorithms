all : driver

driver : driver.o Flowdown.o TableMatch.o BuildUp.o
	g++ -std=c++0x driver.o Flowdown.o TableMatch.o BuildUp.o -o driver -g -Wall

driver.o : driver.cpp Palindrome.h TableMatch.h Flowdown.h BuildUp.h
	g++ -std=c++0x -c driver.cpp -g -Wall

Flowdown.o : Flowdown.cpp Flowdown.h
	g++ -std=c++0x -c Flowdown.cpp -g -Wall

TableMatch.o : TableMatch.cpp TableMatch.h
	g++ -std=c++0x -c TableMatch.cpp -g -Wall

BuildUp.o : BuildUp.cpp BuildUp.h PalStruct.h
	g++ -std=c++0x -c BuildUp.cpp -g -Wall

clean : 
	@rm -f *.o
	@rm -f driver
