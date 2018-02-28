/**
 * https://www.nowcoder.net/practice/a3417270d1c0421587a60b93cdacbca0?tpId=40&tqId=21439&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 13 February 2018
 * 10 February 2018
 * 计算当前时间与输入的时间的差值，然后根据当前时间的一个礼拜的第几天来算输入的时间
 * time.h use localtime localtime_s
 */  
#include <iostream>
#include <string>
#include <map>
#include <time.h> 
using namespace std;

map<string, int> monthMap = {
	{ "January",1 },
	{ "February", 2 },
	{ "March", 3 },
	{ "April", 4 },
	{ "May", 5 },
	{ "June", 6 },
	{ "July", 7 },
	{ "August", 8 },
	{ "September", 9 },
	{ "October", 10 },
	{ "November", 11 },
	{ "December", 12 }
};
map<int, string> weekMap = {
	{ 0, "Sunday" },
	{ 1, "Monday" },
	{ 2, "Tuesday" },
	{ 3, "Wednesday" },
	{ 4, "Thursday" },
	{ 5, "Friday" },
	{ 6, "Saturday" }
};

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
	int curDays;
	int curWeekDay;

	Date(int day,string month,int year){
		/* online oj 可用 localtime_s vs2013
		time_t now = time(0);
		tm *ltm = localtime(&now);
		*/
		struct tm ltm;
		time_t now = time(0);
		localtime_s(&ltm,&now);
		this->year = year;
		this->month = monthMap[month];
		this->day = day;
		this->days = this->calculateDays(this->year,this->month,this->day);
		this->curDays = this->calculateDays(ltm.tm_year + 1900, ltm.tm_mon + 1, ltm.tm_mday);
		this->curWeekDay = ltm.tm_wday;
	}

	string getWeek(){
		int sub = this->days - this->curDays;
		int t = (this->curWeekDay + sub+7) % 7;
		return weekMap[t];
	}

	int isYeap(int i){
		return (i % 100 != 0 && i % 4 == 0 || i % 400 == 0) ? 1 : 0;
	}
private:
	int calculateDays(int year,int month,int day){
		int days = 0;
		for (int i = 0; i < year; i++){
			days += (normalYear + isYeap(i));
		}
		int flag = isYeap(year);
		for (int i = 1; i < month; i++){
			days += dayOfMonth[i][flag];
		}
		days += day;
		return days;
	}
};

int main(){
	int day, year;
	string month;
	Date *d1;
	while ((cin>>day>>month>>year)){
		d1 = new Date(day,month,year);
		cout << d1->getWeek() << endl;
		delete d1;
	}
	return 0;
}