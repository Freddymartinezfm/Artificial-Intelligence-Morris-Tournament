




ABGame: main.o
	g++ -g -Wall -o ABGame main.o
main.o: main.cpp
	g++ -g -c main.cpp -o main.o
clean:
	del *.o
	del ABGame.exe


