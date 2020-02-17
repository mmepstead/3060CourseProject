#include <iostream>
#include <string>
#include <fstream>
#include "Authentication.h"
using namespace std;
//Class to handle all user authentication and logins
// Inputs: None
// User Inputs: String username, String password
// Outpus: User (To be set as the current user)
User Authentication::login()
{
    string line;
    string username;
    User loggedInUser;
    ifstream myfile("currentUsers.txt");
    if (myfile.is_open())
    {
        //Get username from user
        cout << "Enter Username: ";
        cin >> username;
        //Loop through currentUsers file
        while (getline(myfile, line))
        {
            //Check if username is in the file
            if (line.substr(0, line.find(" ")).compare(username) == 0)
            {
                loggedInUser.setUsername(username);
                cout << "Successfully Logged In!" << endl;
            }
        }
        //If no user was successfully logged in
        if (loggedInUser.getUsername().compare("") == 0)
        {
            cout << "Error: A user with that username does not exist" << endl;
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
    return loggedInUser;

}

// Inputs: None
// User Inputs: Confirmation of logout
// Outputs: None simply sets the current user to null
void Authentication::logout()
{

}