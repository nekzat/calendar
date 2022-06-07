#include"Event.h"
#include"Date.h"
#include<string>
#include<iostream>
using namespace std;
Event::Event(){
	EventDate = Date(2000,1,1);
	place = "school";
	description = "practice";
}
Event::Event(Date newDate, string newPlace, string newDescription) {
	EventDate = newDate;
	place = newPlace;
	description = newDescription;
}
void Event::setDate(Date newDate) {
	EventDate= newDate;
}
Date Event::getDate() {
	return EventDate;
}
void Event::setPlace(string newPlace) {
	place = newPlace;
}
string Event::getPlace() {
	return place;
}
void Event::setDescription(string newDescription) {
	description = newDescription;
}
string Event::getDescription() {
	return description;

}
void Event::printEvent() {
	EventDate.printDate();
	cout << " " << getPlace() << " " << getDescription() << endl;
}