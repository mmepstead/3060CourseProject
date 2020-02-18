#ifndef USER_H
#define USER_H
#include "../Items/Item.h"
#include<string>
#include<iostream>

using namespace std;


class User
{

	//public functions and variables
	public:
		//Function Declerations
		// Inputs: String buyer:username of buyer, string seller: username of buyer
		// float credit:amount of credit to refund
		// Outputs: None
		void refund(string buyer, string seller, float credit);
		// Inputs: amount of credit to add
		// Outputs: new balance of credit
		float addCredit(float credit);
		// Inputs: String itemName: name of item, float minBid: minimum bid
		// int days: number of days aution lasts
		// Outputs: None
		void advertise(string itemName, float minBid, int days);
		// Inputs: String item: name of item, float amount: amount of bid
		// Outputs: None
		void bid(string item, float amount);

		//Getters
		// Inputs: None
		// Outputs: username
		string getUsername() { return username; }
		// Inputs: None
		// Outputs: creditBalance
		float getCreditBalance() { return creditBalance; }
		// Inputs: None
		// Outputs: usertype
		int getUserType() { return userType; }

		//Setters
		// Inputs: string inputUsername: new username
		// Outputs: None
		void setUsername(string inputUsername) { username = inputUsername; }
		// Inputs: string credit: new credit balance
		// Outputs: None
		void setCreditBalance(float credit) { creditBalance = credit; }
		// Inputs: string type: new account type
		// Outputs: None
		void setUserType(int type) { userType = type; }

	//private functions and variables
	private:
		//Variable Decleration
		string username;
		int userType;
		//User Types:
		//1 = Buy standard
		//2 = Sell standard
		//3 = Fulll standard
		//4 = Admin
		float creditBalance;

};
#endif
