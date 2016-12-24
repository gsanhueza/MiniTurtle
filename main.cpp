#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum headPointer {NORTH, EAST, SOUTH, WEST};

typedef struct turtle
{
    bool floor[20][20];
    int posX;
    int posY;
    headPointer nowHeading;
    bool isPenDown;
} Turtle;

Turtle* initializeTurtle(void);
void printInstructions(void);
void printFloor(Turtle *turtle);
void processOption(string option, Turtle *turtle);
void moveTurtle(Turtle *turtle, int spaces);

int main(void)
{
    Turtle *turtle = initializeTurtle();

    printInstructions();
    string option = "1";

    while (option.at(0) != '9')
    {
        getline(cin, option);
        processOption(option, turtle);
    }

    free(turtle);

    return 0;
}

Turtle* initializeTurtle()
{
    Turtle *turtle = (Turtle *)malloc(sizeof(Turtle));

    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 20; col++)
        {
            turtle->floor[row][col] = false;
        }
    }
    turtle->posX = 0;
    turtle->posY = 0;
    turtle->nowHeading = EAST;
    turtle->isPenDown = false;

    return turtle;
}

void printInstructions()
{
    cout << "Welcome to Turtle Graphics in C++! " << endl;
    cout << "There are several options for drawing your pattern:" << endl;
    cout << " 1: Pen Up" << endl;
    cout << " 2: Pen Down" << endl;
    cout << " 3: Turn Right" << endl;
    cout << " 4: Turn Left" << endl;
    cout << " 5, x: Move forward \"x\" spaces" << endl;
    cout << " 6: Print floor" << endl;
    cout << " 9: End of Data" << endl;
    cout << endl << "Now enter your options: " << endl;
}

void printFloor(Turtle *turtle)
{
    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 20; col++)
        {
            cout << ((turtle->floor[row][col]) ? "* " : "  ");
        }
        cout << endl;
    }
    cout << endl;
}

void processOption(string option, Turtle *turtle)
{
    if (option.at(0) == '1')
    {
        turtle->isPenDown = false;
    }
    else if (option.at(0) == '2')
    {
        turtle->isPenDown = true;
    }
    else if (option.at(0) == '3')
    {
        turtle->nowHeading = static_cast<headPointer>((static_cast<int>(turtle->nowHeading) + 1) % 4);
    }
    else if (option.at(0) == '4')
    {
        turtle->nowHeading = static_cast<headPointer>((static_cast<int>(turtle->nowHeading) + 3) % 4);
    }
    else if (option.at(0) == '5')
    {
        moveTurtle(turtle, stoi(option.substr(2)));
    }
    else if (option.at(0) == '6')
    {
        printFloor(turtle);
    }
    else if (option.at(0) == '9')
    {
        return;
    }
    else
    {
        cout << "Error. Try Again." << endl;
    }
}

void moveTurtle(Turtle *turtle, int spaces)
{
    switch(turtle->nowHeading)
    {
        case NORTH:
            for (int i = turtle->posY; i >= max(turtle->posY - spaces - 1, 0); i--)
            {
                turtle->floor[i][turtle->posX] = turtle->isPenDown;
            }

            turtle->posY = max(turtle->posY - spaces, 0);
            break;

        case EAST:
            for (int i = turtle->posX; i < min(turtle->posX + spaces, 20); i++)
            {
                turtle->floor[turtle->posY][i] = turtle->isPenDown;
            }

            turtle->posX = min(turtle->posX + spaces - 1, 20 - 1);
            break;

        case SOUTH:
            for (int i = turtle->posY; i < min(turtle->posY + spaces, 20); i++)
            {
                turtle->floor[i][turtle->posX] = turtle->isPenDown;
            }

            turtle->posY = min(turtle->posY + spaces - 1, 20 - 1);
            break;

        case WEST:
            for (int i = turtle->posX; i >= max(turtle->posX - spaces - 1, 0); i--)
            {
                turtle->floor[turtle->posY][i] = turtle->isPenDown;
            }

            turtle->posX = max(turtle->posX - spaces, 0);
            break;

        default:
            break;
    }
}
