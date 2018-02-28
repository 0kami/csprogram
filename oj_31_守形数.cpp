/**
 * https://www.nowcoder.com/practice/99e403f8342b4d0e82f1c1395ba62d7b?tpId=40&tqId=21549&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		int sp = pow(n, 2);
		bool flag = true;
		while (n > 0){
			if (sp % 10 == n % 10){
				sp /= 10;
				n /= 10;
			}
			else{
				flag = false;
				break;
			}
		}
		if (flag)cout << "Yes!" << endl;
		else cout << "No!" << endl;
	}
	return 0;
} 