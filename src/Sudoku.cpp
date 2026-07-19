#include <iostream>
#include <fstream>

#include "Sudoku.h"
#include <chrono>
#include <thread>

using namespace std::chrono;
steady_clock::time_point startTime;
using namespace std;


Sudoku::Sudoku()
{

    gamesPlayed = 0;

    gamesSolved = 0;

    bestScore = 0;


    loadPlayerData();


    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            board[i][j]=0;
        }
    }

}

void Sudoku::welcomeScreen()
{

    cout<<"\n====================================\n";

    cout<<"        🧩 SUDOKU SOLVER 🧩\n";

    cout<<"====================================\n";


    cout<<"\nWelcome Player!";

    cout<<"\nSolve puzzles using logic and algorithms.";

    cout<<"\nPowered by C++ Backtracking Algorithm\n";


}

void Sudoku::instructions()
{

    cout<<"\n========== HOW TO PLAY ==========\n";


    cout<<"\n1. Select difficulty level.";

    cout<<"\n2. Fill empty cells.";

    cout<<"\n3. Every row must contain 1-9.";

    cout<<"\n4. Every column must contain 1-9.";

    cout<<"\n5. Every 3x3 box must contain 1-9.";


    cout<<"\n\nGood Luck! 🎯\n";

}

void Sudoku::loadingAnimation()
{

    cout<<"\nLoading";


    for(int i=0;i<3;i++)
    {

        cout<<".";

        this_thread::sleep_for(
            chrono::milliseconds(500)
        );

    }


    cout<<"\n";

}

void Sudoku::getPlayerDetails()
{

    cout<<"\nEnter your name: ";

    cin>>playerName;


}

void Sudoku::showStatistics()
{

    cout<<"\n==========================";

    cout<<"\n       PLAYER STATS";

    cout<<"\n==========================";


    cout<<"\nPlayer: "
        <<playerName;


    cout<<"\nGames Played: "
        <<gamesPlayed;


    cout<<"\nGames Solved: "
        <<gamesSolved;


    cout<<"\nBest Score: "
        <<bestScore;


}

void Sudoku::savePlayerData()
{

    ofstream file("data/player.txt");


    if(file)
    {

        file<<playerName<<endl;

        file<<gamesPlayed<<endl;

        file<<gamesSolved<<endl;

        file<<bestScore<<endl;

    }


    file.close();

}

void Sudoku::loadPlayerData()
{

    ifstream file("data/player.txt");


    if(file)
    {

        getline(file,playerName);


        file>>gamesPlayed;

        file>>gamesSolved;

        file>>bestScore;

    }


    else
    {
        playerName="Guest";
    }


    file.close();

}

void Sudoku::menu()
{

    int choice;


    do
    {

        cout<<"\n========================";
        cout<<"\n      SUDOKU SOLVER";
        cout<<"\n========================";

        cout<<"\n1. New Game";
        cout<<"\n2. Solve Sudoku";
        cout<<"\n3. Display Board";
        cout<<"\n4. Save Game";
        cout<<"\n5. Load Game";
        cout<<"\n6. Statistics";
        cout<<"\n7. Exit";


        cout<<"\n\nEnter choice: ";
        if(!(cin>>choice))
        {
            cin.clear();
            cin.ignore(1000,'\n');

            cout<<"\nInvalid input!";
            continue;
        }

        switch(choice)
        {

        case 1:

            selectDifficulty();

            cout<<"\nNew Sudoku Generated!";
            displayBoard();

            break;



        case 2:

            startTimer();
            gamesPlayed++;
            calculateScore();
            savePlayerData();
            if(solve())
            {
                cout<<"\nSudoku Solved Successfully!";
                displayBoard();
                calculateScore();
            }

            else
            {
                cout<<"\nNo solution exists!";
            }

            break;



        case 3:

            displayBoard();

            break;



        case 4:

            saveGame();

            break;



        case 5:

            loadGame();

            displayBoard();

            break;



        case 6:

            showStatistics();

            break;



        case 7:

            cout<<"\nThanks for playing Sudoku!";
            break;



        default:

            cout<<"\nInvalid Choice!";

        }


    }while(choice!=7);


}

void Sudoku::displayBoard()
{

    cout<<"\n";

    cout<<"+-------+-------+-------+\n";


    for(int i=0;i<9;i++)
    {

        for(int j=0;j<9;j++)
        {

            if(j%3==0)
                cout<<"| ";


            if(board[i][j]==0)
                cout<<". ";

            else
                cout<<board[i][j]<<" ";

        }


        cout<<"|\n";


        if((i+1)%3==0)
            cout<<"+-------+-------+-------+\n";

    }

}

