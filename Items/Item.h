#include <iostream>
#include <string>

using namespace std;

class Item 
{
	private:
		string Name, CurrentHighestUser;
		int TimeLeft;
		float MinBid, CurrentHighestBid;
	public :
	
		//constructor
		// Inputs: Item name, Time left, Minimum bid, Current highest bid(value), Current highest bidder (User)
		Item(string N, int TL, float MB, float CHB, string CHU)
		{
			string Name = N;
			int TimeLeft = TL;
			float MinBid = MB;
			float CurrentHighestBid = CHB;
			string CurrentHighestUser = CHU;
		};
		
		//simple getter & setter functions
		string getName()
		{
			return Name;
		}
		int getTimeLeft()
		{
			return TimeLeft;
		}
		float getMinBid()
		{
			return MinBid;
		}
		float getCurrentHighestBid()
		{
			return CurrentHighestBid;
		}
		string getCurrentHighestUser()
		{
			return CurrentHighestUser;
		}
		void setName(string N)
		{
			Name = N;
		}
		void setTimeLeft(int TL)
		{
			TimeLeft = TL;
		}
		void setMinBid(float MB)
		{
			MinBid = MB;			
		}
		void setCurrentHighestBid(float CHB)
		{
			CurrentHighestBid = CHB;
		}
		void setCurrentHighestUser(string CHU)
		{
			CurrentHighestUser = CHU;
		}
		
};