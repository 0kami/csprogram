/**
 * https://www.nowcoder.com/practice/cef727d0af33479c9fb4a9c120702414?tpId=40&tqId=21403&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */ 
#include <iostream>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		int sum = 0;
		while (sum >= 10 || sum == 0){
			if (sum >= 10){
				n = sum;
				sum = 0;
			}
			while (n > 0){
				sum += n % 10;
				n /= 10;
			}
		}
		
		cout << sum << endl;
	}
	return 0;
}