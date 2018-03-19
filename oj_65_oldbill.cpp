/**
 * https://www.nowcoder.com/practice/17a30153e092493e8b4d13f321343927?tpId=40&tqId=21426&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 运行时间：3ms 占用内存：496k 
 * 另一种 枚举火鸡的个数
 */
#include <iostream>
using namespace std;

int main(){
	int n, x, y, z;
	while (cin >> n >> x >> y >> z){
		bool flag = true;
		for (int i = 9; flag&&i > 0; i--)
			for (int j = 9; j >= 0; j--){
				int sum = i * 10000 + x * 1000+ y * 100+z*10 + j;
				if ((sum) % n == 0){
					flag = false;
					cout << i << " " << j << " " << sum / n << endl;
					break;
				}
			}
		if (flag)cout << 0 << endl;
	}
	return 0;
}