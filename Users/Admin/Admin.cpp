#include "../User.h"
#include "Admin.h"
#include "../../TransactionWriter/TransactionWriter.h"
#include <map>

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

void Admin::create(string username, int type)
{
  TransactionWriter writer;
  map<string, string> values;
  values.insert(pair<string, string>("username", username));
  values.insert(pair<string, string>("user_type", to_string(type)));
  values.insert(pair<string, string>("credit_balance", "000000000"));
  writer.dailyTransactionWriter(1, values);
  cout << "Successfully created user: " << username << endl;
}

void Admin::deleteUser(string username)
{
  TransactionWriter writer;
  map<string, string> values;
  values.insert(pair<string, string>("username", username));
  values.insert(pair<string, string>("user_type", to_string(0)));
  values.insert(pair<string, string>("credit_balance", "000000000"));
  writer.dailyTransactionWriter(1, values);
  cout << "Successfully deleted user: " << username << endl;
}
