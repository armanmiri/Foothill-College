/*
 
Arman Miri
CS F002A
10/18/21
Harden
a6_1
Assignment 6 Part 1
 
This program draws a rocket based on the users input for dimensions. The program asks the user for the
width, height, and number of stages, they would like their rocket to be. Then draws the rocket that
matches the users dimnesions.
 
*/

#include <iostream>
using namespace std;

void drawHorizontalLine(int numXs);
void draw2VerticalLines(int numSpaces, int numRows);
void drawOneRow(int numSpaces);
// creation of void functions to draw

void getDimensions(int &width, int &height, int &stages);
// creation of void function for user input

void drawBox(int width, int height);
void drawCone();
void drawRocket(int &width, int &height, int &stages);
// creation of void functions to draw parts of the rocket

int main()
{
    int width;
    int height;
    int stages;
    // declaration of integers for program
    
    getDimensions(width, height, stages);
    // gets and stores the user input for height width and stages for the rocket
    
    drawRocket(width, height, stages);
    // draws the rocket based on the user inputs
    
    cout << "\n";
    // creates space in output
}





// This function asks the user for thier input on the rocket dimensions for
// width, height and stages and stores them.
void getDimensions(int &width, int &height, int &stages)
{
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter how many stages should the rocket have: ";
    cin >> stages;
    cout << "\n";
}





// This function draws the rocket based on the user inputs, with the for
// function determining how many stages will need to be drawn based on the user input
void drawRocket(int &width, int &height, int &stages)
{
    int count;
    // integer for count
    
    drawCone();
    // draws cone for top of rocket
    
    for (count = 0; count < stages; count++)
    // draws as many boxes for the number of stages the user input
    {
        drawBox(width, height);
        // draws box for stages in rocket
    }
    
    drawCone();
    // draws cone for the bottom of the rocket
}





// This function draws the cone for the rockets top and bottom
void drawCone ()
{
    cout << "  x  " << endl;
    cout << " x x " << endl;
    cout << "x   x" << endl;
    // draws cone
}





// This funcion draws a box for the rockets center based on the user input for
// height and width using functions to draw horizantal and vertical lines to form
// the box
void drawBox(int width, int height)
{
    drawHorizontalLine(width);
    // draws hoizantal line to create box
    
    draw2VerticalLines(width-2, height-2);
    // draws two vertical lines for the sides of the box
    
    drawHorizontalLine(width);
    // draws a horizantal line to close the box
}





// This function draws a horizantal line based on the user input for width which
// is set the numXs in this case to create the top of the box
void drawHorizontalLine(int numXs)
{
    int count;
    // integer for count
    
    for (count = 0; count < numXs; count++)
    // draws as many points as the user input for the width of the box
    {
        cout << "X";
        // writes a point
    }
    
    cout << endl;
    // ends line
}





// This function draws two vertical lines that are the user input for width-2 apart
// which is set to the numSpaces, and the input for user input for height-2 which is set
// to numRows. The -2 on the height and width account for the space between lines in the 2 vertical
// line function which is drawn by the draw one row function.
void draw2VerticalLines(int numSpaces, int numRows)
{
    int rowCount;
    // integer for count

    for (rowCount = 0; rowCount < numRows; rowCount++)
    // draws as many points until the number of rows is equal to the user input for height
    {
        drawOneRow(numSpaces);
        // draws a row
    }
}





// This function draws one row based on the user input for width-2 which is set to the numSpaces between
// points drawn. The -2 on the width is to account for the points that are placed in those locations that
// created the two vertical lines in the 2 vertical lines function
void drawOneRow(int numSpaces)
{
    int spaceCount;
    // integer for count
    
    cout << "X";
    // draws a point
    
    for (spaceCount = 0; spaceCount < numSpaces; spaceCount++)
    // puts space in between next point for the space needed to match user input for width
    {
        cout << " ";
        // writes black space
    }
    cout << "X" << endl;
    // writes point
    
  }




    
/*
 
 Enter width: 5
 Enter height: 6
 Enter how many stages should the rocket have: 2

   x
  x x
 x   x
 XXXXX
 X   X
 X   X
 X   X
 X   X
 XXXXX
 XXXXX
 X   X
 X   X
 X   X
 X   X
 XXXXX
   x
  x x
 x   x

 Program ended with exit code: 0
 
*/
    
