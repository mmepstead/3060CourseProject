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

void SellStandard::bid(string item, float amount)
{
	cout << "Error: Account of type Sell Standard does not have acess to bid function" << endl;
}
