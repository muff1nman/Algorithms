flags = -g -Wall

all : driver

driver : driver.o Andrew.o Helper.o
	g++ $(flags) driver.o Andrew.o Helper.o -o driver 
driver.o : driver.cpp
	g++ $(flags) -c driver.cpp

Andrew.o : Andrew.cpp
	g++ $(flags) -c Andrew.cpp -o Andrew.o

Helper.o : Helper.cpp
	g++ $(flags) -c Helper.cpp -o Helper.o

clean : 
	@rm -f *.o driver
