/**
 * https://www.nowcoder.com/practice/f74c7506538b44399f2849eba2f050b5?tpId=40&tqId=21416&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n, m;
	while (cin >> m >> n){
		int lchild;
		int rchild;
		int sum = 1;
		queue<int> q;
		q.push(m);
		do{
			int temp=q.front();
			q.pop();
			lchild = temp * 2;
			rchild = temp * 2 + 1;
			if (lchild <= n){
				sum++;
				q.push(lchild);
			}
			if (rchild <= n){
				sum++;
				q.push(rchild);
			}
		} while (!q.empty());
		cout << sum << endl;
	}
	return 0;
} 