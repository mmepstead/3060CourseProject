#include <iostream>
#include <string>

using namespace std;

class Item 
{
	private:
		String Name, CurrentHighestUser;
		int TimeLeft;
		float MinBid, CurrentHighestBid;
	public :
	
		//constructor
		Item(String N, int TL, float MB, float CHB, String CHU)
		{
			String Name = N;
			int TimeLeft = TL;
			float MinBid = MB;
			float CurrentHighestBid = CHB;
			String CurrentHighestUser = CHU;
		};
		
		//simple getter & setter functions
		String getName()
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
			return CurrentHighestBid
		}
		String getCurrentHighestUser()
		{
			return CurrentHighestUser
		}
		void setName(String N)
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
		void setCurrentHighestUser(String CHU)
		{
			CurrentHighestUser = CHU;
		}
		
}