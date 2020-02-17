#include "User.h"

class Admin : public User
{
public:
	Admin(string name, float balance)
	{
		setUsername(name);
		setCreditBalance(balance);
		setUserType(4);
	}

	void create(string username, int type);
	void deleteUser(string username);
	float addCredit(string username, float credit);
};