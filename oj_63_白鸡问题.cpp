/**
 * https://www.nowcoder.com/practice/01d161052db64c249a47fc723b4fd5db?tpId=40&tqId=21487&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 运行时间：3ms 占用内存：480k
 */ 
#include <iostream>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		int remainMoney,temp;
		for (int i = 0; i <= 100; i++){
			int remainI = 100 - i;
			remainMoney = n - i * 5;
			for (int j = 0; j <= remainI; j++){
				temp = remainMoney- j * 3;
				if (temp > 0 && 100 <= i + j + temp * 3)
					cout << "x=" << i << ",y=" << j << ",z=" << 100 - i - j << endl;
			}
		}
	}
	return 0;
}