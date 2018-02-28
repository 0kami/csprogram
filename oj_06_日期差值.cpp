/**
 * https://www.nowcoder.net/practice/ccb7383c76fc48d2bbc27a2a6319631c?tpId=40&tqId=21442&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <cmath>
using namespace std;

int dayOfMonth[13][2] = {
	0, 0,
	31, 31,
	28, 29,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31
};

int normalYear = 365;


class Date{
public:
	int year;
	int month;
	int day;
	int days;
	Date(int date){
		days = 0;
		year = date / 10000;
		month = (date / 100) % 100;
		day = date % 100;
		for (int i = 0; i < year; i++){
			days += (365 + isYeap(i));
		}
		int flag = isYeap(year);
		for (int i = 1; i < month; i++){
			days += dayOfMonth[i][flag];
		}
		days += day;
	}
	int operator -(const Date &d){
		int temp = days > d.days ? days - d.days : d.days - days;
		return temp + 1;
	}
	int isYeap(int i){
		return (i % 100 != 0 && i % 4 == 0 || i % 400 == 0) ? 1 : 0;
	}
};

int main(){
	int date1, date2;
	Date *d1, *d2;
	int temp;
	while ((cin>>date1>>date2)){
		d1 = new Date(date1);
		d2 = new Date(date2);
		temp = d1->days > d2->days ? d1->days - d2->days : d2->days - d1->days;
		cout << temp+1 << endl;
        delete d1;
        delete d2;
	}
	return 0;
} 