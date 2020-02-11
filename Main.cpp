// Main class to run the std in loop that will take the user inputs
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string transaction;
    while(transaction != "Exit") 
    {
        cout << "Enter a transaction: " <<endl;
        cin >> transaction;
    }

    return 0;

}
