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
#include <fstream>
#include "./Authentication/Authentication.h"
//#include "./Authentication/Authentication.cpp"
#include "./Users/User.h"
//#include "./Users/User.cpp"
#include "./Users/BuyStandard/BuyStandard.h"
#include "./Users/SellStandard/SellStandard.h"
#include "./Users/FullStandard/FullStandard.h"
#include "./Users/Admin/Admin.h"
#include "./TransactionWriter/TransactionWriter.h"

using namespace std;

void state0();
void state2Buy(string username);
void state2Sell(string username);
void state2Full(string username);
void state2Admin(string username);
void advertiseItem(User user);
bool itemNameTaken(string itemName);
bool userExists(string username);
string current_users_file;
// Inputs: None
// Outputs: Int
int main(int argc, char *argv[])
{
    current_users_file = argv[1];
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
            accntType = auth.login(username, current_users_file);//Call login function

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
                cout << "Error: Invalid transaction code" << endl;
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
        cout << "-->"<< endl;

        //Take user input
        cin >> transaction;

        //Make choice based on user input
        switch (transaction)
        {
        case 1:  loop = false;
            break;
        case 3:
        {
            float credit;
            cout << "Please enter the amount of credit you want to add to your account" << endl;
            if(cin >> credit) 
            {
                user.addCredit(credit);
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Invalid input" << endl;
            }
            break;
        }
		case 4:
		{
			string item;
			float bid;
			//take user input
			cout << "Enter the name of the item you wish to bid on: " << endl;
			cin >> item;
			cout << "Enter the amount you wish to bid: " << endl;
			//assuring correct input is entered
			if(cin >> bid)
            {

                user.bid(item, bid);
            }
			else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Invalid input" << endl;
            }
			break;
		}
        //Default case
        default:
            cout << "Error: Invalid transaction code" << endl;
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
        case 3:
        {
            float credit;
            cout << "Please enter the amount of credit you want to add to your account" << endl;
            if(cin >> credit) 
            {
                user.addCredit(credit);
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Invalid input" << endl;
            }
            break;
        }
        case 4:
            advertiseItem(user);
            break;
        //Default case
        default:
            cout << "Error: Invalid transaction code" << endl;
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
        case 3:
        {
            float credit;
            cout << "Please enter the amount of credit you want to add to your account" << endl;
           if(cin >> credit) 
            {
                user.addCredit(credit);
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Invalid input" << endl;
            }
            break;
        }
		case 4:
		{
			string item;
			float bid;
			//take user input
			cout << "Enter the name of the item you wish to bid on: " << endl;
			cin >> item;
			cout << "Enter the amount you wish to bid: " << endl;
			//assuring correct input is entered
			if(cin >> bid)
            {
                user.bid(item, bid);
            }
			else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Invalid input" << endl;
            }
			break;
		}
        case 5:
            advertiseItem(user);
            break;
        //Default case
        default:
            cout << "Error: Invalid transaction code" << endl;
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
        cout << "-->";

        //Take user input
        cin >> transaction;

        //Make choice based on user input
        switch (transaction)
        {
        case 1:  loop = false;
            break;
		case 2: 
		{
			string buy, sell;
			float money;
			//getting inputs
			cout << "Please enter the username of the buyer: " << endl;
			cin >> buy;
			cout << "Please enter the username of the seller: " << endl;
			cin >> sell;
			cout << "Please enter the amount to be refunded: " << endl;
			cin >> money;
			//checking if either the buy doesnt exist, and if both dont exist
			if(!userExists(buy) && !userExists(sell))
			{
				cout << "neither the buyer or the seller exists" << endl;
			}
			else if (!userExists(sell))
			{
				cout << "seller does not exist" << endl;
			}
			else if(!userExists(buy))
			{
				cout << "buyer does not exist" << endl;
			}	
			else 
			{
				//calling the function once the inputs are gathered
				user.refund(buy, sell, money);
			}
			break;
		}
        case 3:
        {
            string username;
            float credit;
            Authentication auth;
            cout << "Enter username of user to add credit to:" << endl;
            cin >> username;
            // Quick way to check if user exists
            if(userExists(username)) 
            {
                cout << "Enter amount of credit to add:" << endl;
                if(cin >> credit) 
                {
                    user.addCredit(username, credit);
                }
                else
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Error: Invalid input" << endl;
                }
                
            }
            else
            {
                cout << "Error: User with that username does not exist" << endl;
            }
            break;
        }
        case 4:
		{
			string item;
			float bid;
			cout << "Enter the name of the item you wish to bid on: " << endl;
			cin >> item;
			cout << "Enter the amount you wish to bid: " << endl;
			if(cin >> bid)
            {
                user.bid(item, bid);
            }
			else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Invalid input" << endl;
            }
            
			break;
		}
		case 5:
            advertiseItem(user);
            break;
        case 6:
        {
            string username;
            int userAccntType;
            cout << "Enter a username: ";
            cin >> username;
            cout << "Enter account type:" << endl << "1 = BuyStandard" << endl << "2 = SellStandard" << endl << "3 = FullStandard" << endl << "4 = Admin" << endl;
            cin >> userAccntType;
            user.create(username,userAccntType);
            break;
        }


        case 7:
        {
          string username;
          cout << "Enter the username to delete: ";
          cin >> username;
          user.deleteUser(username);
          break;
        }

        //Default case
        default:
            cout << "Error: Invalid transaction code" << endl;
            break;
        }
    }
}

bool userExists(string username)
{
    string line;
    ifstream myfile(current_users_file.c_str());

    if (myfile.is_open())
    {
        //Loop through currentUsers file
        while (getline(myfile, line))
        {
            //Check if username is in the file
            if (line.substr(0, line.find(" ")).compare(username) == 0)
            {
                myfile.close();
                return true;
            }
        }
        return false;
        myfile.close();
    }
    cout << "Error: Unable to open file" << endl;
}

bool itemNameTaken(string itemName)
{
    string line;
    ifstream myfile("availableItems.txt");

    if (myfile.is_open())
    {
        //Loop through currentUsers file
        while (getline(myfile, line))
        {
            //Check if username is in the file
            if (line.substr(0, line.find(" ")).compare(itemName) == 0)
            {
                myfile.close();
                return true;
            }
        }
        return false;
        myfile.close();
    }
    cout << "Error: Unable to open file" << endl;
}
void advertiseItem(User user)
{
    string itemName;
    float minBid;
    int days;
    cout << "Enter the name of the item you want to advertise:" << endl;
    if(!(cin >> itemName))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Invalid input" << endl;
    }
    if(itemNameTaken(itemName))
    {
        cout << "Error: An item with that name already exists" << endl;
        return;
    }
    cout << "Enter minimum bid for the item:" << endl;
    if(!(cin >> minBid))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Invalid input" << endl;
    }
    if(minBid < 0 || minBid > 999.99)
    {
        cout << "Error: Minimum bid must be between $0 and $999.99" << endl;
        return;
    }
    cout << "Enter number of days for item to be auctioned:" << endl;
    if(!(cin >> days))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Invalid input" << endl;
    }
    if(days < 0 || days > 100)
    {
        cout << "Error: Number of days must be between 0 and 100" << endl;
        return;
    }
    user.advertise(itemName, minBid, days);
    return;
}
