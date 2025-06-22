#include <iostream>

using namespace std;
int main();
int i = 0;

char Ui()
{
    int ch;
    cout << "***************************************************************************************************************" << endl;
    cout << "\t\t\t\tWelcome to the program of Logic Gates" << endl;
    cout << "***************************************************************************************************************" << endl;
    cout << "\n\t\t\tCHOOSE THE FOLLOWING LOGIC GATE : " << endl;
    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t1. AND GATE" << endl;
    cout << "\t\t\t\t2. OR GATE" << endl;
    cout << "\t\t\t\t3. NOT GATE" << endl;
    cout << "\t\t\t\t4. NAND GATE" << endl;
    cout << "\t\t\t\t5. NOR GATE" << endl;
    cout << "\t\t\t\t6. EX-OR GATE" << endl;
    cout << "\t\t\t\t7. EX-NOR GATE" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------" << endl;

    cout << "\n\t\t\t\t\tENTER THE OPTION NUMBER: ";
    cin >> ch;
    system("cls");
    return ch;
}

void logic(int ch)
{
    bool a, b, y;
    char B;
    switch (ch)
    {
    case 1:
    {

        cout << "===============================================================================================================" << endl;

        if (i == 0)
        {
            cout << "\t\t\t\t\tAND GATE" << endl;
            i++;
        }

        cout << "===============================================================================================================" << endl;
        cout << "Tell me the total numbers of operands : " << endl;
        int totOpe;
        cin >> totOpe;
        bool b[totOpe];

        for (int i = 0; i < totOpe; i++)
        {
            cout << "\t\t\t\tEnter input number " << i + 1 << " = ";
            cin >> b[i];
        }
        y = b[0];
        for (int i = 1; i < totOpe; i++)
        {
            y = y & b[i];
        }

        cout << "\t\t\t\tANDing all the inputs....\n"
             << endl;

        cout << "\n\t\t\t\t+---------------+" << endl;
        cout << "\t\t\t\t|  OUTPUT = " << y << "   |" << endl;
        cout << "\t\t\t\t+---------------+" << endl;

        break;
    };
    case 2:
    {

        cout << "===============================================================================================================" << endl;

        if (i == 0)
        {
            cout << "\t\t\t\t\tOR GATE" << endl;
            i++;
        }

        cout << "===============================================================================================================" << endl;
        cout << "Tell me the total numbers of operands : " << endl;
        int totOpe;
        cin >> totOpe;
        bool b[totOpe];

        for (int i = 0; i < totOpe; i++)
        {
            cout << "\t\t\t\tEnter input number " << i + 1 << " = ";
            cin >> b[i];
        }
        y = b[0];
        for (int i = 1; i < totOpe; i++)
        {
            y = y | b[i];
        }
        cout << "\t\t\t\tORing all the inputs....\n"
             << endl;

        cout << "\n\t\t\t\t+---------------+" << endl;
        cout << "\t\t\t\t|  OUTPUT = " << y << "   |" << endl;
        cout << "\t\t\t\t+---------------+" << endl;

        break;
    };
    case 3:
    {

        cout << "===============================================================================================================" << endl;

        if (i == 0)
        {
            cout << "\t\t\t\t\tNOT GATE" << endl;
            i++;
        }

        cout << "===============================================================================================================" << endl;
        cout << "\t\t\t\tEnter input A = ";
        cin >> a;

        if (a > 1 || a < 0)
        {
            system("cls");
            logic(1);
        }

        else
        {
            cout << "\t\t\t\tInverting the input....\n"
                 << endl;

            y = !a;
            cout << "\n\t\t\t\t+---------------+" << endl;
            cout << "\t\t\t\t|    (A') = " << y << "   |" << endl;
            cout << "\t\t\t\t+---------------+" << endl;
        }
        break;
    };
    case 4:
    {

        cout << "===============================================================================================================" << endl;

        if (i == 0)
        {
            cout << "\t\t\t\t\tNAND GATE" << endl;
            i++;
        }

        cout << "===============================================================================================================" << endl;
        cout << "Tell me the total numbers of operands : " << endl;
        int totOpe;
        cin >> totOpe;
        bool b[totOpe];

        for (int i = 0; i < totOpe; i++)
        {
            cout << "\t\t\t\tEnter input number " << i + 1 << " = ";
            cin >> b[i];
        }
        y = b[0];
        for (int i = 1; i < totOpe; i++)
        {
            y = ~(y & b[i]);
        }
        cout << "\t\t\t\tNANDing all the inputs....\n"
             << endl;

        cout << "\n\t\t\t\t+---------------+" << endl;
        cout << "\t\t\t\t|  OUTPUT = " << y << "   |" << endl;
        cout << "\t\t\t\t+---------------+" << endl;

        break;
    };
    case 5:
    {

        cout << "===============================================================================================================" << endl;

        if (i == 0)
        {
            cout << "\t\t\t\t\tNOR GATE" << endl;
            i++;
        }

        cout << "===============================================================================================================" << endl;

        cout << "Tell me the total numbers of operands : " << endl;
        int totOpe;
        cin >> totOpe;
        bool b[totOpe];

        for (int i = 0; i < totOpe; i++)
        {
            cout << "\t\t\t\tEnter input number " << i + 1 << " = ";
            cin >> b[i];
        }
        y = b[0];
        for (int i = 1; i < totOpe; i++)
        {
            y = ~(y | b[i]);
        }

        cout << "\t\t\t\tNORing all the inputs....\n"
             << endl;
        cout << "\n\t\t\t\t+---------------+" << endl;
        cout << "\t\t\t\t|  OUTPUT = " << y << "   |" << endl;
        cout << "\t\t\t\t+---------------+" << endl;

        break;
    };
    case 6:
    {

        cout << "===============================================================================================================" << endl;

        if (i == 0)
        {
            cout << "\t\t\t\t\tXOR GATE" << endl;
            i++;
        }

        cout << "===============================================================================================================" << endl;
        cout << "\t\t\t\tEnter input A = ";
        cin >> a;
        cout << "\t\t\t\tEnter input B = ";
        cin >> b;
        if (a > 1 || a < 0 || b > 1 || b < 0)
        {
            system("cls");
            logic(1);
        }

        else
        {
            cout << "\t\t\t\tX-ORing both the inputs....\n"
                 << endl;
            y = a ^ b;
            cout << "\n\t\t\t\t+-----------------+" << endl;
            cout << "\t\t\t\t| (A'B + AB') = " << y << " |" << endl;
            cout << "\t\t\t\t+-----------------+" << endl;
        }
        break;
    };
    case 7:
    {

        cout << "===============================================================================================================" << endl;

        if (i == 0)
        {
            cout << "\t\t\t\t\tXNOR GATE" << endl;
            i++;
        }

        cout << "===============================================================================================================" << endl;
        cout << "\t\t\t\tEnter input A = ";
        cin >> a;
        cout << "\t\t\t\tEnter input B = ";
        cin >> b;
        if (a > 1 || a < 0 || b > 1 || b < 0)
        {
            system("cls");
            logic(1);
        }

        else
        {
            cout << "\t\t\t\tX-NORing both the inputs....\n"
                 << endl;

            y = !(a ^ b);
            cout << "\n\t\t\t\t+-------------------+" << endl;
            cout << "\t\t\t\t|  (AB + A'B') = " << y << " |" << endl;
            cout << "\t\t\t\t+-------------------+" << endl;
        }
        break;
    };

    default:
        system("cls");
        main();
        break;
    }

    cout << "\t\t\t\tEnter 'b' for back , otherwise enter any letter:";
    cin >> B;
    if (B == 'b' || B == 'B')
    {
        system("cls");
        main();
    }
    else
    {
        logic(ch);
    }
}

int main()
{
    i = 0;
    int ch = Ui();
    logic(ch);

    return 0;
}
