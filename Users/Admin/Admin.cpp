#include "../User.h"
#include "Admin.h"
#include <string>
#include <map> 
#include <fstream>
#include "../../TransactionWriter/TransactionWriter.h"

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
void Admin::bid(string item, float amount)
	{
		TransactionWriter bidWriter;
		map<string, string> values;
		ifstream inFile;
		inFile.open ("availableItems.txt", ios_base::app);
		if (inFile.is_open()) 
		{
			string arr = "";
			string name = "";
			string seller = "";
			string curBid = "";
			char line[65];
			int spaceCount = 0;
			bool foundItem = false;
			while (getline(inFile, arr)) 
			{
				spaceCount = 0;
				name = "";
				curBid = "";
				seller = "";
				for(int i=0; i<arr.size();i++){
					
					if (arr[i] == 32){
						spaceCount +=1;
					}
					if (spaceCount == 0){
						name+=arr[i];
					}
					else if (spaceCount == 1)
					{
						seller += arr[i];
					}
					else if (spaceCount == 4){
						curBid+=arr[i];
					}
				}
				if (name == item)
				{
					foundItem = true;
					break;
				}
			}
			inFile.close();
			if (foundItem)
			{
				float newBid = atof(curBid.c_str());
					values.insert(pair<string, string>("item", item));
					values.insert(pair<string, string>("seller", seller)); 
					values.insert(pair<string, string>("buyer", getUsername()));
					values.insert(pair<string, string>("bid", to_string(amount)));  
					bidWriter.dailyTransactionWriter(4, values);
					cout << "you have successfully bid on the item" << endl;
			}
			else
			{
				cout << "Item was not found" << endl;
			}
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
