// Control the program
#include "display_function.cpp"

void init(){
    //initialize data
    getToday();
    initDaysOfMonth();

    //setting console
    SetConsoleOutputCP(65001);              // set console to be able to display Vietnamese
}

void next(short &month, short &year){
    if (month == 12){
        month = 1;
        ++year;
    }
    else month++;
}

void previous(short &month, short &year){
    if (month == 1){
        month = 12;
        --year;
    }
    else month--;
}

void returnToday(short &month, short &year){
    month = today.month;
    year = today.year;
}