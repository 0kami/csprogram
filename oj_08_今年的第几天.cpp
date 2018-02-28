/**
 * https://www.nowcoder.com/practice/ae7e58fe24b14d1386e13e7d70eaf04d?tpId=40&tqId=21350&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <string>
#include <map>
#include <ctime>
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

	Date(int day,int month,int year){
		this->year = year;
		this->month = month;
		this->day = day;
		this->days = this->calculateDays(this->year,this->month,this->day);
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
};

int main(){
	int day, year;
	int month;
	Date *d1;
	while ((cin>>year>>month>>day)){
		d1 = new Date(day,month,year);
		cout << d1->days << endl;
		delete d1;
	}
	return 0;
} 