/**
 * https://www.nowcoder.com/practice/eda051c1effc4dffa630bc8507f0c5f7?tpId=40&tqId=21562&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <string>
using namespace std;


int main(){
	int n;
	while (cin >> n){
		char t;
		string ans;
		while (n > 0){
			int cur = n%8;
			t = cur + '0';
			ans = t + ans;
			n /= 8;
		}
		cout << ans << endl;
	}
	return 0;
} 