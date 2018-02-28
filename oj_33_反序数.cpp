/**
 * https://www.nowcoder.com/practice/171278d170c64d998ab342b3b40171bb?tpId=40&tqId=21336&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
using namespace std;

int main(){
	char originStr[4];
	while (cin >> originStr){
		for (int i = 3; i >= 0; i--){
			cout << originStr[i];
		}
		cout << endl;
	}
	return 0;
} 