all:
	g++ -Isrc/include/SDL2 -Lsrc/lib/ -o main main.cpp painter.cpp snake.cpp PlayGround.cpp Gallery.cpp Text.cpp SDL_utils.cpp display.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf