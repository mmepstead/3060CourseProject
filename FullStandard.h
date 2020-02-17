#include "User.h"

class FullStandard : public User
{
public:
	FullStandard(string name, float balance)
	{
		setUsername(name);
		setCreditBalance(balance);
		setUserType(3);
	}
};


