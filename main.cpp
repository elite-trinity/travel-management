#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;
void menu(); // main menu function prototype

class ManageMenu
{
protected:
    string userName; // hide admin name

public:
    // virtual void menu(){}

    ManageMenu()
    {
        int choice;
        system("color 0A"); // change terminal color
        cout << "\t\t\t 1.Admin Login: " << endl;
        cout << "\t\t\t 2.User Login: " << endl;
        cout << "Your Choice(1/2): " << endl;
        cin >> choice;
        if (choice == 1)
        {
        }
        else if (choice == 2)
        {
            system("CLS");
            menu();
        }
        else
        {
            cout << "Please Enter A Valid Input !!" << endl;
            Sleep(100);
            ManageMenu startObj;
        }

        // menu(); //377 //call to main function to load after executing the constructr
    }

    ~ManageMenu() {} // de
};

class Customer
{
public:
    string name, gender, address;
    long int age, mobileNo, menuBack;
    static int UID;
    char all[999];

    void getDetails()
    {
        ofstream out("Registered_Users.txt", ios::app);
        {
            cout << "\nEnter User ID: ";
            cin >> UID;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Mobile Number: ";
            cin >> mobileNo;
            cout << "Address: ";
            cin >> address;
            cout << "Gender: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << UID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();
        cout << "\nSaved \nNOTE: We save your details record for future purposes.\n"
             << endl;
    }
    void showDetails()
    {
        ifstream in("Registered_Users.txt");
        {
            if (!in)
            {
                cout << "File Error!" << endl;
            }
            while (!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
};

int Customer::UID;
void menu() // menu function contain main menu
{

    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t      * Elite Smart Travels *\n"
         << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    
    cout << "\t|\tAdd Personal Details           -> 1\t|" << endl;
    cout << "\t|\tEnter Source and Destination   -> 2\t|" << endl;
    cout << "\t|\tMode of Transports             -> 3\t|" << endl;
    cout << "\t|\tView Reciept                   -> 4\t|" << endl;
    cout << "\t|\tExit                           -> 5\t|" << endl;

    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customer a2; // creating objects
    if (mainChoice == 1)
    {
        cout << "------Customers------\n"
             << endl;
        cout << "1. Enter New Customer" << endl;
        cout << "2. See Old Customers" << endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        if (inChoice == 1)
        {
            a2.getDetails();
        }
        else if (inChoice == 2)
        {
            a2.showDetails();
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
    else if (mainChoice == 2)
    {
        int s, d;
        cout << "Enter Source" << endl;
        cout << "1.Pune" << endl;
        cout << "2.Mumbai" << endl;
        cout << "3.Delhi" << endl;
        cin >> s;
        cout << "Enter Destination" << endl;
        cout << "1.Pune" << endl;
        cout << "2.Mumbai" << endl;
        cout << "3.Delhi" << endl;
        cin >> d;
    }

    else if (mainChoice == 3)
    {
        int m;
        cout << "Enter the mode of Transport" << endl;
        cout << "1.Flight" << endl;
        cout << "2.Bus" << endl;
        cout << "3.Train" << endl;
        cin >> m;
    }

    else if (mainChoice == 4)
    {
    }
    
else if (mainChoice == 5)
{
    cout << "\n\n\t--GOOD-BYE!--" << endl;
    Sleep(1100);
    system("CLS");
    ManageMenu();
}
else
{
    cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
    Sleep(1100);
    system("CLS");
    menu();
}
}

int main()
{
    ManageMenu startObj;
    return 0;
}
