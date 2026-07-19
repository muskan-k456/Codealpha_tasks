#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string name;
    int accountNo;
    float balance;

public:
    void createAccount()
    {
        cout << "Enter Account Number: ";
        cin >> accountNo;

        cout << "Enter Customer Name: ";
        cin >> name;

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit()
    {
        float amount;
        cout << "Enter Deposit Amount: ";
        cin >> amount;

        balance += amount;

        cout << "Deposit Successful!\n";
    }

    void withdraw()
    {
        float amount;

        cout << "Enter Withdrawal Amount: ";
        cin >> amount;

        if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
        }
    }

    void display()
    {
        cout << "\nAccount Number : " << accountNo << endl;
        cout << "Customer Name  : " << name << endl;
        cout << "Balance        : " << balance << endl;
    }

    void saveFile()
    {
        ofstream file("bank.txt");

        file << accountNo << endl;
        file << name << endl;
        file << balance << endl;

        file.close();
    }

    void loadFile()
    {
        ifstream file("bank.txt");

        if (file)
        {
            file >> accountNo;
            file >> name;
            file >> balance;
        }

        file.close();
    }
};

int main()
{
    BankAccount account;

    account.loadFile();

    int choice;

    do
    {
        cout << "\n===== Banking System =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Account\n";
        cout << "5. Save & Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            account.createAccount();
            break;

        case 2:
            account.deposit();
            break;

        case 3:
            account.withdraw();
            break;

        case 4:
            account.display();
            break;

        case 5:
            account.saveFile();
            cout << "Data Saved Successfully!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
