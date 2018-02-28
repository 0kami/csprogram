/**
 * https://www.nowcoder.com/practice/7f4be54b37a04fdaa4ee545819151114?tpId=40&tqId=21514&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 素数筛法 预先将非素数排除（素数的倍数都不是素数）
 */ 
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool primes[10001];

bool isPrime(int n){
	bool flag = true;
	int top = sqrt(n) + 1;
	for (int i = 2; i < top; i++){
		if (n%i == 0){
			flag = false;
			break;
		}
	}
	return flag;
}

void init(){
	for (int i = 0; i < 10001; i++){
		primes[i] = true;
	}
	for (int i = 2; i < 10001; i++){
		if (primes[i] == false)continue;
        for (int j = i*i; j < 10001; j+=i){//从i*i开始 因为i*k（k<i）已经被前面的素数标记过了
            primes[j] = false;
        }
	}
}

int main(){
	int n;
	init();
	while (cin >> n){
		vector<int> vec;
		for (int i = 2; i < n; i++){
			if (primes[i]&&i%10==1){
				vec.push_back(i);
			}
		}
		int size = vec.size();
		if (size == 0){
			cout << "-1" << endl;
		}
		else{
			for (int i = 0; i < size-1; i++){
				cout << vec[i] << " ";
			}
			cout << vec[size - 1] << endl;
		}
	}
	return 0;
}