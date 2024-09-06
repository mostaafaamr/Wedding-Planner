#include<iostream>
#include<cmath>
using namespace std;
class Event
{
private:
	char EventName[100];
	char CustomerName[100];
	float GuestCount;
	float EventDuration;
	int NumberOfWaiters;
	float CostPerWaiter;
	float FoodCost;
	float TotalCost;
	float DepositAmount;
public:
	void getEventName();
	void getCustomerName();
	void getGuestCount();
	void getEventDuration();
	void CalculateCost();
	void PrintInfo();

};
void Event:: getEventName()
{
	cout << "Enter the name of the event " << endl;
	cin.getline(EventName, 100);
}

void Event::getCustomerName()
{
	cout << "Enter the customer's first and last name" << endl;
	cin.getline(CustomerName, 100);
	
	
}
void Event::getGuestCount()
{
	cout << "Enter the number of guests" << endl;
	while (true)
	{
		cin >> GuestCount;
		if (!cin||GuestCount<=0)
		{
			cout << "please re-enter the number of guests " << endl;
			cin.clear();
			cin.ignore(LLONG_MAX , '\n');  
			continue;
		}
		else 
			break;
	} 	

	
	while (GuestCount<0)
	{
		cout << "Invalid input, Re-enter the number of guests";
		cin >> GuestCount;
	}
	GuestCount = int(GuestCount);
	
}
void Event::getEventDuration()
{
	cout << "Enter the number of minutes in the event" << endl ;
	cin >> EventDuration; 
	while (EventDuration <= 0)
	{
		cout << "Invalid input, Re-enter the number of minutes in the event";
			cin >> EventDuration;
	}
	EventDuration = ceil(EventDuration); //If the user enters event duration as a float, we approximate to the next minute.
}
void Event::CalculateCost()
{
	NumberOfWaiters = ceil(GuestCount/20.0);
	TotalCost = 0;
	FoodCost = GuestCount * 54.5;
	int hours = 0; float mins =EventDuration;   
	for(int i=0;i<=EventDuration;i++)
{
	if (i == 60 * (hours + 1))
	{
		hours++;
	}
	

}
mins = EventDuration - hours * 60;
if (mins >= 46.5)
mins = 46.5;
CostPerWaiter = hours * 46.5 + mins;
TotalCost = FoodCost + CostPerWaiter * NumberOfWaiters;
DepositAmount = 0.25 * TotalCost;
}
void Event::PrintInfo()
{
	cout << "-------------------------" << endl;
	cout << EventName << " Event " << endl;
	cout << "Event estimate for " << CustomerName << endl;
	cout << "-------------------------" << endl;
	cout << "Number of waiters : " << NumberOfWaiters << endl;
	cout << "The Cost per Waiter : " << CostPerWaiter << endl;
	cout << "The Cost for Food is : " << FoodCost << endl;
	cout << "Total cost is : " << TotalCost << endl;
	cout << "Please provide a 25% deposit to reserve the event " << endl;
	cout << "the deposit needed is : " << DepositAmount << endl;

}



int main()
{
	Event x;
	x.getEventName();
	x.getCustomerName();
	x.getGuestCount();
	x.getEventDuration();
	x.CalculateCost();
	x.PrintInfo();
	return 0;
}




