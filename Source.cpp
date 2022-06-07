#include"Date.h"
#include"Event.h"
#include <iostream>
#include<iomanip>
#include<vector>
#include<fstream>

using namespace std;

void printDate(vector<Event> EventList){
    int i;
    int remainder;
    int year;
    int month;
    int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int dayrem;
    cout << "請輸入年份：";
    cin >> year;
    while (year <= 0) {
         cout <<"really ?? =_=" << endl ;
         cout << "請輸入年份：" ;
         cin >> year;
    }
    cout << "請輸入月份：" ;
    cin >> month;
    remainder = (year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        if (month >= 2) {
            day[1] = 29;
        }
    }
    while (month < 1 || month > 12) {
        cout << "really ?? =_=" << endl ;
        cout << "請輸入月份：" ;
        cin >> month;
        remainder = (year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (month >= 2) {
                day[1] = 29;
            }
        }
    }
    cout << endl ;
    remainder = (year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        if (month >= 2) {
            day[1] = 29;
        }
    }

    for (i = 0; i < (month - 1); i++) {
        remainder += day[i];
    }

    dayrem = (remainder + 1) % 7;

    cout << " 西元" << year << "年" << month << "月" << endl;
    cout << " 日 一 二 三 四 五 六" << endl;

    for (i = 0; i < dayrem; i++) {
        cout << setw(3) << setfill(' ') << "";
    }
    int count = dayrem % 7;

    for (i = 0; i < day[month - 1]; i++) {
        cout << setw(3) << setfill(' ') << i + 1;
        if (count >= 6) {
            cout << endl;
            count = 0;
        }
        else {
            count++;
        }
    }
    cout << endl;
    cout << endl;
    int counter = 0;
    for (int i = 0; i < EventList.size(); i++) {
        if (EventList[i].getDate().getYear() == year) {
            if (EventList[i].getDate().getMonth() == month) {
                cout << "Date: "<<EventList[i].getDate().getYear() << "/" << EventList[i].getDate().getMonth() << "/" << EventList[i].getDate().getDay() <<" ";
                cout << "Place: "<<EventList[i].getPlace() << " Description: " << EventList[i].getDescription()<<endl;
                counter++;
            }
        }
    }
    if (counter == 0){
        cout << "No Event in this month" << endl<<endl;
    }
    else {
        cout << endl<<endl;
    }
}
void printVector(vector<Event> EventList) {
    for (int i = 0; i < EventList.size(); i++) {
        EventList[i].printEvent();
    }
    cout << endl;
}
void addEvent(vector<Event>& EventList) {
    int year, mouth, day;
    EventList.resize(EventList.size()+1);
    
    string neoPlace,neoDescription;

    cout << "Enter year: ";
    cin >> year;
    cout << "Enter mouth: ";
    cin >> mouth;
    cout << "Enter day: ";
    cin >> day;
    cout << endl;

    cout << "Enter Place: ";
    cin >> neoPlace;
    cout << endl;

    cout << "Enter Description: ";
    cin >> neoDescription;
    cout << endl;
    
    EventList[EventList.size()-1].setDate(Date(year , mouth , day));
    EventList[EventList.size()-1].setPlace(neoPlace);
    EventList[EventList.size()-1].setDescription(neoDescription);
    cout << "add Event success " << endl;
}
void writeFlie(vector<Event> EventList) {
    ofstream file;
    file.open("Event.txt",ios::out);
    file << EventList.size() << "\n";
    for (int i = 0; i < EventList.size(); i++) {
        file << EventList[i].getDate().getYear()<<" ";
        file << EventList[i].getDate().getMonth()<<" ";
        file << EventList[i].getDate().getDay()<<" "<<"\n";
        file << EventList[i].getPlace() << "\n";
        file << EventList[i].getDescription() << "\n";
    }
    file.close();
    cout << "store success " << endl;
}
void readFlie(vector<Event>& EventList) {
    int vec_size,newYear, newMonth, newDay;
    string newPlace, newDescription;
    ifstream file;
    file.open("Event.txt", ios::in);
    file >> vec_size;
    for (int i = 0; i < vec_size; i++) {
        EventList.resize(EventList.size() + 1);
        file >> newYear >> newMonth >> newDay;
        file >> newPlace >> newDescription;
        EventList[i].setDate(Date(newYear, newMonth, newDay));
        EventList[i].setPlace(newPlace);
        EventList[i].setDescription(newDescription);
    }
    file.close();
    cout << "read the file" << endl;
}
void clearVector(vector<Event>& EventList) {
    EventList.clear();
    cout << "already delete all Event" << endl;
}
void deleteEvent(vector<Event>& EventList) {
    int deleteYear, deleteMonth, deleteDay, deleteCounter = 0;
    int tempYear = 0, tempMonth = 0, tempDay = 0;
    cout << "Enter the year you want to delete: ";
    cin >> deleteYear ;
    cout << "Enter the Mouth you want to delete: ";
    cin >> deleteMonth;
    cout << "Enter the Day you want to delete: ";
    cin >> deleteDay;
    for (int i = 0; i < EventList.size(); i++) {
        if (EventList[i].getDate().getYear() == deleteYear) {
            if (EventList[i].getDate().getMonth() == deleteMonth) {
                if (EventList[i].getDate().getDay() == deleteDay) {
                    tempYear = EventList[EventList.size()-1].getDate().getYear();
                    tempMonth = EventList[EventList.size()-1].getDate().getMonth();
                    tempDay = EventList[EventList.size()-1].getDate().getDay();
                    EventList[EventList.size() - 1].setDate(Date(deleteYear, deleteMonth, deleteDay));
                    EventList[i].setDate(Date(tempYear, tempMonth, tempDay));
                    EventList[i].setPlace(EventList[EventList.size() - 1].getPlace());
                    EventList[i].setDescription(EventList[EventList.size() - 1].getDescription());
                    EventList.pop_back();
                    deleteCounter++;
                }
            }
        }

    }
    if (deleteCounter == 0) {
        cout << "No events can be deleted on that day!!" << endl;
    }
    else if (deleteCounter > 0) {
        cout << "already delete " << deleteCounter << " Event!!" << endl;
    }
    else {
        cout << " ? ? ? ? ? ? ? " << endl;
    }

}

int main()
{   
    int i = 0;
    vector<Event>eventlist;
    readFlie(eventlist);
    printDate(eventlist);
    cout << "enter the control number if you dont know Enter 8" << endl<<endl;
    while (i != -1) {
        cin >> i;
        cout << endl;
        if ( 0 < i && i < 9) {
            switch (i) {
            case 1:
                printDate(eventlist);
                break;
            case 2:
                printVector(eventlist);
                break;
            case 3:
                addEvent(eventlist);
                break;
            case 4:
                deleteEvent(eventlist);
                break;
            case 5:
                clearVector(eventlist);
                break;
            case 6:
                writeFlie(eventlist);
                break;
            case 7:
                readFlie(eventlist);
                break;
            case 8:
                cout << "enter 1 to check the Date" << endl;
                cout << "enter 2 to check the Events of now " << endl;
                cout << "enter 3 to addEvent" << endl;
                cout << "enter 4 to deleteEvent" << endl;
                cout << "enter 5 to clear Events" << endl;
                cout << "enter 6 to store" << endl;
                cout << "enter 7 to cancel the current action" << endl;
                cout << endl;
                break;
            default:
                cout << "pleace Enter the right control number" << endl;
                break;
            }
        }
        if (i < -1||i>8) { cout << " https://youtu.be/dQw4w9WgXcQ "<<endl<<endl; }
    };
    writeFlie(eventlist);
    return 0;
}
