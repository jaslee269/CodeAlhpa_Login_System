
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Registration Function
void registerUser()
{
    string username, password;
    string u, p;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Validate input
    if(username.empty() || password.empty())
    {
        cout << "Username and password cannot be empty!\n";
        return;
    }

    if(password.length() < 6)
    {
        cout << "Password must contain at least 6 characters!\n";
        return;
    }

    // Check duplicate username
    ifstream file("users.txt");

    while(file >> u >> p)
    {
        if(u == username)
        {
            cout << "Username already exists!\n";
            file.close();
            return;
        }
    }

    file.close();

    // Store user details
    ofstream outfile("users.txt", ios::app);

    if(!outfile)
    {
        cout << "Error opening file!\n";
        return;
    }

    outfile << username << " " << password << endl;

    outfile.close();

    cout << "\nRegistration Successful!\n";
}

// Login Function
void loginUser()
{
    string username, password;
    string u, p;
    bool found = false;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Read user details from file
    ifstream file("users.txt");

    if(!file)
    {
        cout << "No registered users found!\n";
        return;
    }

    while(file >> u >> p)
    {
        if(u == username && p == password)
        {
            found = true;
            break;
        }
    }

    file.close();

    if(found)
    {
        cout << "\nLogin Successful! Welcome " << username << "!\n";
    }
    else
    {
        cout << "\nInvalid Username or Password!\n";
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== LOGIN AND REGISTRATION SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while(choice != 3);

    return 0;
}
