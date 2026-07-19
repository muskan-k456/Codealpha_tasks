#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool userExists(string username)
{
    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass)
    {
        if (user == username)
        {
            return true;
        }
    }
    return false;
}

void registerUser()
{
    string username, password;

    cout << "\nEnter Username: ";
    cin >> username;

    if (userExists(username))
    {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;

    cout << "Registration Successful!\n";
}

void loginUser()
{
    string username, password;
    string user, pass;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> user >> pass)
    {
        if (user == username && pass == password)
        {
            cout << "Login Successful!\n";
            return;
        }
    }

    cout << "Invalid Username or Password!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Login System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}