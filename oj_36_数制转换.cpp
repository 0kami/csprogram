/**
 * https://www.nowcoder.com/practice/8ef02ef8571b417d8c311a87861f7a03?tpId=40&tqId=21387&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
 #include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
	int a, b;
	string n;
	while (cin >> a >> n >> b){
		long temp = 0;
		string ans;
		int size = n.size();
		int j = 0;
		for (int i = size - 1; i >= 0; i--,j++){
			char c = n.at(i);
			if (c - 'a' >= 0){//note =
				temp += ((c - 'a') + 10)*pow(a, j);
			}
			else if (c - 'A' >= 0){
				temp += ((c - 'A') + 10)*pow(a, j);
			}
			else if (c - '0' >= 0){
				temp += ((c - '0'))*pow(a, j);
			}
		}
		char t;
 		while (temp > 0){
 			int cur = temp%b;
			if (cur >= 10){
				t = cur % 10 + 'A';
			}
			else{
				t = cur + '0';
			}
			ans = t + ans;
			temp /= b;
		}
		cout << ans << endl;
	}
	return 0;
}