#ifndef SUDOKU_H
#define SUDOKU_H
#include<string>
using namespace std;

class Sudoku
{

private:

    int board[9][9];

    int difficulty;


    string playerName;

    int gamesPlayed;

    int gamesSolved;

    int bestScore;


public:

    Sudoku();


    void welcomeScreen();

    void instructions();

    void loadingAnimation();

    void getPlayerDetails();

    void showStatistics();


    void savePlayerData();

    void loadPlayerData();


    void menu();


    void selectDifficulty();

    void displayBoard();


    void startTimer();

    void calculateScore();


    void saveGame();

    void loadGame();


    bool isSafe(int row,int col,int num);

    bool isValid();

    bool solve();

    void inputBoard();
};


#endif
