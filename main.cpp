/*
Date: 2020-02-17

Description: This program is made to be an auction service. Users
can make accounts based on their intentions(Buy/sell). Then users
can put items up for sale and other users can bid on them. Other
functions of this service are refunds and adding credit to the
program.

//Input Files:
currentUsers.txt
dailyTransactionFile.txt
avalibleItems.txt

//Output Files:
currentUsers.txt
dailyTransactionFile.txt
avalibleItems.txt

Running this program
    Run the commands:
     make
     ./auction
*/
// Main class to run the std in loop that will take the user inputs
#include <iostream>
#include <string>
#include "./Authentication/Authentication.h"
#include "./Users/User.h"
#include "./Users/BuyStandard/BuyStandard.h"
#include "./Users/SellStandard/SellStandard.h"
#include "./Users/FullStandard/FullStandard.h"
#include "./Users/Admin/Admin.h"

using namespace std;

void state0();
void state2Buy(string username);
void state2Sell(string username);
void state2Full(string username);
void state2Admin(string username);

// Inputs: None
// Outputs: Int
int main()
{
    state0();
    return 0;
}

//States:
//State 0 = Logged out
//State 1 = Exit state
//State 2 = Logged in state
// Inputs: None
// Outputs: None
void state0()
{
    int transaction;
    string username;
    int accntType;
    bool loop = true;

    while (loop)
    {
        //Ouput to user
        cout << "Welcome to the auction website. Please select an option from the following:" << endl;
        cout << "Login -- 1" << endl;
        cout << "Exit -- 0" << endl;
        cout << "-->";

        //Take in user input
        cin >> transaction;

        //Make choice based on user input
        switch (transaction)
        {
        //Exit is chosen
        case 0: loop = false;
            break;

         //Login was chosen
        case 1:
            Authentication auth;//Create instance of authentication class
            cout << "Enter Username: ";
            cin >> username;
            accntType = auth.login(username);//Call login function

            switch (accntType)
            {
            case 0:
                break;
            case 1:
                state2Buy(username);
                break;
            case 2:
                state2Sell(username);
                break;
            case 3:
                state2Full(username);
                break;
            case 4:
                state2Admin(username);
                break;
            default:
                break;
            }

            break;

            //Default case
            default:
                break;
        }
    }
}


// Inputs: String username for initalizing type of account
// Outputs: None
void state2Buy(string username)
{
    BuyStandard user(username, 0);
    int transaction;
    bool loop = true;
    while (loop)
    {
        //Output to user
        cout << "Account Type: Buy Standard" << endl;
        cout << "Please choose from one of the following options:" << endl;
        cout << "Logout -- 1 " << endl;
        cout << "Refund -- 2 " << endl;
        cout << "Add credit -- 3 " << endl;
        cout << "Bid -- 4 " << endl;
        cout << "-->";

        //Take user input
        cin >> transaction;

        //Make choice based on user input
        switch (transaction)
        {
        case 1:  loop = false;
            break;
        }
    }
}

// Inputs: String username for initalizing type of account
// Outputs: None
void state2Sell(string username)
{
    SellStandard user(username, 0);
    int transaction;
    bool loop = true;
    while (loop)
    {
        //Output to user
        cout << "Account Type: Sell Standard" << endl;
        cout << "Please choose from one of the following options:" << endl;
        cout << "Logout -- 1 " << endl;
        cout << "Refund -- 2 " << endl;
        cout << "Add Credit -- 3 " << endl;
        cout << "Advertise -- 4 " << endl;
        cout << "-->";

        //Take user input
        cin >> transaction;

        //Make choice based on user input
        switch (transaction)
        {
        case 1:  loop = false;
            break;
        }
    }
}

// Inputs: String username for initalizing type of account
// Outputs: None
void state2Full(string username)
{
    FullStandard user(username, 0);
    int transaction;
    bool loop = true;
    while (loop)
    {
        //Output to user
        cout << "Account Type: Full Standard" << endl;
        cout << "Please choose from one of the following options:" << endl;
        cout << "Logout -- 1 " << endl;
        cout << "Refund -- 2 " << endl;
        cout << "Add Credit -- 3 " << endl;
        cout << "Bid -- 4 " << endl;
        cout << "Advertise -- 5 " << endl;
        cout << "-->";

        //Take user input
        cin >> transaction;

        //Make choice based on user input
        switch (transaction)
        {
        case 1:  loop = false;
            break;
        }
    }
}

// Inputs: String username for initalizing type of account
// Outputs: None
void state2Admin(string username)
{
    Admin user(username, 0);
    int transaction;
    bool loop = true;
    while (loop)
    {
        //Output to user
        cout << "Account Type: Admin" << endl;
        cout << "Please choose from one of the following options:" << endl;
        cout << "Logout -- 1 " << endl;
        cout << "Refund -- 2 " << endl;
        cout << "Add Credit -- 3 " << endl;
        cout << "Bid -- 4 " << endl;
        cout << "Advertise -- 5 " << endl;
        cout << "Create User -- 6 " << endl;
        cout << "Delete User -- 7 " << endl;
        cout << "Add Credit to user account -- 4 " << endl;
        cout << "-->";

        //Take user input
        cin >> transaction;

        //Make choice based on user input
        switch (transaction)
        {
        case 1:  loop = false;
            break;
        }
    }
}
