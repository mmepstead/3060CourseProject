#include <iostream>
#include <string>
#include <fstream>
#include "../Users/User.h"
#include "Authentication.h"

using namespace std;
//Class to handle all user authentication and logins
// Inputs: None
// User Inputs: String username, String password
// Outpus: User (To be set as the current user)
int Authentication::login(string username, string current_users_file)
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
                cout << "Successfully Logged In!" << endl;
                myfile.close();
                return (line.substr(line.find(" ") + 1, 1))[0] - '0';
            }
        }

        cout << "Error: A user with that username does not exist" << endl;
        myfile.close();
        return 0;
    }
    else
    {
        cout << "Unable to open file" << endl;
        return 0;
    }
}


// Inputs: None
// User Inputs: Confirmation of logout
// Outputs: None simply sets the current user to null
void Authentication::logout()
{

}