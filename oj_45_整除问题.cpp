/**
 * https://www.nowcoder.com/practice/8e29045de1c84d349b43fdb123ab586a?tpId=40&tqId=21436&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 分解素因数 将a分解素因数 n! 用素因数的倍数来计算
 */

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool primes[1010];
vector<int> primesN;

void init(){
	for (int i = 0; i < 1010; i++){
		primes[i] = true;
	}
	unsigned int i, j;
	for (i = 2; i < 1010; i++){
		if (primes[i] == false)continue;
		for (j = i*i; j < 1010; j += i){
			primes[j] = false;
		}

	}
	for (i = 2; i < 1010; i++){
		if (primes[i])primesN.push_back(i);
	}
}

int calculateK(int n, int a,int p){
	int temp=p;
	int nK = 0;
	int aK = 0;
	while (a != 1){//calculate a's k
		if (a%p == 0){
			aK++;
			a /= p;
		}
		else break;
	}
	if (aK == 0)return 1000000000;
	while (temp <= n){//n!下有多少个数字可以提供p素因数
		nK += n / temp;
		temp *= p;
	}
	return nK / aK;
}


int main(){
	int n,a;
	init();
	while (cin >> n >> a){
		int k = 10000000000;
		int cur = 0;
		int top = sqrt(n) + 1;
		int min;
		do{
			min = calculateK(n, a, primesN[cur++]);
			if (min < k){
				k = min;
			}
		} while (primesN[cur] < n);
		cout << k << endl;
	}
	return 0;
} 