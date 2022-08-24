#include "control_function.cpp"

int main(){
    init();
    short month = today.month;
    short year = today.year;

    char ch;

    while (ch != 'q'){
        displayCalandar(month, year);
        ch = _getch();

        if (ch == 'n') next(month, year);
        if (ch == 'p') previous(month, year);
        if (ch == 'r') returnToday(month, year);
    }
}