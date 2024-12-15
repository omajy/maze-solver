#include <iostream>
#include <utility>
#include <queue>

using namespace std;

void printMaze(int maze[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (maze[i][j] == 35) {
                cout << '#' << " ";
            }
            else if (maze[i][j] == 83) {
                cout << 'S' << " ";
            }
            else if (maze[i][j] == 69) {
                cout << 'E' << " ";
            }
            else {
                cout << maze[i][j] << " ";
            }
        }
        cout << endl;
    }
}

pair<pair<int, int>, pair<int, int>> findStartEnd(int maze[9][9]) {
    pair<int, int> start, end;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (maze[i][j] == 83) {
                start = pair<int, int>(i, j);
                cout << "Start Coordinates: (" << i << ", " << j << ")" << endl;
            }
            else if (maze[i][j] == 69) { 
                cout << "End Coordinates: (" << i << ", " << j << ")" << endl;
                end = pair<int, int>(i, j);
            }
        }
    }
    return make_pair(start, end);
}

bool isValidStep(int maze[9][9], int i, int j) {
    if (i < 0 || i >= 9 || j < 0 || j >= 9) {
        return false;
    }
    else if (maze[i][j] == 83 || maze[i][j] == 0 || maze[i][j] == 69) {  
        return true;
    }
    else return false;
}

bool bfs(int maze[9][9]) {
    queue<pair<int, int>> queue;
    bool visited[9][9] = {false};
    pair<int, int> parent[9][9];
    pair<int, int> current;

    pair<pair<int, int>, pair<int, int>> coordinates = findStartEnd(maze);
    pair<int, int> start = coordinates.first;
    pair<int, int> end = coordinates.second;

    int i = start.first;
    int j = start.second;

    int moves[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    queue.push(start);
    visited[i][j] = true;
    parent[i][j] = {start.first, start.second};

    while (!queue.empty()) {
        current = queue.front();
        queue.pop();

        if (current == end) {
            pair<int, int> pathNode = current;
            while (pathNode != start) {
                if (maze[pathNode.first][pathNode.second] != 83 && maze[pathNode.first][pathNode.second] != 69) {
                    maze[pathNode.first][pathNode.second] = 35;
                }
                pathNode = parent[pathNode.first][pathNode.second];
            }
            printMaze(maze);
            return true;
        }

        for (int k = 0; k < 4; k++) {
            int i_neighbour = current.first + moves[k][0];
            int j_neighbour = current.second + moves[k][1];

            if (isValidStep(maze, i_neighbour, j_neighbour) && !visited[i_neighbour][j_neighbour]) {
                visited[i_neighbour][j_neighbour] = true;
                parent[i_neighbour][j_neighbour] = current;
                queue.push({i_neighbour, j_neighbour});
            }
        }
    }
    return false;
}

int main() {
    int maze[9][9] = {
        {83, 0, 0, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 0, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 1},
        {0, 0, 1, 0, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0, 69, 1} 
    };
    bfs(maze);
}
