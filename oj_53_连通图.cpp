/**
 * https://www.nowcoder.com/practice/569e89823a5141fe8a11ab7d4da21edf?tpId=40&tqId=21506&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 运行时间：3ms 占用内存：384k
 */ 
#include <iostream>
using namespace std;
int city[1001];
int findRoot(int a){//是否同属于一个集合 并优化集合
	if (city[a] == -1)return a;
	else{
		int tmp = findRoot(city[a]);
		city[a] = tmp;
		return tmp;
	}
}

int main(){
	int n,m;
	while (cin >> n>>m){
		for (int i = 1; i <= n; i++)city[i] = -1;
		int a, b;
		for (int i = 0; i < m; i++){
			cin >> a >> b;
			int rootA = findRoot(a);
			int rootB = findRoot(b);
			if (rootA != rootB)city[rootA] = rootB;//根节点合并
		}
		int ans = -1;
		for (int i = 1; i <= n; i++){
			if (city[i] == -1)ans++;
		}
		if(ans==0)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}