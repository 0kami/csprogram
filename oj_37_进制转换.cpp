/**
 * https://www.nowcoder.com/practice/0337e32b1e5543a19fa380e36d9343d7?tpId=40&tqId=21361&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 10=>2
 */
#include <iostream>
#include <string>
using namespace std;

void div(string &num, int d){//大整数除法
	string temp;
	int flag = 0;
	for (char c : num){
		int intC = (c - '0')+flag*10;
		flag = intC % 2;
		temp += (intC >> 1) + '0';
	}
	flag = 0;
	num = "";
	for (char c : temp){
		if (c == '0'&&flag == 0)continue;
		else{
			num += c;
			flag = 1;
		}
	}
}

int main(){
	string n;
	while (cin >> n){
		string ans;
		char t;
		int cur;
 		do{
 			cur = (n.at(n.size()-1)-'0')%2;
			t = cur + '0';
			ans = t + ans;
			div(n, 2);
		} while (n.size() > 0);
		cout << ans << endl;
	}
	return 0;
}  