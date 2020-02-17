#include "User.h"

class BuyStandard : public User
{
public:
	BuyStandard(string name, float balance)
	{
		setUsername(name);
		setCreditBalance(balance);
		setUserType(1);
	}

	void advertise(string itemName, float minBid, int days);
};


void BuyStandard::advertise(string itemName, float minBid, int days)
{
	cout << "Error: Account of type Buy Standard does not have acess to advertise function" << endl;
}
