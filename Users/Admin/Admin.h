#include "../User.h"

class Admin : public User
{
public:
	// Inputs: string name: username for account, float balance: balance for account
	// Outputs: None
	Admin(string name, float balance)
	{
		setUsername(name);
		setCreditBalance(balance);
		setUserType(4);
	}

	// Inputs: string username: username for account, int type: type of account
	// Outputs: None
	void create(string username, int type);
	// Inputs: string usename: username for account to delete
	// Outputs: None
	void deleteUser(string username);
	// Inputs: string username: username to add credit to, float credit: amount to add to account
	// Outputs: float for new balance
	float addCredit(string username, float credit);
	void bid(string item, float amount);
};
