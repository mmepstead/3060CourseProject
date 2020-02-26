#include "../User.h"
#include "Admin.h"
// Inputs: string username: username to add credit to, float credit: amount to add to account
// Outputs: float for new balance
float Admin::addCredit(string username, float credit) {
    // TODO: INITIALIZE USER PROPERLY
    User user;
    user.setUsername(username);
    float creditBalance = user.getCreditBalance();
    if (credit <= 0 || credit > 999.99)
		{
			cout << "Invalid amount." << endl;
			return 0;
		}
		else if ((creditBalance + credit) > 999.99)
		{
			cout << "Error: Adding amount " << credit << " will bring account balance above 999.99." << endl;
			return 0;
		}
		else
		{
			cout << "Credit of " << credit << " successfully added to account " << user.getUsername() << endl;
			creditBalance += credit;
			cout << "Current balance: " << creditBalance << endl;
			return creditBalance;
		}
}