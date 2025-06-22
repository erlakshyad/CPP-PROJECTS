#include <iostream>

using namespace std;

string player1, player2;
char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void draw()
{
    system("cls");
    cout << "*******************************************************************************************************************************************" << endl;
    cout << "\t\t\t\t\t\tTHE TIC-TAC-TOE GAME" << endl;
    cout << "*******************************************************************************************************************************************" << endl;

    cout << "\t\t\t\t\t\t  " << a[0] << " |  " << a[1] << " |  " << a[2] << endl;
    cout << "\t\t\t\t\t\t----|----|----" << endl;
    cout << "\t\t\t\t\t\t  " << a[3] << " |  " << a[4] << " |  " << a[5] << endl;
    cout << "\t\t\t\t\t\t----|----|----" << endl;
    cout << "\t\t\t\t\t\t  " << a[6] << " |  " << a[7] << " |  " << a[8] << endl;
}

void logic(){

}

void input(int i){
    logic();
    int inp;
    if(i%2 !=0){
        cout << "\n\n\t\t\t\t\t"<<player1<<"'s turn : ( X ) "<<endl;
        cout << "\t\t\t\tEnter the position (number) : " ;
        cin >> inp;
        a[inp-1 ] = 'X';
    } 
    
    else{
        cout << "\n\n\t\t\t\t\t"<<player2<<"'s turn : ( O ) "<<endl;
        cout << "\t\t\t\tEnter the position (number) : " ;
        cin >> inp;
        a[inp -1] = 'O';

    }

}

int main()
{
    player1 = "BHAAU";
    player2 = "BHAI";
    draw();
   
   for(int i = 1; i <20 ; i ++){
    draw();       
    input(i);
           
   } 
    return 0;
}
