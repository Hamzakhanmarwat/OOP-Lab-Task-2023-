#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
    static int totalAccounts;
    int accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string holder = "N/A") : accountHolder(holder), balance(0) 
    {
        accountNumber = ++totalAccounts;
    }

    void deposit(double amount) 
    {
        balance += amount;
    }

    void withdraw(double amount) 
    {
        if (balance >= amount)
         {

            balance -= amount;
        }
        else
        {
            cout<<"Not enough balance!"<<endl;
        }
    }

    double getBalance() 
    {
        return balance;
    }

    int getAccountNumber() 
    {
        return accountNumber;
    }

    std::string getAccountHolder() 
    { // Added missing getter for accountHolder
        return accountHolder;
    }

    static int getTotalAccounts() 
    {
        return totalAccounts;
    }
};

int BankAccount::totalAccounts = 0;

class BankManager 
{
private:
    BankAccount* accounts;
    int numAccounts; // Added to keep track of the number of accounts

public:
    BankManager() : accounts(nullptr), numAccounts(0) {}

    ~BankManager() 
    {
        if (accounts != nullptr) 
        {
            delete[] accounts;
        }
    }

    void createAccount(std::string holder = "N/A") 
    {
        BankAccount* newAccounts = new BankAccount[numAccounts + 1];
        for (int i = 0; i < numAccounts; ++i) 
        {
            newAccounts[i] = accounts[i];
        }
        newAccounts[numAccounts] = BankAccount(holder);

        if (accounts != nullptr) 
        {
            delete[] accounts;
        }

        accounts = newAccounts;
        numAccounts++;
    }

    void deleteAccount(int accountNumber) 
    {
        int index = -1;
        for (int i = 0; i < numAccounts; ++i) 
        {
            if (accounts[i].getAccountNumber() == accountNumber) 
            {
                index = i;
                break;
            }
        }

        if (index != -1) {
            BankAccount* newAccounts = new BankAccount[numAccounts - 1];
            for (int i = 0, j = 0; i < numAccounts; ++i) 
            {
                if (i != index) 
                {
                    newAccounts[j++] = accounts[i];
                }
            }

            delete[] accounts;
            accounts = newAccounts;
            numAccounts--;
        }
    }

    BankAccount* findAccount(int accountNumber) 
    {
        for (int i = 0; i < numAccounts; ++i) 
        {
            if (accounts[i].getAccountNumber() == accountNumber) 
            {
                return &accounts[i];
            }
        }
        return nullptr; // Account not found
    }

    void displayAllAccounts() {
        for (int i = 0; i < numAccounts; ++i) 
        {
            cout << "Account Number: " << accounts[i].getAccountNumber() << endl;
            cout << "Account Holder: " << accounts[i].getAccountHolder() << endl;
            cout << "Balance: " << accounts[i].getBalance() <<endl;
            cout << "-------------------------" <<endl;
        }
    }
};

int main() {
    BankManager manager;
    manager.createAccount("Alice");
    manager.createAccount("Bob");

    BankAccount* account = manager.findAccount(5);
    if (account != nullptr) 
    {
        account->deposit(1000);
        account->withdraw(500);
    }

    manager.displayAllAccounts();

    manager.deleteAccount(2);
    cout << "After deleting account:" << std::endl;
    manager.displayAllAccounts();

    return 0;
}
