#ifndef Date_h
#define Date_h
class Date{
private:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int, int, int);
	void setDay(int);
	int getDay();
	void setMonth(int);
	int getMonth();
	void setYear(int);
	int getYear(); 
	void printDate();
};
#endif // !Date_h


