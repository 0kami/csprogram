/**
 * https://www.nowcoder.com/practice/a5edebf0622045468436c74c3a34240f?tpId=40&tqId=21349&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int a,b;
	while (cin >> a>>b){
		vector<int> vecA;
		vector<int> vecB;
		while (a > 0){
			vecA.push_back(a % 10);
			a /= 10;
		}
		while (b > 0){
			vecB.push_back(b % 10);
			b /= 10;
		}
		int sum = 0;
		for (int i : vecA){
			for (int j : vecB){
				sum += j*i;
			}
		}
		cout << sum << endl;
	}
	return 0;
}