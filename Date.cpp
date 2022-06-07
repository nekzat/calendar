#include"Date.h"
#include<iostream>
using namespace std;
Date::Date() {
	day = 1111;
	month = 1;
	year = 1;
}
Date::Date(int newYear, int newMouth, int newDay) {
	day = newDay;
	month = newMouth;
	year = newYear;
}
void Date::setDay(int newDay) {
	day = newDay;
}
int Date::getDay() {
	return day;
}
void Date::setMonth(int newMouth) {
	month = newMouth;
}
int Date::getMonth() {
	return month;
}
void Date::setYear(int newYear) {
	year = newYear;
}
int Date::getYear() {
	return year;

}
void Date::printDate() {
	cout << year << "¦~" << month << "¤ë" << day << "¤é" ;
}