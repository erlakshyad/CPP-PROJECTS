#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <cstdio>

using namespace std;
void page1();
void UI_frontPage();
void UI_login();
void UI_SignUp();
void UI_Attendance();
void UI_Menu();
void UI_Menu();
void UI_SignUp();

void ReplaceWord(const string &filename, const string Date, const string oldword, const string newword, int LineWords);
void Record_Employee(int opt);
void Save_UN_N_PW(string username, string password1);
void Check_Menu(int opt);
void CheckPage(int opt);
void Check_Attendance(int opt);
bool CheckLogin(string un, string pw);
void DeleteRecord(const string filename, const string id);

int main()
{
    page1();

    return 0;
}

void page1(){
    do{
    cout << "\t\t\t\t*****************************************************************************************************"<<endl;
    cout << "\t\t\t\t                                   WELCOME TO AN EMPLOYEE MANAGEMENT SYSTEM APPLICATION!!"<<endl;
    cout << "\t\t\t\t\t\t\t\t\t-made by LAKSHYA DHAKARE"<<endl;
    cout << "\t\t\t\t*****************************************************************************************************"<<endl;
    cout << "\t\t\t\tEnter 'p' to proceed ";
    char ch;
    cin >> ch;
    if(ch == 'p'||ch == 'P'){
        system("cls");UI_frontPage();
    }
    system("cls");
}while(1);
}

void UI_frontPage()
{
    int opt;
    bool correct;
    do
    {
        cout << "\n\t\t\t\t**************************************************************************************" << endl;
        cout << "\t\t\t\t\t\tLAKSHYA DHAKARE's E.M.S.APPLICATION" << endl;
        cout << "\t\t\t\t_________________________________" << endl;
        cout << "\t\t\t\t\t1.Login" << endl;
        cout << "\t\t\t\t---------------------------------" << endl;
        cout << "\t\t\t\t\t2.Sign up" << endl;
        cout << "\n\t\t\t\t**************************************************************************************" << endl;
        cout << "\n\t\t\t\t Enter an option : ";
        cin >> opt;
        if (opt == 1 || opt == 2)
        {
            CheckPage(opt);
            system("cls");
            correct = false;
        }
        else
        {
            correct = true;
            system("cls");
        }
    } while (correct);
}

void UI_Menu()
{
    system("cls");
    int opt;
    bool correct = true;
    while (correct)
    {

        cout << "\n\t\t\t\t**************************************************************************************" << endl;
        cout << "  \t\t\t\t                                       MENU                                           " << endl;
        cout << "\n\t\t\t\t**************************************************************************************" << endl;
        cout << "\t\t\t\t\t1. Register New Employee" << endl;
        cout << "\t\t\t\t\t2. Delete a record of an employee" << endl;
        cout << "\t\t\t\t\t3. Display all employee record" << endl;
        cout << "\t\t\t\t\t4. Attendance" << endl;
        cout << "\t\t\t\t\t5. Search a record of an employee" << endl;
        cout << "\t\t\t\t\t6. Modify record of an employee" << endl;
        cout << "\t\t\t\t\t7. Exit the program" << endl;
        cout << "\t\t\t\t\t8. Back" << endl;

        cout << "Enter an option : ";
        cin >> opt;

        if (!(opt > 8 || opt < 1))
        {
            Check_Menu(opt);
            correct = false;
        }

        else
        {
            correct = true;
            system("cls");
        }
    }
}

// modifications have to be done below
void UI_login()
{
    string username, password;
    bool correct = true;
    while (correct)
    {
        system("cls");
        cout << "\n\t\t\t\t**************************************************************************************" << endl;
        cout << "\t\t\t\t                                    LOGIN:                                              " << endl;
        getline(cin, username);
        cout << "\t\t\t\t________________________________________________________________________________________" << endl;
        cout << "\t\t\t\tUserName : ";
        getline(cin, username);
        cout << "\t\t\t\t----------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\tPassword : ";
        getline(cin, password);
        cout << "\n\t\t\t\t**************************************************************************************" << endl;

        correct = CheckLogin(username, password);

        if (correct)
        {
            cout << "\t\t\t\tLogin Successful++" << endl;

            Sleep(2000);
            system("cls");
            UI_Menu();
            break;
        }
        else
        {
            cout << "\t\t\t\tLogin Unsuccessful--" << endl;
            cout << "\t\t\t\tEnter the correct username and password........" << endl;
            cout << "\t\t\t\tPress ENTER (only for once) to try again ...." << endl;
            Sleep(4000);

            correct = true;
        }
    }
}

