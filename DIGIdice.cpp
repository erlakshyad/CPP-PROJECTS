#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<windows.h>
using namespace std;

void logic();
void draw(int n) {
    system("cls");

    cout << "\t\t\t\t**************************************" << endl;
    cout << "\t\t\t\tWELCOME TO MY DIGITAL DICE ROLLER:" << endl;
    cout << "\t\t\t\t**************************************" << endl;
    
    switch(n) {
    case 1 :
        cout << "\t\t\t\t\t\t ----- " << endl;
        cout << "\t\t\t\t\t\t|     |" << endl;
        cout << "\t\t\t\t\t\t|  *  |" << endl;
        cout << "\t\t\t\t\t\t|     |" << endl;
        cout << "\t\t\t\t\t\t ----- " << endl;
        break;
    case 2 :
        cout << "\t\t\t\t\t\t ----- " << endl;
        cout << "\t\t\t\t\t\t| *   |" << endl;
        cout << "\t\t\t\t\t\t|     |" << endl;
        cout << "\t\t\t\t\t\t|   * |" << endl;
        cout << "\t\t\t\t\t\t ----- " << endl;
        break;
    case 3 :
        cout << "\t\t\t\t\t\t ----- " << endl;
        cout << "\t\t\t\t\t\t| *   |" << endl;
        cout << "\t\t\t\t\t\t|  *  |" << endl;
        cout << "\t\t\t\t\t\t|   * |" << endl;
        cout << "\t\t\t\t\t\t ----- " << endl;
        break;
    case 4 :
        cout << "\t\t\t\t\t\t ----- " << endl;
        cout << "\t\t\t\t\t\t| * * |" << endl;
        cout << "\t\t\t\t\t\t|     |" << endl;
        cout << "\t\t\t\t\t\t| * * |" << endl;
        cout << "\t\t\t\t\t\t ----- " << endl;
        break;
    case 5 :
        cout << "\t\t\t\t\t\t ----- " << endl;
        cout << "\t\t\t\t\t\t| * * |" << endl;
        cout << "\t\t\t\t\t\t|  *  |" << endl;
        cout << "\t\t\t\t\t\t| * * |" << endl;
        cout << "\t\t\t\t\t\t ----- " << endl;
        break;
    case 6 :
        cout << "\t\t\t\t\t\t ----- " << endl;
        cout << "\t\t\t\t\t\t| * * |" << endl;
        cout << "\t\t\t\t\t\t| * * |" << endl;
        cout << "\t\t\t\t\t\t| * * |" << endl;
        cout << "\t\t\t\t\t\t ----- " << endl;
        break;
    default  :
        cout << n << "\nError";
        break;
    }

    cout << "\t\t\t\tPress any key to roll, 'q' or 'Q' to quit." << endl;
}

void logic() {
    char ch = getch();
    if(ch == 'q'||ch=='Q') {
        exit(0);
    }
    else {
        int delay = 50;
        for (int i = 0; i < 15; i++) { 
            int temp = rand() % 6 + 1;
            draw(temp);
            Sleep(delay);
            delay += 20;
        }
        int n = rand() % 6 + 1;
        draw(n);
    }
    logic();
}

int main() {
    srand(time(0));
    draw(1);
    logic();

    return 0;
}
