//#include<Item>
#include<string>
#include<iostream>
#include "User.h"
#include <map> 
#include <fstream>
#include "../TransactionWriter/TransactionWriter.h"
using namespace std;

	// Inputs: String buyer: username of buyer, String seller: username of seller,
	// float credit: amount of creddit to refund
	// Outputs: None
	void User::refund(string buyer, string seller, float credit)
	{
		
			TransactionWriter writer; //simple writer
			map<string, string> values;
			values.insert(pair<string, string>("buyer", buyer));//entering values into the map
			values.insert(pair<string, string>("seller", seller)); 
			values.insert(pair<string, string>("refund_credit", to_string(credit)));
			writer.dailyTransactionWriter(5, values);//writing to the file with the correct transaction number
			cout << "the credit has been refunded" << endl;
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
			TransactionWriter writer;
			map<string, string> values;
			values.insert(pair<string, string>("username", getUsername()));
			values.insert(pair<string, string>("credit_balance", to_string(creditBalance)));
			switch(userType) {
				case 1:
					values.insert(pair<string, string>("user_type", "BS"));
					break;
				case 2:
					values.insert(pair<string, string>("user_type", "SS"));
					break;
				case 3:
					values.insert(pair<string, string>("user_type", "FS"));
					break;
				case 4:
					values.insert(pair<string, string>("user_type", "AA"));
					break; 
			} 
			writer.dailyTransactionWriter(6, values);
			return creditBalance;
		}
	}
	//Inputs: string for the item name, float for the amount to bid
	//Ouputs: none
	void User::bid(string item, float amount)
	{
		TransactionWriter bidWriter; //creating a transaction writer
		map<string, string> values;//map to store the values based on the case for bid (case 4)
		ifstream inFile;
		inFile.open ("availableItems.txt", ios_base::app);
		if (inFile.is_open()) 
		{
			string arr = ""; //simple variable declarations
			string name = "";
			string seller = "";
			string curBid = "";
			char line[65];
			int spaceCount = 0;
			bool foundItem = false;
			while (getline(inFile, arr)) //going through the file line by line, and storing that line in the arr string
			{
				spaceCount = 0;
				name = "";
				curBid = "";
				seller = "";
				for(int i=0; i<arr.size();i++){ //going through the arr string as a character array and separate the individual parts based on the spaces
					
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
					foundItem = true; //changes boolean if item is found
					break;
				}
			}
			inFile.close();
			if (foundItem)
			{
				float newBid = atof(curBid.c_str());
				if ((amount/newBid) <= 1.05)
				{
					cout << "bid is not large enough" << endl;
				}
				else
				{
					values.insert(pair<string, string>("item", item));//inserting all the values into the map
					values.insert(pair<string, string>("seller", seller)); 
					values.insert(pair<string, string>("buyer", getUsername()));
					values.insert(pair<string, string>("bid", to_string(amount)));  
					bidWriter.dailyTransactionWriter(4, values);
					cout << "you have successfully bid on the item" << endl;
				}
			}
			else
			{
				cout << "Item was not found" << endl;
			}
		}
		
	}
