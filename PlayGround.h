#ifndef GAMEGROUND_H
#define GAMEGROUND_H

#include <vector>
#include "Snake.h"
#include "Position.h"
#include"string"

using namespace std;
enum GameStatus {
    GAME_RUNNING = 1,
    GAME_STOP = 2,
    GAME_WON = 4 | GAME_STOP,
    GAME_LOST = 8 | GAME_STOP,
};

class PlayGround
{
    vector<vector<CellType> > squares;
    Snake snake;
    GameStatus status;
    int score;
public:
    PlayGround(int width, int height);
    ~PlayGround();

   // void initPlayGround();
    bool isGameRunning() const { return status == GAME_RUNNING; }
    bool isGameStop() const { return status == GAME_STOP; }
    void processUserInput(UserInput input);
    void nextStep();
    void changeCellState(Position pos, CellType type);
    void addCherry();

    int getWidth() const { return squares[0].size(); }
    int getHeight() const { return squares.size(); }
    const vector<vector<CellType> >& getSquares() const { return squares; }
    CellType getCellState(Position p) const { return squares[p.y][p.x]; }
    void setGameStatus(GameStatus status);
    int getScore(){return snake.getScore();}

    vector<Position> getSnakePositions() const;
};

#endif