void UI_SignUp()
{
    string username, password1, password2;
    bool correct = true;
    while (correct)
    {
        system("cls");
        cout << "\n\t\t\t\t**************************************************************************************" << endl;
        cout << "\t\t\t\t                                    SIGN UP:                                              " << endl;
        getline(cin, username);
        cout << "\t\t\t\t________________________________________________________________________________________" << endl;
        cout << "\t\t\t\tUserName : ";
        getline(cin, username);
        cout << "\t\t\t\t----------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\tPassword : ";
        getline(cin, password1);
        cout << "\t\t\t\t----------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\tConfirm Password : ";
        getline(cin, password2);
        cout << "\n\t\t\t\t**************************************************************************************" << endl;

        if (password1 == password2)
        {
            cout << "\t\t\t\tSign up Successful++" << endl;
            Sleep(2000);
            system("cls");
            Save_UN_N_PW(username, password1);
            UI_Menu();
            correct = false;
        }

        else
        {
            cout << "\t\t\t\tSign up Unsuccessful--" << endl;
            cout << "\t\t\t\tERROR : password........" << endl;
            cout << "\t\t\t\tPress ENTER (only for once) to try again ...." << endl;
            Sleep(4000);

            correct = true;
        }
    }
}

void UI_Attendance()
{
    int opt;
    bool correct;
    do
    {
        cout << "\n\t\t\t\t**************************************************************************************" << endl;
        cout << "  \t\t\t\t                                       MENU                                           " << endl;
        cout << "\n\t\t\t\t**************************************************************************************" << endl;
        cout << "\t\t\t\t\t1.Take Attendance" << endl;
        cout << "\t\t\t\t\t2.Search for attendance" << endl;
        cout << "\t\t\t\t\t3.Modify attendance" << endl;
        cout << "\t\t\t\t\t4.Display whole attendance" << endl;
        cout << "\t\t\t\t\t5.Display attendance of an employee" << endl;
        cout << "\t\t\t\t\t6.Back" << endl;

        cout << "\n\n\t\t\t\tEnter an option : ";
        cin >> opt;
        if (opt == 1 || opt == 2 || opt == 3 || opt == 4 || opt == 5 || opt == 6)
        {
            system("cls");
            Check_Attendance(opt);
            correct = false;
        }
        else
        {
            system("cls");
            correct = true;
        }
    } while (correct);
}

bool CheckLogin(string un, string pw)
{
    bool found = false;
    string un1, pw1;
    int unLineNo = 0;
    streampos posn;
    ifstream emplo("Login.txt");

    if (!emplo)
    {
        cerr << "Sign up, first...." << endl;
    }

    while (getline(emplo, un1) && getline(emplo, pw1))
    {
        unLineNo++;
        if (un1.find(un) != string::npos && pw1.find(pw) != string::npos)
        {
            found = true;
        }
    }

    return found;
}

void Check_Menu(int opt)
{
    switch (opt)
    {
    case 1:
    case 2:
    case 3:
        system("cls");
        Record_Employee(opt);
        break;
    case 4:
        system("cls");
        UI_Attendance();
        break;
    case 5:
        system("cls");
        Record_Employee(opt);
        break;
    case 6:
        system("cls");
        Record_Employee(opt);
        break;
    case 7:
        system("cls");
        exit(0);
        break;
    case 8:
        system("cls");
        UI_frontPage();
        break;

    default:
        UI_Menu();
    }
}

void CheckPage(int opt)
{
    switch (opt)
    {
    case 1:
        UI_login();
        break;
    case 2:
        UI_SignUp();
        break;

    default:
        UI_frontPage();
        break;
    }
}

