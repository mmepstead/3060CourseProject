#include "TransactionWriter.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../common.h"
string TransactionWriter::stringFormatter(string input, int limit) 
{
    string result = input;
    for(int i = limit-input.length(); i > 0; i-=1)
    {
        result += " ";
    }
    return result;
}
string TransactionWriter::numberFormatter(string input, int limit) 
{
    string result = input;
    for(int i = limit-input.length(); i > 0; i-=1)
    {
        result = "0" + result;
    }
    return result;
}
// Inputs: Transaction type(1-create, 2-delete etc.),  
//  values: map containing the values for fields like username and others
// Outputs: None
void TransactionWriter::dailyTransactionWriter(int transactionType, map<string, string> values) 
{
    string line = "";
    ofstream myfile;
    myfile.open (daily_transaction_file, ios_base::app);
    line += "0";
    line += to_string(transactionType);
    line += " ";
    switch (transactionType)
    {
        case 3: 
            line += stringFormatter(values.at("item"), 25);
            line += " ";
            line += stringFormatter(values.at("seller"), 15);
            line += " ";
            line += numberFormatter(values.at("days"),3);
            line += " ";
            line += numberFormatter(values.at("minimum_bid"), 6);
            line += "\n";
            break;
        case 4: 
            line += stringFormatter(values.at("item"), 25);
            line += " ";
            line += stringFormatter(values.at("seller"), 15);
            line += " ";
            line += stringFormatter(values.at("buyer"), 15);
            line += " ";
            line += numberFormatter(values.at("bid"), 6);
            line += "\n";
            break;
        case 5: 
            line += stringFormatter(values.at("buyer"), 15);
            line += " ";
            line += stringFormatter(values.at("seller"), 15);
            line += " ";
            line += numberFormatter(values.at("refund_credit"),10);
            line += "\n";
            break;
        default:
            line += stringFormatter(values.at("username"), 15);
            line += " ";
            line += values.at("user_type");
            line += " ";
            line += numberFormatter(values.at("credit_balance"),10);
            line += "\n";
            break;
    }
    myfile << line;
    myfile.close();
}
// Inputs: username: username of the user, type: the acronym for the user's account type(FS - full-standard),
//  credit: the amount of credit on the user's account
// Outputs: None
void TransactionWriter::currentUsersWriter(string username, string type, float credit) 
{

}
// Inputs: name: Name of item, seller: username of seller, winningUser: username of user with current highest bid,
//  winningBid: value of current highest bid, daysLeft: Number of days left before auction closes
// Outputs: None
void TransactionWriter::availableItemsWriter(string name, string seller, string winningUser, string winningBid, int daysLeft) 
{

}