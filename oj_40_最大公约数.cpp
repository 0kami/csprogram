/**
 * https://www.nowcoder.com/practice/20216f2c84bc438eb5ef05e382536fd3?tpId=40&tqId=21492&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
using namespace std;

int main(){
	int a,b;
	while (cin >> a>>b){
		int r;
		while (b > 0){
			r = a%b;
			a = b;
			b = r;
		}
		cout << a << endl;
	}
	return 0;
}