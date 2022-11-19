proj4.exe: LinkedNodeClass.o SortedListClass.o LIFOStackClass.o FIFOQueueClass.o proj4.o
	g++ LinkedNodeClass.o SortedListClass.o LIFOStackClass.o FIFOQueueClass.o proj4.o -o proj4.exe

LinkedNodeClass.o: LinkedNodeClass.cpp
	g++ -c LinkedNodeClass.cpp -o LinkedNodeClass.o 
SortedListClass.o:
	g++ -c SortedListClass.cpp -o SortedListClass.o 

LIFOStackClass.o: LIFOStackClass.cpp
	g++ -c LIFOStackClass.cpp -o LIFOStackClass.o 
FIFOQueueClass.o: FIFOQueueClass.cpp
	g++ -c FIFOQueueClass.cpp -o FIFOQueueClass.o 
proj4.o: proj4.cpp
	g++ -c proj4.cpp -o proj4.o
	
clean:
	rm -rf LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o proj4.o proj4.exe