void Check_Attendance(int opt)
{

    switch (opt)
    {
    case 1:
    {
        bool correct;
        ifstream emp("Employee.txt");

        ofstream Emp("EmpAttendance.txt", ios::app);
        string line, name, id, date;
        char pa;
        do
        {
            emp.clear();
            emp.seekg(0);
            cout << "\t\t\t\t=========================================================================================================" << endl;
            cout << "\t\t\t\tUserID \t" << "Date      \t" << "Present(p)/Absent(a)\t(Enter 'e' to exit)" << endl;
            cout << "\t\t\t\t=========================================================================================================" << endl;
            cout << "\t\t\t\tEnter Date (DD/MM/YYYY) : ";
            cin >> date;
            cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;

            while (getline(emp, line))
            {
                stringstream ss(line);
                ss >> line >> name >> id;
                cout << id << "\t" << date << "\t" << "Enter p or a or e : ";
                cin >> pa;

                if (pa == 'p' || pa == 'P')
                {
                    Emp << id << "\t\t" << date << "\t" << "Present" << endl;
                }
                else if (pa == 'a' || pa == 'P')
                {
                    Emp << id << "\t\t" << date << "\t" << "Absent" << endl;
                }
                else if (pa == 'e' || pa == 'P')
                {
                    system("cls");
                    UI_Attendance();
                }
            }
            cout << "\t\t\t\tEnter e to exit or enter any other letter to enter the new attendace record : ";
            cin >> pa;
            if (pa == 'e' || pa == 'P')
            {
                system("cls");
                UI_Attendance();
            }
            else
            {
                system("cls");
                correct = true;
            }
        } while (correct);

        system("cls");
        emp.close();
        Emp.close();
        break;
    }
        /****************************************************************************************************************/
    case 2:
    {
        bool correct = true;
        system("cls");
        cout << "\t\t\t\t=========================================================================================================" << endl;
        cout << "\t\t\t\t                                 SEARCH ATTENDANCE                                                       " << endl;
        cout << "\t\t\t\t=========================================================================================================" << endl;
        do
        {

            string id, id1, line;
            int check = 0;
            cout << "\t\t\t\t_________________________________________________________________________________________________________" << endl;
            cout << "\n\t\t\t\tEnter the userID : ";
            cin >> id;
            cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;
            ifstream emp("EmpAttendance.txt");

            while (getline(emp, line))
            {
                stringstream ss(line);
                ss >> id1;
                if (id == id1)
                {
                    cout << line << endl;
                    check--;
                }
            }
            if (check == 0)
            {
                cout << "\t\t\t\tThe attendance record of the employee having ID " << id << " is \n\t\t\t\t NOT FOUND" << endl;
            }

            cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\tEnter '1' to back \nor\n Enter any number to search another employee's attendance : ";
            cin >> check;
            if (check == 1)
            {
                system("cls");
                UI_Attendance();
            }

            emp.close();
        } while (correct);
        system("cls");
        break;
    }

        /****************************************************************************************************************/
    case 3:
    {
        string id, pa, Date;
        char PA;
        char e;

        while (true)
        {

            cout << "\t\t\t\t=========================================================================================================" << endl;
            cout << "\t\t\t\t                                      MODIFY ATTENDANCE                                                  " << endl;
            cout << "\t\t\t\t=========================================================================================================" << endl;
            cout << "\n\t\t\t\tEnter e to exit or any other letter to continue : ";
            cin >> e;
            if (e == 'e' || e == 'E')
            {
                system("cls");
                UI_Attendance();
            }
            cout << "\t\t\t\tEnter ID of the employee : ";
            cin >> id;
            cout << "\t\t\t\tEnter the date (DD/MM/YYYY) (E.g. 01/03/2025) : ";
            cin >> Date;
            cout << "\t\t\t\tEnter 'p' for present or 'a' for absent : ";
            cin >> PA;
            if (PA == 'p' || PA == 'P')
            {
                pa = "Present";
            }
            else if (PA == 'a' || PA == 'A')
            {
                pa = "Absent";
            }

            else
            {
                system("cls");
                continue;
            }

            ReplaceWord("EmpAttendance.txt", Date, id, pa, 3);

            system("cls");
        }
        break;
    }

        /****************************************************************************************************************/
    case 4:
    {
        system("cls");
        ifstream emp("EmpAttendance.txt");
        string wholeAtt;
        char ch;
        cout << "=========================================================================================================" << endl;
        cout << "ID\t\t" << "DATE\t" << "Present/Absent" << endl;
        cout << "=========================================================================================================" << endl;
        while (!emp.eof())
        {
            emp.get(ch);
            wholeAtt += ch;
        }
        cout << "\t\t\t\t_________________________________________________________________________________________________________" << endl;
        cout << wholeAtt << endl;
        cout << "\t\t\t\tEnter any letter e.g. 'e' for back : ";
        cin >> ch;
        emp.close();
        system("cls");
        UI_Attendance();
    }
    break;

        /****************************************************************************************************************/
    case 5:
    {
        bool correct = true;
        system("cls");
        cout << "\t\t\t\t=========================================================================================================" << endl;
        cout << "\t\t\t\t                                 DISPLAY ATTENDANCE OF AN EMPLOYEE                                                       " << endl;
        cout << "\t\t\t\t=========================================================================================================" << endl;
        do
        {

            string id, id1, line;
            int check = 0;
            cout << "\t\t\t\t_________________________________________________________________________________________________________" << endl;
            cout << "\n\t\t\t\tEnter the userID : ";
            cin >> id;
            cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;
            ifstream emp("EmpAttendance.txt");

            while (getline(emp, line))
            {
                stringstream ss(line);
                ss >> id1;
                if (id == id1)
                {
                    cout << line << endl;
                    check--;
                }
            }
            if (check == 0)
            {
                cout << "\t\t\t\tThe attendance record of the employee having ID " << id << " is \n\t\t\t\t NOT FOUND" << endl;
            }

            cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\tEnter '1' to back \nor\n Enter any number to search another employee's attendance : ";
            cin >> check;
            if (check == 1)
            {
                system("cls");
                UI_Attendance();
            }

            emp.close();
        } while (correct);
        system("cls");
        break;
    }
        system("cls");
        break;

        /****************************************************************************************************************/
    case 6:
        system("cls");
        UI_Menu();
        break;

        /****************************************************************************************************************/

    default:
        UI_Attendance();
    }
}

