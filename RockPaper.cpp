#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

string player;
char rps;
char RPS;
int RoundCount = 1;
int RockCount = 0;
int PaperCount = 0;
int ScissorCount = 0;
float if60percent = 0;
float ProbR;
float ProbP;
float ProbS;
int recentMovesR = 0;
int recentMovesS = 0;
int recentMovesP = 0;
int ResultRecR;
int ResultRecS;
int ResultRecP;

int PlayerScore;
int AIscore;

void firstpage()
{
    system("cls");
    for (int i = 5; i >= 1; i--)
    {
        cout << "\t\t\t\t******************************************\n\t\t\t\t*           /\\        _______            *\n\t\t\t\t*          /  \\          |               *\n\t\t\t\t*         /____\\         |               *\n\t\t\t\t*        /      \\        |               *\n\t\t\t\t*       /        \\    ___|___            *\n\t\t\t\t*                                        *\n\t\t\t\t*       ROCK PAPER SCISSORS GAME         *\n\t\t\t\t******************************************" << endl;

        cout << "\n\n"
             << "\t\t\t\tSTARTS IN " << i << " seconds";
        std::this_thread::sleep_for(std::chrono::milliseconds(900));

        for (int j = 0; j < 4; j++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(250));

            cout << '.';
        }
        system("cls");
    }
}

char AIlogic()
{

    // win stay, lose shift
    if (ResultRecP == 1)
    {
        RPS = 'r';
    }
    else if (ResultRecS == 1)
    {
        RPS = 'p';
    }
    else if (ResultRecR == 1)
    {
        RPS = 's';
    }
    else if (recentMovesP >= 2)
    {
        RPS = 's';
    }
    else if (recentMovesR >= 2)
    {
        RPS = 'p';
    }
    else if (recentMovesS >= 2)
    {
        RPS = 'r';
    }
    else if (RoundCount >= 10)
    {
        if (((float)RockCount / (float)RoundCount) >= 0.45)
        {
            RPS = 'p';
        }
        else if (((float)PaperCount / (float)RoundCount) >= 0.45)
        {
            RPS = 's';
        }
        else if (((float)ScissorCount / (float)RoundCount) >= 0.45)
        {
            RPS = 'r';
        }
        else if (RockCount == PaperCount && RockCount == ScissorCount)
        {
            RPS = '0';
        }
    }
    // recent moves

    else
    {
        RPS = '0';
    }

    return RPS;
}

int rpsLogic(char rps)
{

    int result;
    srand(time(NULL));

    if (AIlogic() == '0')
    {
        int _RPS = (rand() % 3);

        if (_RPS == 0)
        {
            RPS = 'r';
        }
        if (_RPS == 1)
        {
            RPS = 'p';
        }
        if (_RPS == 2)
        {
            RPS = 's';
        }
    }
    else
    {
        RPS = AIlogic();
    }

    if ((rps == 'r' || rps == 'R') && (RPS == 'p'))
    {
        result = -1;
        ResultRecR = 0;
        ResultRecP = 0;
        ResultRecS = 0;
    }
    if ((rps == 'P' || rps == 'P') && (RPS == 'r'))
    {
        result = 1;
        ResultRecP++;
        ResultRecR = 0;
        ResultRecS = 0;
    }
    if ((rps == 's' || rps == 'S') && (RPS == 'p'))
    {
        result = 1;
        ResultRecS++;
        ResultRecR = 0;
        ResultRecP = 0;
    }
    if ((rps == 'P' || rps == 'p') && (RPS == 's'))
    {
        result = -1;
        ResultRecR = 0;
        ResultRecP = 0;
        ResultRecS = 0;
    }
    if ((rps == 'r' || rps == 'R') && (RPS == 's'))
    {
        result = 1;
        ResultRecR++;
        ResultRecS = 0;
        ResultRecP = 0;
    }
    if ((rps == 's' || rps == 'S') && (RPS == 'r'))
    {
        result = -1;
        ResultRecR = 0;
        ResultRecP = 0;
        ResultRecS = 0;
    }
    if ((rps == RPS) || rps == 'P' && RPS == 'p' || rps == 'S' && RPS == 's' || rps == 'R' && RPS == 'r')
    {
        result = 0;
        ResultRecR = 0;
        ResultRecP = 0;
        ResultRecS = 0;
    }

    return result;
}

