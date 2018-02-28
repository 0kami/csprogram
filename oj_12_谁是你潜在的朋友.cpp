/**
 * https://www.nowcoder.com/practice/0177394fb25b42b48657bc2b1c6f9fcc?tpId=40&tqId=21360&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 
 */
#include <iostream>
using namespace std;

int main(){
	int n,m;
	int books[200] = { 0 };
	while (cin>>n>>m){
		int *persons=new int[n];
		for (int i = 0; i < n; i++){
			int temp;
			cin >> temp;
			books[temp]++;
			persons[i] = temp;
		}
		for (int i = 0; i < n; i++){
			int temp = books[persons[i]]-1;
			if (temp > 0)cout << temp;
			else cout << "BeiJu";
			cout << endl;
		}
	}
	return 0;
} 