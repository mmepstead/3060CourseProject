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
	virtual void bid(string item, float amount) = 0;

	//Getters
	string getUsername() { return username; }
	float getCreditBalance() { return creditBalance; }
	//Item[] getItems();

	//Setters
	void setUsername(string username) { this.username = username; }
	void setCreditBalance(float credit) { this.creditBalance = creditBalance; }
	//Item[] getItems();

//private functions and variables
private:
	//Variable Decleration
	string username;
	float creditBalance;
	//Item items[3]; 
};

//Constuctor for the user class
User::User() {
	cout << "CONST" << endl;
}

void User::bid(string item, float amount) {
	cout << "THIS IS A TEST" << endl;
}
