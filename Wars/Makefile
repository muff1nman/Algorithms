flags = -g -Wall
all : driver

driver : driver.o
	@g++ $(flags) driver.o -o driver

driver.o : driver.cpp
	@g++ $(flags) -c driver.cpp

clean : 
	@rm -f *.o driver
