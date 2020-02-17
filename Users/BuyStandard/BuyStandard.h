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
