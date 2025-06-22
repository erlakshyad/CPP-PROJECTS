#include <iostream>
#include <iomanip>
#include <windows.h>


using namespace std;

void operation(double *a, char *opr, double *b, double *ans);



int main()
{
    double a;
    double b;
    double ans;
    char Operator;
    
    cout << "\t\t\t\t***************************************************************************************" << endl;
    cout << "\t\t\t\t                                 BASIC CALCULATOR                                      " << endl;
    cout << "\t\t\t\t***************************************************************************************" << endl;
    cout << "\t\t\t\t\tThe format : \n\t\t\t\t\t\ta + b\n\t\t\t\t\t\ta - b\n\t\t\t\t\t\ta / b\n\t\t\t\t\t\ta * b" << endl;
    cout << "\t\t\t\t---------------------------------------------------------------------------------------" << endl;
    
    do
    {
        cout << "\t\t\t\t                        Type the operands and operators                                " << endl;
        cout << "\t\t\t\t---------------------------------------------------------------------------------------\n" << endl;

        cout << "\n\t\t\t\t\t\tExpression = ";
        cin >> a>> Operator>>b;

        operation(&a, &Operator, &b, &ans);

        cout << "\n\n\t\t\t\t\t\t+------------------------+" << endl;
        cout << "\t\t\t\t\t\t|" << setw(12) << ans << setw(13) << "|" << endl;
        cout << "\t\t\t\t\t\t+------------------------+\n" << endl;

        cout << "\t\t\t\t=======================================================================================" << endl;
        
    } while (true);

    return 0;
}

void operation(double *a, char *opr, double *b, double *ans)
{
    switch (*opr)
    {
    case '+':
        *ans = *a + *b;
        break;
    case '-':
        *ans = *a - *b;
        break;
    case '/':
        *ans = *a / *b;
        break;
    case '*':
        *ans = *a * *b;
        break;
    default:
        cout << "ERROR...............................";
        *ans = 0;
    }
}