void Record_Employee(int opt)
{
    switch (opt)
    {
    case 1:
    {
        string name, id, role, sector, mo_no, email;
        system("cls");
        bool correct;
        do
        {
            cout << "\t\t\t\t=========================================================================================================" << endl;
            cout << "\t\t\t\tFormat : " << endl;
            cout << "\t\t\t\t69  WANKHADE_SUJAL      24CM069     COMPUTER_ENGINEER   IT  9600345628  WANKHADE_SUJAL@gmail.com" << endl;

            cout << "\t\t\t\tEnter employee's name : ";
            cin >> name;
            cout << "\t\t\t\tEnter employee's id : ";
            cin >> id;
            cout << "\t\t\t\tEnter employee's role : ";
            cin >> role;
            cout << "\t\t\t\tEnter employee's sector : ";
            cin >> sector;
            cout << "\t\t\t\tEnter employee's mobile number : ";
            cin >> mo_no;
            cout << "\t\t\t\tEnter employee's email : ";
            cin >> email;

            ofstream Emp("Employee.txt", ios::app);
            Emp << setw(19) << name << " " << id << "\t\t" << role << "\t" << sector << "\t" << mo_no << "\t" << email << endl;

            cout << "\t\t\t\t-----------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t"<< name << "'s record saved successfully." << endl;
            cout << "\t\t\t\t-----------------------------------------------------------------------------------------------------------" << endl;

            cout << "\t\t\t\tEnter any letter except 'b' to add another employee record  " << endl;
            char inp2;
            cout << "\t\t\t\tEnter 'b' to back : ";
            cin >> inp2;

            if (inp2 == 'b')
            {
                correct = false;
                system("cls");
                UI_Menu();
            }
            else
            {
                correct = true;
            }

        } while (correct);
        break;
    }
        /****************************************************************************************************************/

    case 2:
    {
        do
        {
            system("cls");
            cout << "\t\t\t\t=========================================================================================================" << endl;
            cout << "\t\t\t\t                                           DELETE A RECORD OF AN EMPLOYEE                                " << endl;
            cout << "\t\t\t\t=========================================================================================================" << endl;
            cout << "\n\t\t\t\tEnter the id of the employee to delete its record :\n\t\t\t\t\t\t OR \n\t\t\t\tEnter 'b' for back : ";
            string id;
            cin >> id;
            if (id == "b")
            {
                system("cls");
                UI_Menu();
            }
            DeleteRecord("Employee.txt", id);

        } while (true);

        break;
    }
        /****************************************************************************************************************/

    case 3:
    {
        ifstream emp("Employee.txt");
        string employeeRecord;
        char Emp;
        while (!emp.eof())
        {
            emp.get(Emp);
            employeeRecord += Emp;
        }

        cout << "===============================================================================================================" << endl;
        cout << setw(15) << "|Employee_Name" << " |EmpID\t\t" << "|Role\t\t" << "|Sector\t" << "|Mobile no.|\t\t" << "Email add.|" << endl;
        cout << "===============================================================================================================" << endl;
        cout << employeeRecord << endl;
        cout << "===============================================================================================================" << endl;
        cout << "Enter '0' for Back" << endl;
        int inp;
        cin >> inp;
        if (inp == 0)
        {
            system("cls");
            UI_Menu();
        }
        emp.close();
        break;
    }
        /****************************************************************************************************************/

    case 5:
    {
        bool correct = true;
        string line, name, id, id1;
        cout << "\t\t\t\t=========================================================================================================" << endl;
        cout << "\t\t\t\t                                 SEARCH RECORD OF AN EMPLOYEE                                            " << endl;
        cout << "\t\t\t\t=========================================================================================================" << endl;
        cout << "\t\t\t\t|Employee Name    |ID    \t|Role\t|Sector\t|Mobile number\t|Email|" << endl;

        do
        {

            cout << "\t\t\t\t_________________________________________________________________________________________________________" << endl;
            cout << "\t\t\t\tEnter the ID of the employee : ";
            cin >> id1;
            cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;
            ifstream emp("Employee.txt");
            int check = 0;

            while (getline(emp, line))
            {
                stringstream ss(line);
                ss >> name >> id;
                if (id == id1)
                {
                    cout << line << endl;
                    check--;
                }
            }

            if (check == 0)
            {
                cout << "\t\t\t\tThe record of the employee having id " << id1 << " is\n\t\t\t\tNOT FOUND" << endl;
            }
            cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\tEnter the any letter except 'b' to search another employee's record \nEnter 'b' for back : ";
            char ch;
            cin >> ch;
            if (ch == 'b')
            {
                system("cls");
                UI_Menu();
            }
            else
            {
                correct = true;
            }

        } while (correct);
        break;
    }
        /****************************************************************************************************************/

    case 6:
    {
        do
        {
            system("cls");
            cout << "\t\t\t\t=========================================================================================================" << endl;
            cout << "\t\t\t\t                                            MODIFY ATTENDANCE                                            " << endl;
            cout << "\t\t\t\t=========================================================================================================" << endl;
            cout << "\t\t\t\tEnter the ID to search the employee record : ";
            string line, id0;
            string name, id, role, sector, MoNo, email;
            cin >> id0;
            cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;
            ifstream emp("Employee.txt");
            int check = 0;

            while (getline(emp, line))
            {
                stringstream ss(line);
                ss >> name >> id >> role >> sector >> MoNo >> email;
                if (id == id0)
                {
                    cout << "\t\t\t\t" << line << endl;
                    check--;
                    break;
                }
            }

            if (check == 0)
            {
                cout << "\n\t\t\t\tThe record of the employee having id " << id << " is\n\t\t\t\tNOT FOUND" << endl;
            }
            cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;
            emp.close();
            cout << "\t\t\t\t" << endl;
            cout << "\n\t\t\t\tEnter the id of the Employee and the select to change -" << endl;
            cout << "\n\t\t\t\t1.Name" << endl;
            cout << "\n\t\t\t\t2.ID" << endl;
            cout << "\n\t\t\t\t3.Role" << endl;
            cout << "\n\t\t\t\t4.Sector" << endl;
            cout << "\n\t\t\t\t5.Mobile Number" << endl;
            cout << "\n\t\t\t\t6.Email Address" << endl;
            cout << "\n\t\t\t\t7.Back"<<endl;
            cout << "\n\t\t\t\tEnter the option : ";

            int optn;
            cin >> optn;

            switch (optn)
            {
            case 1:
            {
                system("cls");
                cout << "\t\t\t\t=========================================================================================================\n"
                     << endl;
                string name1;
                cout << "\t\t\t\tEnter the correct name : ";
                cin >> name1;
                cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;

                ReplaceWord("Employee.txt", id, name, name1, 6);
                system("cls");
                break;
            };
            case 2:
            {
                system("cls");
                cout << "\t\t\t\t=========================================================================================================\n"
                     << endl;
                string id1;
                cout << "\t\t\t\tEnter the correct id : ";
                cin >> id1;
                cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;

                ReplaceWord("Employee.txt", id, id, id1, 6);
                system("cls");
                break;
            };
            case 3:
            {
                system("cls");
                cout << "\t\t\t\t=========================================================================================================\n"
                     << endl;
                string role1;
                cout << "\t\t\t\tEnter the correct role : ";
                cin >> role1;
                cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;

                ReplaceWord("Employee.txt", id, role, role1, 6);
                system("cls");
                break;
            };
            case 4:
            {
                system("cls");
                cout << "\t\t\t\t=========================================================================================================\n"
                     << endl;
                string sector1;
                cout << "\t\t\t\tEnter the correct sector : ";
                cin >> sector1;
                cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;

                ReplaceWord("Employee.txt", id, sector, sector1, 6);
                system("cls");
                break;
            };
            case 5:
            {
                system("cls");
                cout << "\t\t\t\t=========================================================================================================\n"
                     << endl;
                string MoNo1;
                cout << "\t\t\t\tEnter the correct MoNo : ";
                cin >> MoNo1;
                cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;

                ReplaceWord("Employee.txt", id, MoNo, MoNo1, 6);
                system("cls");
                break;
            };
            case 6:
            {
                system("cls");
                cout << "\t\t\t\t=========================================================================================================\n"
                     << endl;
                string email1;
                cout << "\t\t\t\tEnter the correct email : ";
                cin >> email1;
                cout << "\t\t\t\t---------------------------------------------------------------------------------------------------------" << endl;

                ReplaceWord("Employee.txt", id, email, email1, 6);
                system("cls");
                break;
            };

            case 7 : UI_Menu(); break;
            default:
                break;
            }

        } while (true);

        break;
    }
        /****************************************************************************************************************/

    default:
        system("cls");
        UI_Menu();
    }
}

