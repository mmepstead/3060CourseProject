#include "../User.h"

class FullStandard : public User
{
public:
	// Inputs: string name: username for account, float balance: balance for account
	// Outputs: None
	FullStandard(string name, float balance)
	{
		setUsername(name);
		setCreditBalance(balance);
		setUserType(3);
	}
};
