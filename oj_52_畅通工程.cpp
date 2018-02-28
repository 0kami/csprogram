/**
 * https://www.nowcoder.com/practice/4878e6c6a24e443aac5211d194cf3913?tpId=40&tqId=21457&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 考察并查集 根与根之间相互合并
 * 运行时间：4ms
 * 占用内存：386k
 */ 
#include <iostream>
using namespace std;
int city[1000];
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
		if (n == 0)break;
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
		cout << ans << endl;
	}
	return 0;
}