bool Sudoku::isSafe(int row, int col, int num)
{

    // Check row
    for(int j=0;j<9;j++)
    {
        if(board[row][j] == num)
        {
            return false;
        }
    }


    // Check column
    for(int i=0;i<9;i++)
    {
        if(board[i][col] == num)
        {
            return false;
        }
    }


    // Check 3x3 box

    int startRow = row - row % 3;
    int startCol = col - col % 3;


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[startRow+i][startCol+j] == num)
            {
                return false;
            }
        }
    }


    return true;
}

void Sudoku::startTimer()
{

    startTime = steady_clock::now();

}

void Sudoku::calculateScore()
{

    auto endTime = steady_clock::now();


    auto duration =
    duration_cast<seconds>(endTime - startTime);



    int timeTaken = duration.count();



    int score;



    if(difficulty == 1)
    {
        score = 1000 - timeTaken;
    }

    else if(difficulty == 2)
    {
        score = 1500 - timeTaken;
    }

    else
    {
        score = 2000 - timeTaken;
    }



    if(score < 0)
        score = 0;



    cout<<"\n========================";
    cout<<"\n      RESULT";
    cout<<"\n========================";


    cout<<"\nTime Taken: "
        <<timeTaken<<" seconds";


    cout<<"\nScore: "
        <<score;


}


bool Sudoku::solve()
{

    if(!isValid())
    {
        return false;
    }
    int row = -1;
    int col = -1;

    bool emptyFound = false;


    // Find empty cell
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j] == 0)
            {
                row = i;
                col = j;
                emptyFound = true;
                break;
            }
        }

        if(emptyFound)
            break;
    }


    // If no empty cell, sudoku solved
    if(!emptyFound)
    {
        return true;
    }


    // Try numbers 1-9
    for(int num=1; num<=9; num++)
    {

        if(isSafe(row,col,num))
        {

            board[row][col] = num;


            // Recursive call
            if(solve())
            {
                return true;
            }


            // Backtrack
            board[row][col] = 0;
        }
    }


    return false;
}

void Sudoku::inputBoard()
{
    cout<<"\nEnter Sudoku puzzle (0 for empty cells):\n";


    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>board[i][j];
        }
    }
}

void Sudoku::selectDifficulty()
{

    int choice;


    cout<<"\nChoose Difficulty Level\n";
    cout<<"1. Easy\n";
    cout<<"2. Medium\n";
    cout<<"3. Hard\n";
    cout<<"Enter choice: ";

    cin>>choice;


    int easy[9][9] =
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };


    int medium[9][9] =
    {
        {0,3,0,0,7,0,0,0,0},
        {6,0,0,1,0,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,0},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };


    int hard[9][9] =
    {
        {0,0,0,0,0,0,0,1,2},
        {0,0,0,0,3,5,0,0,0},
        {0,0,0,0,0,0,4,0,0},
        {0,0,0,7,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,5},
        {0,0,0,0,0,8,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,9}
    };


    int (*selected)[9];


    if(choice==1)
    {
        selected = easy;
        difficulty = 1;
    }


    else if(choice==2)
    {
        selected = medium;
        difficulty = 2;
    }


    else if(choice==3)
    {
        selected = hard;
        difficulty = 3;
    }


    else
    {
        cout<<"\nInvalid difficulty!";
        return;
    }



    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            board[i][j]=selected[i][j];
        }
    }

}

bool Sudoku::isValid()
{

    for(int i=0;i<9;i++)
    {

        for(int j=0;j<9;j++)
        {

            if(board[i][j] != 0)
            {

                int temp = board[i][j];


                board[i][j] = 0;


                if(!isSafe(i,j,temp))
                {
                    board[i][j] = temp;
                    return false;
                }


                board[i][j] = temp;

            }

        }

    }


    return true;
}

void Sudoku::saveGame()
{

    ofstream file("data/sudoku.txt");


    if(!file)
    {
        cout<<"\nFile could not be opened!";
        return;
    }


    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            file << board[i][j] << " ";
        }

        file << endl;
    }


    file.close();


    cout<<"\nGame saved successfully!";

}

void Sudoku::loadGame()
{

    ifstream file("data/sudoku.txt");


    if(!file)
    {
        cout<<"\nNo saved game found!";
        return;
    }



    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            file >> board[i][j];
        }
    }


    file.close();


    cout<<"\nGame loaded successfully!";

}
