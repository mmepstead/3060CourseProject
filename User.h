#ifndef STUDENT_H
#define STUDENT_H
//#include<Item>
#include<string>
#include<iostream>

using namespace std;


class User 
{

//public functions and variables
public:
	//Function Declerations
	void refund(string buyer, string seller, float credit);
	float addCredit(float credit);
	void advertise(string itemName, float minBid, int days);
	void bid(string item, float amount);

	//Getters
	string getUsername() { return username; }
	float getCreditBalance() { return creditBalance; }
	int getUserType() { return userType; }

	//Setters
	void setUsername(string inputUsername) { username = inputUsername; }
	void setCreditBalance(float credit) { creditBalance = credit; }
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


void User::refund(string buyer, string seller, float credit)
{

}


/*
*/
float User::addCredit(float credit)
{
	if (credit <= 0 || credit > 999.99)
	{
		cout << "Invalid amont." << endl;
	}
	else if ((creditBalance + credit) > 999.99)
	{
		cout << "Error: Adding amount " << credit << " will bring account balance above 999.99." << endl;
	}
	else
	{
		cout << "Credit of " << credit << " successfully added to account" << getUsername() << endl;
	}
}