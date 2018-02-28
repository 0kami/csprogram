/**
 * https://www.nowcoder.com/practice/04c8a5ea209d41798d23b59f053fa4d6?tpId=40&tqId=21334&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * http://blog.csdn.net/u013011841/article/details/38870585 
 * 约数定理
 */

#include <iostream>
#include <math.h>
using namespace std;


int main(){
	int n,a;
	while (cin >> n){
		if (n == 0)break;
		while (n-- > 0){
			cin >> a;
			if (a == 1){
				cout << "1" << endl;
				continue;
			}
			int top = sqrt(a);
			int ans = 2;
			if (top*top == a){//25 top=5 只能算一次
				ans++;
				top--;
			}
			for (int i = 2; i <= top; i++){
				if (a%i == 0)ans += 2;
			}
			cout << ans << endl;
		}
	}
	return 0;
} 