void AnnounceResult(int result, string player, char rps, char RPS)
{
    if (rps == 'p')
    {
        cout << "\t\t\t\t+-----------------------------------------------+" << endl;
        cout << "\t\t\t\t|" << setw(20) << player << "'s move    ----> Paper     |" << endl;
        PaperCount++;
        recentMovesP++;
        recentMovesR = 0;
        recentMovesS = 0;
    }
    if (rps == 'r')
    {
        cout << "\t\t\t\t+-----------------------------------------------+" << endl;
        cout << "\t\t\t\t|" << setw(20) << player << "'s move    ----> Rock      |" << endl;
        RockCount++;
        recentMovesR++;
        recentMovesP = 0;
        recentMovesS = 0;
    }
    if (rps == 's')
    {
        cout << "\t\t\t\t+-----------------------------------------------+" << endl;
        cout << "\t\t\t\t|" << setw(20) << player << "'s move    ----> Scissor    |" << endl;
        ScissorCount++;
        recentMovesS++;
        recentMovesP = 0;
        recentMovesR = 0;
    }
    if (rps == 'P')
    {
        cout << "\t\t\t\t+-----------------------------------------------+" << endl;
        cout << "\t\t\t\t|" << setw(20) << player << "'s move    ----> Paper     |" << endl;
        PaperCount++;
        recentMovesP++;
        recentMovesR = 0;
        recentMovesS = 0;
    }
    if (rps == 'R')
    {
        cout << "\t\t\t\t+-----------------------------------------------+" << endl;
        cout << "\t\t\t\t|" << setw(20) << player << "'s move    ----> Rock      |" << endl;
        RockCount++;
        recentMovesR++;
        recentMovesP = 0;
        recentMovesS = 0;
    }
    if (rps == 'S')
    {
        cout << "\t\t\t\t+-----------------------------------------------+" << endl;
        cout << "\t\t\t\t|" << setw(20) << player << "'s move    ----> Scissor    |" << endl;
        ScissorCount++;
        recentMovesS++;
        recentMovesR = 0;
        recentMovesP = 0;
    }
    cout << "\t\t\t\t" << "|                    And                        |" << endl;
    if (RPS == 'p')
    {

        cout << "\t\t\t\t" << "|           The AI's move ----> Paper           |" << endl;
        cout << "\t\t\t\t" << "+-----------------------------------------------+" << endl;
    }
    if (RPS == 'r')
    {
        cout << "\t\t\t\t" << "|           The AI's move ----> Rock            |" << endl;
        cout << "\t\t\t\t" << "+-----------------------------------------------+" << endl;
    }
    if (RPS == 's')
    {
        cout << "\t\t\t\t" << "|           The AI's move ----> Scissor         |" << endl;
        cout << "\t\t\t\t" << "+-----------------------------------------------+" << endl;
    }
    switch (result)
    {

    case 1:
        PlayerScore++;
        cout << "\n\n\t\t\t\t" << "+-----------------------------------------------+" << endl;
        cout << "\t\t\t\t|" << "          Congratulations!                     |" << endl;
        cout << "\t\t\t\t|" << setw(20) << player << " won      > v <            |" << endl;
        cout << "\t\t\t\t" << "+-----------------------------------------------+" << endl;
        break;

    case -1:
        AIscore++;
        cout << "\n\n\t\t\t\t" << "+-----------------------------------------------+" << endl;
        cout << "\t\t\t\t|" << "          Oh No!                               |" << endl;
        cout << "\t\t\t\t|" << "            AI won      > v <                  |" << endl;
        cout << "\t\t\t\t" << "+-----------------------------------------------+" << endl;
        break;

    case 0:
        cout << "\n\n\t\t\t\t" << "+-----------------------------------------------+" << endl;
        cout << "\t\t\t\t" << "|                  DRAW!                        |" << endl;
        cout << "\t\t\t\t" << "+-----------------------------------------------+" << endl;
        break;

    default:
        cerr << "\t\t\t\tERROR!" << endl;
        break;
    }
    cout << "\n\n+-----------------------------------------------+\t\t+-----------------------------------------------+" << endl;
    cout << "|" << setw(20) << player << "'s score : " << setw(4) << PlayerScore << "            |" << "\t\t| " << "                    AI's score : " << setw(4) << AIscore << "         |" << endl;
    cout << "+-----------------------------------------------+\t\t+-----------------------------------------------+" << endl;
}

int main()
{
    firstpage();
    cout << "***********************************************************************************************************************" << endl;
    cout << "\t\t\t\tWelcome to the Rock Paper Scissors Game" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "\n\t\t\t\tEnter the player's name : \n\t\t\t\t Or just enter 1 to enter default name(PLAYER)" << endl;
    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"
         << endl;
    cout << "\t\t\t\t====> ";
    cin >> player;
    if (player == "1")
    {
        player = "PLAYER";
    }
    system("cls");
    cout << "***********************************************************************************************************************" << endl;
    cout << "\t\t\t\tWelcome to the Rock Paper Scissors Game" << endl;
    cout << "***********************************************************************************************************************" << endl;

    while (1)
    {

        while (1)
        {
            cout << "\n\t\t\t\t\t\t\tRound " << RoundCount << " : " << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

            cout << "\t\t\t\tEnter => " << endl;
            cout << "\t\t\t\t----> r for rock" << endl;
            cout << "\t\t\t\t----> p for paper" << endl;
            cout << "\t\t\t\t----> s for scissor" << endl;
            cout << "\n\t\t\t\t-----------------------\n";
            cout << "\n\t\t\t\t====> ";
            cin >> rps;

            if (rps == 'r' || rps == 'p' || rps == 's' || rps == 'R' || rps == 'P' || rps == 'S')
            {
                break;
            }

            else
            {
                cout << "\t\t\t\tInvalid input!" << endl;
                system("cls");
            }
        }

        int result = rpsLogic(rps);

        AnnounceResult(result, player, rps, RPS);
        RoundCount++;
        cout << "=======================================================================================================================" << endl;
        cout << "Press the ENTER key to do next round";
        cin.ignore();
        cin.get();
        system("cls");
        cout << "=======================================================================================================================" << endl;
    }

    return 0;
}