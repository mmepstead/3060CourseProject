#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include "../Users/User.h"
using namespace std;
//Class to handle all user authentication and logins
class Authentication
{
    public:
        User login();
        void logout();
};
#endif