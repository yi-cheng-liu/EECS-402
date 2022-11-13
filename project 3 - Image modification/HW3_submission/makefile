project3.exe: project3.o RectangleClass.o PatternClass.o ColorImageClass.o ColorClass.o RowColumnClass.o menu.o 
	g++ project3.o RectangleClass.o PatternClass.o ColorImageClass.o ColorClass.o RowColumnClass.o menu.o -o project3.exe

project3.o: project3.cpp
	g++ -std=c++98 -Wall -c project3.cpp -o project3.o

RectangleClass.o: RectangleClass.cpp
	g++ -std=c++98 -Wall -c RectangleClass.cpp -o RectangleClass.o

PatternClass.o: PatternClass.cpp
	g++ -std=c++98 -Wall -c PatternClass.cpp -o PatternClass.o

ColorImageClass.o: ColorImageClass.cpp
	g++ -std=c++98 -Wall -c ColorImageClass.cpp -o ColorImageClass.o
	
ColorClass.o: ColorClass.cpp
	g++ -std=c++98 -Wall -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp
	g++ -std=c++98 -Wall -c RowColumnClass.cpp -o RowColumnClass.o
	
menu.o: menu.cpp
	g++ -std=c++98 -Wall -c menu.cpp -o menu.o

clean:
	rm -rf project3.o RectangleClass.o PatternClass.o ColorImageClass.o ColorClass.o RowColumnClass.o menu.o project3.exe
