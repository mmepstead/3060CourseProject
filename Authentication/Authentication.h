#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include "../Users/User.h"
using namespace std;
//Class to handle all user authentication and logins
class Authentication
{
    public:
        // Inputs: None
        // User Inputs: String username, String password
        // Outpus: User (To be set as the current user)
        int login(string username, string current_users_file);
        // Inputs: None
        // User Inputs: Confirmation of logout
        // Outputs: None simply sets the current user to null
        void logout();
};
#endif
