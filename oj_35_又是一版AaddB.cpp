/**
 * https://www.nowcoder.com/practice/9255c05d45b8406c9b588d7c57aa920b?tpId=40&tqId=21466&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <string>
using namespace std;

int main(){
	long long m,a,b;
	while (cin >> m ){
		if (m == 0)break;
		cin >> a >> b;
		long long sum = a + b;
		string ans;
		string cur;
		int i = 0;
		do{
			cur = ('0' + sum % m);
			ans = cur + ans;
			i++;
			sum /= m;
		}while (sum > 0);
		cout << ans << endl;
	}
	return 0;
} 