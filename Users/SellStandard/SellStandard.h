#include "../User.h"

class SellStandard : public User
{
public:
	// Inputs: string name: username for account, float balance: balance for account
	// Outputs: None
	SellStandard(string name, float balance)
	{
		setUsername(name);
		setCreditBalance(balance);
		setUserType(2);
	}

	// Inputs: string item: name of item, float amount: amount of bid
	// Outputs: None
	void bid(string item, float amount);
};
