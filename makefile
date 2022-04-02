all: driver

driver: driver.o FileManager.o
	g++ driver.o FileManager.o -o driver

driver.o: driver.cpp SortTest.h FileManager.h Selection.h Insertion.h Quick.h
	g++ -c driver.cpp

FileManager.o: FileManager.cpp FileManager.h
	g++ -c FileManager.cpp

clean:
	clear
	rm *.o *.csv driver
	clear