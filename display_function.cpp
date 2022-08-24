#include "DayTime_function.cpp"
#include "console_function.cpp"

void displayInstruction(){
    setColor(0,2);
    cout << "Press 'n' to Next. Press 'p' to Previous. Press 'r' to return to this month. Press 'q' to Quit."<<endl;
    setColor(0,7);
}

void displayDays(short month, short year){
    initDays(month, year);
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            short day = days[i][j];
            if (!validDay(day, month, year)) cout << "    ";     // 4 spaces
            else if (day <= 9) cout << day << "   ";            // 3 spaces
            else cout << day << "  ";                           // 2 spaces;
        }
        cout << endl;
    }
}

void displayCalandar(short month, short year){
    system("cls");
    setColor(0,11);
    cout << "----------------------------" << endl;
    cout << "          " << stringMonth[month] << ", " << year <<endl;
    cout << "----------------------------" << endl;
    setColor(0,7);

    cout << "M   T   W   T   F   S   S   "<<endl;
    
    displayDays(month, year);
    cout << "\n";
    displayInstruction();
}
