project3.exe: project3.o RectangleClass.o PatternClass.o ColorImageClass.o ColorClass.o RowColumnClass.o MainMenu.o 
	g++ project3.o RectangleClass.o PatternClass.o ColorImageClass.o ColorClass.o RowColumnClass.o MainMenu.o -o project3.exe

# project3.o: project3.cpp
# 	g++ -std=c++98 -Wall -c project3.cpp -o project3.o

# RectangleClass.o: RectangleClass.cpp
# 	g++ -std=c++98 -Wall -c RectangleClass.cpp -o RectangleClass.o

# PatternClass.o: PatternClass.cpp
# 	g++ -std=c++98 -Wall -c PatternClass.cpp -o PatternClass.o

# ColorImageClass.o: ColorImageClass.cpp
# 	g++ -std=c++98 -Wall -c ColorImageClass.cpp -o ColorImageClass.o
	
# ColorClass.o: ColorClass.cpp
# 	g++ -std=c++98 -Wall -c ColorClass.cpp -o ColorClass.o

# RowColumnClass.o: RowColumnClass.cpp
# 	g++ -std=c++98 -Wall -c RowColumnClass.cpp -o RowColumnClass.o
	
# MainMenu.o: MainMenu.cpp
# 	g++ -std=c++98 -Wall -c MainMenu.cpp -o MainMenu.o


project3.o: project3.cpp
	g++ -c project3.cpp -o project3.o

RectangleClass.o: RectangleClass.cpp
	g++ -c RectangleClass.cpp -o RectangleClass.o

PatternClass.o: PatternClass.cpp
	g++ -c PatternClass.cpp -o PatternClass.o

ColorImageClass.o: ColorImageClass.cpp
	g++ -c ColorImageClass.cpp -o ColorImageClass.o
	
ColorClass.o: ColorClass.cpp
	g++ -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp
	g++ -c RowColumnClass.cpp -o RowColumnClass.o
	
MainMenu.o: MainMenu.cpp
	g++ -c MainMenu.cpp -o MainMenu.o


clean:
	rm -rf project3.o RectangleClass.o PatternClass.o ColorImageClass.o ColorClass.o RowColumnClass.o MainMenu.o project3.exe
