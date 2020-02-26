//#include<Item>
#include<string>
#include<iostream>
#include "User.h"
#include <map> 
#include "../TransactionWriter/TransactionWriter.h"
using namespace std;

	// Inputs: String buyer: username of buyer, String seller: username of seller,
	// float credit: amount of creddit to refund
	// Outputs: None
	void User::refund(string buyer, string seller, float credit)
	{

	}
	// Inputs: String itemName: name of item, float minBid: minimum bid
	// int days: number of days aution lasts
	// Outputs: None
	void User::advertise(string itemName, float minBid, int days) {
		TransactionWriter writer;
		map<string, string> values;
		values.insert(pair<string, string>("item", itemName));
		values.insert(pair<string, string>("seller", username)); 
		values.insert(pair<string, string>("days", to_string(days)));
		values.insert(pair<string, string>("minimum_bid", to_string(minBid).substr(0, to_string(minBid).find(".")+3)));   
		writer.dailyTransactionWriter(3, values);
		cout << "Successfully advertised item!" << endl;
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
