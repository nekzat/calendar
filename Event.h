#ifndef Event_h
#define Event_h
#include"Date.h"
#include<string>
using namespace std;
class Event {
private:
	Date EventDate;
	string place;
	string description;

public:
	Event();
	Event(Date, string, string);
	void setDate(Date);
	Date getDate();
	void setPlace(string);
	string getPlace(); 
	void setDescription(string);
	string getDescription(); 
	void printEvent();
};
#endif // !Event_h;