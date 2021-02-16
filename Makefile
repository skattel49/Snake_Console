test: Board.cpp Fruit.cpp Snake.cpp
	g++ -o test main.cpp Board.cpp Snake.cpp Fruit.cpp -lpthread

clean:
	rm -rf *.o test