/**
 * https://www.nowcoder.com/practice/b744af632ac4499aa485d7bb048bb0aa?tpId=40&tqId=21556&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct BigInteger{
	vector<int> digits;
	void set(string x){
		for (char c : x){
			digits.push_back(c - '0');
		}
	}
	void print(){
		for (int i : digits)
			cout << i;
		cout << endl;
	}
}BigInteger;

bool cmp(BigInteger a, BigInteger b){//true not change a&b position
	int sizeA = a.digits.size();
	int sizeB = b.digits.size();
	if (sizeA != sizeB)return sizeA<sizeB;
	for (int i = 0; i < sizeA; i++){
		if (a.digits[i] == b.digits[i])continue;
		return a.digits[i] < b.digits[i];
	}
	return true;
}

int main(){
	int n;
	BigInteger bigInteger[101];
	while (cin >> n){
		string tmp;
		for (int i = 0; i < n; i++){
			cin >> tmp;
			bigInteger[i].set(tmp);
		}
		sort(bigInteger, bigInteger + n, cmp);
		for (int i = 0; i < n; i++){
			bigInteger[i].print();
		}
	}
	return 0;
} 