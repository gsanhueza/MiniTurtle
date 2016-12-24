#include <iostream>
#include <string>

using namespace std;

typedef struct turtle
{
    bool floor[20][20];
    int posX;
    int posY;
} Turtle;

Turtle* initializeTurtle(void);
void printInstructions(void);
void printFloor(Turtle *turtle);
void processOption(string option, Turtle *turtle);
void moveTurtle(Turtle *turtle, int spaces);

bool isPenDown = false;
enum headPointer {NORTH, EAST, SOUTH, WEST};
headPointer nowHeading;

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
        isPenDown = false;
    }
    else if (option.at(0) == '2')
    {
        isPenDown = true;
    }
    else if (option.at(0) == '3')
    {
        nowHeading = static_cast<headPointer>((static_cast<int>(nowHeading) + 1) % 4);
    }
    else if (option.at(0) == '4')
    {
        nowHeading = static_cast<headPointer>((static_cast<int>(nowHeading) + 3) % 4);
    }
    else if (option.at(0) == '5')
    {
        moveTurtle(turtle, 5);
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
}
