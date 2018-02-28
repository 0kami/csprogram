/**
 * https://www.nowcoder.com/practice/8c3c5dae2c4a4266ba04f993a18e286b?tpId=40&tqId=21464&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
using namespace std;

int main(){
	int a, b, k;
	while (cin >> a >> b >> k){
		if (a == b&&a == 0)break;
		int tempA = a;
		int tempB = b;
		bool flag = true;
		while (k-- > 0){
			if (a % 10 == b % 10){
				a /= 10;
				b /= 10;
			}
			else{
				flag = false;
				break;
			}
		}
		if (!flag){
			cout << tempA + tempB << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	return 0;
} 