// Main class to run the std in loop that will take the user inputs
#include <iostream>
#include <string>
#include "Authentication.h"
#include "User.h"
using namespace std;

int main() 
{
    string transaction;
    User currentUser;
    while(transaction != "Exit") 
    {
        cout << "Enter a transaction: " << endl;
        cin >> transaction;
        if(transaction.compare("Login") == 0) 
        {
            Authentication auth;
            currentUser = auth.login();
        }
    }

    return 0;

}
