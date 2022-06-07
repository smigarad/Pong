CC= g++
CFLAGS = -Wall -g -std=c++11 -fsanitize=address -lSDL2 -lSDL2_image -lSDL2_ttf
main: *.cpp
	$(CC) $(CFLAGS) *.cpp -o main