GirlMaze: GirlMaze.o tree.o room.o girl.o
	g++ GirlMaze.o tree.o room.o girl.o -o GirlMaze
tree.o: tree.cpp tree.h Treend.h
	g++ -c -g tree.cpp
room.o: room.cpp room.h
	g++ -c -g room.cpp
girl.o: girl.cpp girl.h
	g++ -c -g girl.cpp
GirlMaze.o: GirlMaze.cpp
	g++ -c -g GirlMaze.cpp
clean:
	rm -rf *.o *.~ GirlMaze
