//#include<Item>
#include<string>
#include<iostream>
#include "User.h"
using namespace std;

	// Inputs: String buyer: username of buyer, String seller: username of seller,
	// float credit: amount of creddit to refund
	// Outputs: None
	void User::refund(string buyer, string seller, float credit)
	{

	}


	// Inputs: float for amount of credit to add
	// Outputs: float for new user balance
	float User::addCredit(float credit)
	{
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
			cout << "Credit of " << credit << " successfully added to account " << getUsername() << endl;
			creditBalance += credit;
			cout << "Current balance: " << creditBalance << endl;
			return creditBalance;
		}
}