void Save_UN_N_PW(string username, string password1)
{

    ofstream emp("Login.txt", ios::app); // Open in append mode

    if (!emp)
    {
        perror("Error opening file");
        cerr << "\t\t\t\tERROR: Could not create or open 'Login.txt'." << endl;
        return;
    }

    emp << username << "\n"
        << password1 << endl;
    emp.close();
}

void ReplaceWord(const string &filename, const string Date, const string oldword, const string newword, int LineWords)
{ // E.g.Arguements => ("Employee.txt", id, MoNo, MoNo1, 6     )
    ifstream emp(filename);
    string tempfile = "tempFile.txt";
    ofstream Emp(tempfile, ios ::out);

    int i;
    bool check = false;
    string data;
    string line;
    string word[LineWords];
    while (getline(emp, line))
    {
        stringstream ss(line);
        for (i = 0; i < LineWords; i++)
        {
            ss >> word[i];
            if (LineWords == 3)
            {
                if (word[i - 2] == oldword && word[i - 1] == Date)
                {
                    word[i] = newword;
                    check = true;
                }
            }

            if (LineWords == 6)
            {
                if (word[i] == oldword && word[1] == Date)
                {
                    word[i] = newword;
                    check = true;
                }
                // CODE....
            }
        }
        if (LineWords == 3)
        {

            Emp << word[0] << "\t\t" << word[1] << '\t' << word[2] << endl;
        }
        if (LineWords == 6)
        {
            Emp << word[0] << "\t"
                << word[1] << "\t\t"
                << word[2] << "\t"
                << word[3] << "\t"
                << word[4] << "\t"
                << word[5]
                << endl;
        }

        data += line + '\n';
    }

    if (!check)
    {
        cout << "**************************************You have entered a wrong date or a wrong id**************************************" << endl;
        Sleep(2500);
        system("cls");
        Check_Attendance(3);
    }
    emp.close();
    Emp.close();

    remove(filename.c_str());

    rename(tempfile.c_str(), filename.c_str());

    // cout <<data;
    // ofstream emp(tempfile, ios :: out);
}

void DeleteRecord(const string filename, const string id)
{
    ifstream emp(filename);
    string tempfile = "tempfile.txt";
    ofstream Emp(tempfile, ios ::out);
    string line;
    bool check = false;
    string word[6];
    while (getline(emp, line))
    {
        stringstream ss(line);
        for (int i = 0; i < 6; i++)
        {
            ss >> word[i];
        }
        if (word[1] == id)
        {
            check = true;
            continue;
        }

        Emp << word[0] << "\t"
            << word[1] << "\t\t"
            << word[2] << "\t"
            << word[3] << "\t"
            << word[4] << "\t"
            << word[5]
            << endl;
    }

    if (!check)
    {
        cout << "\n\t\t\t\t******************************** You have entered a wrong id *********************************" << endl;
    }
    else
    {
        cout << "\t\t\t\t\t\t\tDELETED...." << endl;
    }
    Sleep(2000);
    emp.close();
    Emp.close();

    remove(filename.c_str());
    rename(tempfile.c_str(), filename.c_str());
}