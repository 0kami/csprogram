/**
 * https://www.nowcoder.com/practice/c5f8688cea8a4a9a88edbd67d1358415?tpId=40&tqId=21441&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool primes[105000];
vector<int> primesN;

void init(){
	for (int i = 0; i < 105000; i++){
		primes[i] = true;
	}
	unsigned int i, j;
	for (i = 2; i < 105000; i++){
		if (primes[i] == false)continue;
        for (j = i*i; j < 105000; j += i){
            primes[j] = false;
        }
		
	}
	for (i = 2; i < 105000; i++){
		if (primes[i])primesN.push_back(i);
	}
}


int main(){
	int n;
	init();
	while (cin >> n){
		cout << primesN[n - 1] << endl;
	}
	return 0;
} 