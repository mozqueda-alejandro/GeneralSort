all: driver

driver: driver.o FileManager.o Person.o
	g++ driver.o FileManager.o Person.o -o driver

driver.o: driver.cpp SortTest.h FileManager.h Person.h SortBase.h Selection.h Insertion.h Quick.h
	g++ -c driver.cpp

FileManager.o: FileManager.cpp FileManager.h
	g++ -c FileManager.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

clean:
	clear
	rm *.o *.csv driver
	clear
