test : main.o MyString.o
	g++ -std=c++11 -o test main.o MyString.o

main.o : main.cpp MyString.h
	g++ -std=c++11 -c main.cpp

MyString.o : MyString.cpp MyString.h
	g++ -std=c++11 -c MyString.cpp

clean : 
	rm test main.o MyString.o
