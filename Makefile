all: Main

Main: Achievement.o Game.o GamePlay.o Player.o Ellis-Brandon-indiv-1.o
	g++ -std=c++11 Achievement.o Player.o Game.o GamePlay.o Ellis-Brandon-indiv-1.o -o main

Achievement.o: Achievement.cpp Achievement.h
	g++ -std=c++11 -c Achievement.cpp

Player.o: Player.cpp Player.h GamePlay.h
	g++ -std=c++11 -c Player.cpp

Game.o: Game.cpp Game.h Achievement.h
	g++ -std=c++11 -c Game.cpp

GamePlay.o: GamePlay.cpp GamePlay.h Game.h
	g++ -std=c++11 -c GamePlay.cpp

Ellis-Brandon-indiv-1.o: Ellis-Brandon-indiv-1.cpp Player.h
	g++ -std=c++11 -c Ellis-Brandon-indiv-1.cpp

clean:
	rm *.o main

run:
	./main < "input.txt"