//#include<Item>
#include<string>
#include<iostream>
#include "User.h"
using namespace std;

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