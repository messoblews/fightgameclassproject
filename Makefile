main.exe: main.o Fighter.o menu.o round.o startgame.o
	g++ main.o Fighter.o menu.o round.o startgame.o -o main.exe

Fighter.o: Fighter.h Fighter.cpp
	g++ Fighter.cpp -o Fighter.o -g -Wall -c

startgame.o: startgame.h startgame.cpp
	g++ startgame.cpp -o startgame.o -g -Wall -c

round.o: round.cpp round.h
	g++ round.cpp -o round.o -g -Wall -c

menu.o: menu.cpp menu.h
	g++ menu.cpp -o menu.o -g -Wall -c

main.o: main.cpp Fighter.h menu.h
	g++ main.cpp -o main.o -g -Wall -c