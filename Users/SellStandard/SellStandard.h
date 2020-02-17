#include "User.h"

class SellStandard : public User
{
public:
	SellStandard(string name, float balance)
	{
		setUsername(name);
		setCreditBalance(balance);
		setUserType(2);
	}

	void bid(string item, float amount);
};
