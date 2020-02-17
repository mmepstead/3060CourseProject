// Main class to run the std in loop that will take the user inputs
#include <iostream>
#include <string>
#include "Authentication.h"
#include "User.h"
using namespace std;

int main()
{
    int transaction;
    User currentUser;
    int state = 0;
    //States:
    //State 0 = Logged out
    //State 1 = Exit state
    //State 2 = Logged in state

    //Logged out state
    while (state == 0)
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
            case 0: state = 1;
                    break;

            //Login was chosen
            case 1: Authentication auth;//Create instance of authentication class
                    currentUser = auth.login();//Call login function
                    if (currentUser.getUsername() != "") { state = 2; }//Check if valid login
                    break;

            //Default case 
            default: break;
        }
        //Logged in state
        while (state == 2)
        {
            //Output to user
            cout << "Please choose from one of the following options:" << endl;
            cout << "Logout -- 1 " << endl;
            cout << "-->";

            //Take user input
            cin >> transaction;

            //Make choice based on user input
            switch (transaction)
            {
            case 1:  state = 0;
                     break;
            }
        }
        

    }


    return 0;

}
