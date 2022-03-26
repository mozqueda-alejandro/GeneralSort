driver: driver.o FileManager.o
	g++ driver.o FileManager.o -o driver

driver.o: driver.cpp SortTest.h FileManager.h Selection.h Insertion.h Quick.h
	g++ -c driver.cpp

# SortTest.o: SortTest.cpp SortTest.h
# 	g++ -c SortTest.cpp

FileManager.o: FileManager.cpp FileManager.h
	g++ -c FileManager.cpp

clean:
	rm *.o driver