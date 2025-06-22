#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    // Get the console handle
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set text color to Green
    SetConsoleTextAttribute(hConsole, 2);
    cout << "This is green text!" << endl;

    // Set text color to Red
    SetConsoleTextAttribute(hConsole, 4);
    cout << "This is red text!" << endl;

    // Set text color to Yellow on Blue background
    SetConsoleTextAttribute(hConsole, 6 + 1 * 16);
    cout << "This is yellow text on blue background!" << endl;

    // Reset to default color (White)
    SetConsoleTextAttribute(hConsole, 7);
    cout << "Back to default color." << endl;

    return 0;
}
