flags = -g

all : driver

driver : driver.o Andrew.o Helper.o ListCollection.o
	g++ $(flags) driver.o Andrew.o Helper.o ListCollection.o -o driver 
driver.o : driver.cpp
	g++ $(flags) -c driver.cpp

Andrew.o : Andrew.cpp
	g++ $(flags) -c Andrew.cpp -o Andrew.o

Helper.o : Helper.cpp
	g++ $(flags) -c Helper.cpp -o Helper.o

ListCollection.o : ListCollection.cpp
	g++ $(flags) -c ListCollection.cpp

clean : 
	@rm -f *.o driver
