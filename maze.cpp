#include <iostream>

using namespace std;

// Function to print the maze
void printMaze(char maze[5][5]) 
{
    for (int i = 0; i < 5; ++i) 
    {
        for (int j = 0; j < 5; ++j) 
        {
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() 
{
    char maze[5][5] = 
    {
        {'A', '1', '0', '0', '0'},
        {'0', '1', '0', '1', '0'},
        {'0', '0', '0', '1', '0'},
        {'0', '1', '0', '0', '0'},
        {'0', '0', '0', '1', 'B'}
    };

    int posX = 0, posY = 0;  // Player's initial position (A)

    while (true) 
    {
        printMaze(maze);  // Print the current maze

        char move;
        cout << "Enter move (w/a/s/d): ";
        cin >> move;

        // Revert the current position to path '0'
        maze[posX][posY] = '0';

        // Update the player's position based on the move
        if (move == 'w' && posX > 0 && maze[posX - 1][posY] != '1') 
        {
            posX--;
        }
        else if (move == 's' && posX < 4 && maze[posX + 1][posY] != '1') 
        {
            posX++;
        }
        else if (move == 'a' && posY > 0 && maze[posX][posY - 1] != '1') 
        {
            posY--;
        }
        else if (move == 'd' && posY < 4 && maze[posX][posY + 1] != '1') 
        {
            posY++;
        }

        // Check for reaching the destination (B)
        if (maze[posX][posY] == 'B') {
            cout << "You've reached the destination!" << endl;
            break;
        }

        // Mark the new position with [P]
        maze[posX][posY] = 'P';
    }

    return 0;
}
