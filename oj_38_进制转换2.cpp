/**
 * https://www.nowcoder.com/practice/deb19498bc644f53a6a99905ef5ee01d?tpId=40&tqId=21411&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 16=>10
 */
#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int main(){
	string n;
	while (cin >> n){
		int size = n.size();
		int j = 0;
		int temp=0;
		for (int i = size - 1; i >= 2; i--, j++){
			char c = n.at(i);
			if (c - 'A' >= 0){//note =
				temp += ((c - 'A') + 10)*pow(16, j);
			}
			else if (c - '0' >= 0){
				temp += ((c - '0'))*pow(16, j);
			}
		}
		cout << temp << endl;
	}
	return 0;
} 