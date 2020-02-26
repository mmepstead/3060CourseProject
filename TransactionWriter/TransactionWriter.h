#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <map>

using namespace std;

class TransactionWriter 
{
    public:

        string stringFormatter(string input, int limit);
        string numberFormatter(string input, int limit);
        // Inputs: Transaction type(1-create, 2-delete etc.),  
        //  values: map containing the values for fields like username and others
        // Outputs: None
        void dailyTransactionWriter(int transactionType, map<string, string> values);
        // Inputs: username: username of the user, type: the acronym for the user's account type(FS - full-standard),
        //  credit: the amount of credit on the user's account
        // Outputs: None
        void currentUsersWriter(string username, string type, float credit);
        // Inputs: name: Name of item, seller: username of seller, winningUser: username of user with current highest bid,
        //  winningBid: value of current highest bid, daysLeft: Number of days left before auction closes
        // Outputs: None
        void availableItemsWriter(string name, string seller, string winningUser, string winningBid, int daysLeft);
};
#endif
