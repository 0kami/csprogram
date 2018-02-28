/**
 * https://www.nowcoder.com/practice/5b80ab166efa4551844657603227caeb?tpId=40&tqId=21378&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 完全二叉树的性质
 */
#include <iostream>
using namespace std;

int main(){
	int n, m;
	while (cin >> n >> m){
		while (n != m){
			if (n >= 2&&n>m)n/=2;
			else if (m >= 2&&m>n)m /= 2;
		}
		cout << n << endl;
	}
	return 0;
} 