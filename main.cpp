#include <iostream>

using namespace std; 

void printMaze(int maze[9][9]){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(maze[i][j] == 83){
                cout<<'S'<<" ";
            }
            else if(maze[i][j] == 69){
                cout<<'E'<<" ";
            }
            else{
                cout<<maze[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

void findStartEnd(int maze[9][9]){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(maze[i][j] == 83){
                cout<<"Start Coordinates: ("<<i<<", "<<j<<")"<<endl;
            }
            else if(maze[i][j] == 69){
                cout<<"End Coordinates: ("<<i<<", "<<j<<")"<<endl;
            }
        }
    }
}

bool isValidStep(int maze[9][9], int i, int j){
    if (i < 0 || i >= 9 || j < 0 || j >= 9) {
    return false;
    }
    else if(maze[i][j] == 83 || maze[i][j] == 0 || maze[i][j] == 69){
        return true;
    }
    else return false;
}

int main(){
    int maze[9][9] = {
    {'S', 0, 0, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 0, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 'E', 1}
    };

    printMaze(maze);
    findStartEnd(maze);
    cout << isValidStep(maze, 10, 10) << endl; //no
    cout << isValidStep(maze, 0, 0) << endl; //yes
    cout << isValidStep(maze, 1, 1) << endl; //no
    cout << isValidStep(maze, 8, 7) << endl; //yes
}