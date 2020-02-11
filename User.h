#ifndef STUDENT_H
#define STUDENT_H
//#include<Item>
#include<string>
#include<iostream>

using namespace std;


class User {
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
		//Item[] getItems();

		//Setters
		void setUsername(string inputUsername) { username = inputUsername; }
		void setCreditBalance(float credit) { creditBalance = credit; }
		//Item[] getItems();

	//private functions and variables
	private:
		//Variable Decleration
		string username;
		float creditBalance;
		//Item items[3]; 
};
#endif
