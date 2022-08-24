// Console functions
#pragma once
#include "library.cpp"

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

void goTo(short x, short y){
    COORD Position;
    Position.X = x;
    Position.Y = y;
	SetConsoleCursorPosition(hStdout, Position);
}

void setColor(int backgroundColor, int textColor){
    /*
        0 = Black                       8 = Gray 
        1 = Blue                        9 = Light Blue
        2 = Green                       10 = Light Green
        3 = Aqua                        11 = Light Aqua
        4 = Red                         12 = Light Red
        5 = Purple                      13 = Light Purple
        6 = Yellow                      14 = Light Yellow
        7 = White                       15 = Bright White
    */
   int colorCode = backgroundColor * 16 + textColor;
   SetConsoleTextAttribute(hStdout, colorCode);
}
