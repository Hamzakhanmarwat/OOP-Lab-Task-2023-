#include <iostream>
#include <string>
using namespace std;

struct Login // Basic Login Data
{
    int id;
    string firstname;
    string secondname;
    string password;
};

struct SalePerson // Sale Person details + sales + total sales
{
    Login saleperson_information = {1, "sale", "person", "saleperson123"};
    double salebyQTR[4];
    double total_sales;
};

SalePerson salepersons[5];                    // Five sales person
Login admin = {1, "admin", "admin", "admin"}; // admin Login Details.

int main()
{

    void mainMenu();
    mainMenu();
}

void initializeSalePerson() // initailizing salepersons
{

    salepersons->saleperson_information.id = 0;
    salepersons->saleperson_information.firstname = "saleperson";
    salepersons->saleperson_information.secondname = "N/A";
    salepersons->saleperson_information.password = "saleperson123";
    for (int i = 0; i < 5; i++)
    {
        salepersons->salebyQTR[i] = 0.0;
    }
    salepersons->total_sales = 0.0;
}

void displayAllRecords() // Display All SalePerson Data
{

    void mainMenu();
    void adminMenu();
    cout << "\nNow displaying all records:" << endl;
    cout << "ID \t QTR1 \t QTR2 \t QTR3 \t QTR4 \t Total" << endl;
    cout << "_____________________________________________" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << salepersons[i].saleperson_information.id << " \t";
        for (int j = 0; j < 4; j++)
        {
            cout << salepersons[i].salebyQTR[j] << " \t";                         // this shows the the salepersons and the QTR
        }                                                                         //but needs to show total sales . (see in the PDF.).
        // cout<<salepersons.total_sales[i]<<" \t";
        cout << endl;
    }

    cout << "Press 1 for adminMenu" << endl;
    cout << "Press 0 for main menu" << endl;
    cout << "Your choice: ";

    int choice;
    cin >> choice;
    if (choice == 1)
        adminMenu();
    else if (choice == 0)
        mainMenu();
}

void displaySingleSalepersonRecord() // Display only a single Saleperson data
{

    void mainMenu();
    void adminMenu();

    cout << "\nNow displaying Single Saleperon record:" << endl;

    cout << "Press 1 for adminMenu" << endl;
    cout << "Press 0 for main menu (logout)" << endl;
    cout << "Your choice: ";

    int choice;
    cin >> choice;
    if (choice == 1)
        adminMenu();
    else if (choice == 0)
        mainMenu();
}

void addSalePerson() // Adding sale persons data in the program
{
    int choice, i = 0;
    cout << "Press 1 for Adding a New SalePerson" << endl;
    cout << "Press 0 for Exiting to the AdminMenu" << endl;
    cin >> choice;
    do
    {
        if (choice == 1) // 1 = yes
        {

            for (i = 0; i < 5; i++) // taking input
            {

                cout << "Enter first name  for [" << i + 1 << "]:" << endl;
                cin >> salepersons[i].saleperson_information.firstname;
                cout << "Enter last name for [" << i + 1 << "] :" << endl;
                cin >> salepersons[i].saleperson_information.secondname;
                cout << "Enter ID Number for [" << i + 1 << "] :" << endl;
                cin >> salepersons[i].saleperson_information.id;
                cout << "Enter Password for [" << i + 1 << "]:" << endl;
                cin >> salepersons[i].saleperson_information.password;
                for (int j = 0; j < 4; j++)
                {
                    cout << "Enter Sale QTR [" << j + 1 << "] :";
                    cin >> salepersons[i].salebyQTR[j];
                    salepersons[i].salebyQTR[j] += salepersons[i].total_sales;
                }
                cout << "do u want to add another SalePerson? : " << endl; // asking to enter another person's data
                cin >> choice;
                if (choice == 1) // yes
                {
                    addSalePerson(); // repeat the process.
                }
                else if (choice == 0) // no
                {
                    void mainMenu();
                }
            }
        }

    } while (choice != 0);

    if (choice == 0) // no.
    {
        void mainMenu();
    }
}

void adminMenu() // Menu For Admin use only
{

    void mainMenu();

    cout << "\nAdmin menu:" << endl;
    cout << "Press 1 for displaying the complete record" << endl;
    cout << "Press 2 for displaying the single saleperson record" << endl;
    cout << "Press 3 for Adding SalePerson's Data" << endl;
    cout << "Press 0 for main menu" << endl;
    cout << "Your choice: ";

    int choice;
    cin >> choice;
    if (choice == 1)
        displayAllRecords();
    else if (choice == 2)
        displaySingleSalepersonRecord();
    else if (choice == 3)
        addSalePerson();
    else if (choice == 0)
        mainMenu();
}

void salepersonMenu() // Menu for Saleperson only
{
    void UpdateQTR();
    void mainMenu();

    cout << "\nSalePerson Menu :" << endl;
    cout << "Press 1 for Update the salesByQtr" << endl;
    cout << "Press 2 for displaying the single saleperson record" << endl;
    cout << "Press 0 for main menu" << endl;
    cout << "Your choice: ";

    int choice;
    cin >> choice;
    if (choice == 1)
        UpdateQTR();
    else if (choice == 2)
        displaySingleSalepersonRecord();
    else if (choice == 0)
        mainMenu();
}

void UpdateQTR()
{
    int id ;
    cout<<"Enter Id No : "<<endl;
    cin>>id;
    for (int i = 0; i < 4; i++)
    {
        cout<<"QTR ["<<i+1<<"]"<<endl;
        cin>>salepersons[id].salebyQTR[i];
    }
    salepersonMenu();
        
    
}
void mainMenu() // The main menu
{
    bool AdminLogIN = false;
    bool SalePersonLogIn = false;
    cout << "Welcome to Sales Management System!!!\n"
         << endl;

    cout << "Please select from the following menu:" << endl;
    cout << "press 1 for admin mode" << endl;
    cout << "press 2 for saleperson mode" << endl;
    cout << "\nyour choice: ";

    int choice;
    cin >> choice;
    if (choice == 1)
    {
        if (!AdminLogIN)
        {
            string input_password_admin;
            cout << "Enter Password : " << endl;
            cin >> input_password_admin;
            if (input_password_admin == admin.password)
            {
                cout << "Login Successful!" << endl
                     << endl;
                adminMenu();
            }
            else
            {
                cout << "Login Failed!" << endl
                     << endl;
            }
        }
    }
    else if (choice == 2)
    {
        if (!SalePersonLogIn)
        {
            string input_password_saleperson;
            cout << "Enter Password : " << endl;
            cin >> input_password_saleperson;
            if (input_password_saleperson == salepersons->saleperson_information.password)
            {
                cout << "Login Successful!" << endl
                     << endl;
                salepersonMenu();
            }
            else
            {
                cout << "Login Failed!" << endl
                     << endl;
            }
        }
    }
}