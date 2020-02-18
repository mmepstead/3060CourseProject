#include "../User.h"

class BuyStandard : public User
{
public:
	// Inputs: string name: username for account, float balance: balance for account
	// Outputs: None
	BuyStandard(string name, float balance)
	{
		setUsername(name);
		setCreditBalance(balance);
		setUserType(1);
	}

	// Inputs: string itemName: name of item, float minBid: amount of minimum bid,
	// int days: number of days aution is avalible
	// Outputs: None
	void advertise(string itemName, float minBid, int days);
};
