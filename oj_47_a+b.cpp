/**
 * https://www.nowcoder.com/practice/4c39c984ea3848b48e111b8e71ec1dd4?tpId=40&tqId=21541&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;

void add(string a, string b){
	int flag = 0;
	string ans;
	int aSize = a.size()-1;
	int bSize = b.size()-1;
	int temp,atemp,btemp;
	char t;
	while (aSize >= 0 || bSize >= 0 || flag){// a b每一位都加一遍
		atemp = aSize >= 0 ? (a[aSize] - '0') : 0;
		btemp = bSize >= 0 ? (b[bSize] - '0') : 0;
		temp = atemp + btemp+flag;
		if (temp >= 10){
			t = (temp % 10 + '0');
			flag = 1;
		}
		else{
			t = (temp + '0');
			flag = 0;
		}
		ans = t + ans;
		aSize--;
		bSize--;
	}
	cout << ans << endl;
}

int main(){
	string a,b;
	while (cin >> a>>b){
		add(a, b);
	}
	return 0;
}