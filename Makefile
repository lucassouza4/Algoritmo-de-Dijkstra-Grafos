all: principal.o dijkstra.o
	g++ -o programa principal.o dijkstra.o

run:
	.\programa.exe

principal.o: principal.cpp
	g++ principal.cpp -c
 
dijkstra.o: dijkstra.cpp
	g++ dijkstra.cpp -c