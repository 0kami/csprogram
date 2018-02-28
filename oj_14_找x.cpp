/**
 * https://www.nowcoder.com/practice/069e2130430c41229ab25e47fa0949a6?tpId=40&tqId=21489&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
using namespace std;

int main(){
	int n,x;
	while (cin >> n){
		int *d = new int[n];
		for (int i = 0; i < n; i++){
			cin >> d[i];
		}
		cin >> x;
		int temp = -1;
		for (int i = 0; i < n; i++){
			if (d[i] == x){
				temp = i;
				break;
			}
		}
		cout << temp << endl;
		delete d;
	}
	return 0;
}