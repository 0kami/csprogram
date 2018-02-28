/**
 * https://www.nowcoder.com/practice/5fd9c28b1ce746dd99287a04d8fa9002?tpId=40&tqId=21494&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */ 
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		if (n <= 1){
			cout << "no" << endl;
			continue;
		}
		int top = sqrt(n)+1;
		bool flag = false;
		for (int i = 2; i < top; i++){
			if (n%i == 0){
				flag = true;
				break;
			}
		}
		if (flag)cout << "no" << endl;
		else cout << "yes" << endl;
	}
	return 0;
}