/**
 * https://www.nowcoder.com/practice/b1f7a77416194fd3abd63737cdfcf82b?tpId=40&tqId=21554&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
 #include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <iomanip>
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


class Date{
public:
	int year;
	int month;
	int day;
	int days;

	Date(int days,int year){
		this->year = year;
		this->days = days;
		this->calculateDay();
	}

	int isYeap(int i){
		return (i % 100 != 0 && i % 4 == 0 || i % 400 == 0) ? 1 : 0;
	}
	
private:
	int calculateDays(int year,int month,int day){
		int days = 0;
		int flag = isYeap(year);
		for (int i = 1; i < month; i++){
			days += dayOfMonth[i][flag];
		}
		days += day;
		return days;
	}
	void calculateDay(){
		int days = this->days;
		int flag = isYeap(this->year);
		for (int i = 1; i < 13; i++){
			if (days > dayOfMonth[i][flag])days -= dayOfMonth[i][flag];
			else{
				this->month = i;
				this->day = days;
				break;
			}
		}
	}
};

int main(){
	int days, year;
	Date *d1;
	while ((cin>>year>>days)){
		d1 = new Date(days,year);
		cout << d1->year//格式化输出
			<<"-"
			<< setw(2)
			<< setfill('0')
			<<d1->month
			<<"-"
			<< setw(2)
			<< setfill('0')
			<<d1->day << endl;
		delete d1;
	}
	return 0;
}