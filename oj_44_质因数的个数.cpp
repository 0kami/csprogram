/**
 * https://www.nowcoder.com/practice/20426b85f7fc4ba8b0844cc04807fbd9?tpId=40&tqId=21338&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool primes[100001];
vector<int> primesN;
void init(){
	for (int i = 0; i < 100001; i++){
		primes[i] = true;
	}
	unsigned int i, j;
	for (i = 2; i < 100001; i++){
		if (primes[i] == false)continue;

		for (j = i*i; j < 100001; j += i){
			primes[j] = false;
		}

	}
	for (i = 2; i < 100001; i++){
		if (primes[i])primesN.push_back(i);
	}
}

int main(){
	int n;
	init();
	while (cin >> n){
		int times = 0;
		int i = 0;
		while (n != 1){
			if (primesN[i] > sqrt(n)){
				times++;
				break;
			}
			if (n%primesN[i] == 0){
				times++;
				n /= primesN[i];
				
			}
			else{
				i++;
			}
		}
		cout << times << endl;
	}
	return 0;
} 