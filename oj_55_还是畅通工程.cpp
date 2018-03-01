/**
 * https://www.nowcoder.com/practice/d6bd75dbb36e410995f8673a6a2e2229?tpId=40&tqId=21479&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 运行时间：4ms 占用内存：440k
 */
#include <iostream>
#include <algorithm>
using namespace std;

int village[101];

struct Edge{
	int a, b;
	int cost;
}edge[5000];

bool cmp(Edge a, Edge b){
	return a.cost < b.cost;
}

int findRoot(int x){
	if (village[x] == -1)return x;
	int tmp = findRoot(village[x]);
	village[x] = tmp;
	return tmp;
}

bool isSameSet(){
	int res = 0;
	for (int i = 1; i <= village[0]; i++){
		if (village[i] == -1)res++;
		if (res > 1)return false;
	}
	return true;
}

int main(){
	int n;
	while (cin >> n){
		if (n == 0)break;
		int lines = n*(n - 1) / 2;
		for (int i = 1; i <= n; i++)village[i] = -1;//init
		village[0] = n;//size
		for (int i = 0; i < lines; i++){
			cin >> edge[i].a >> edge[i].b >> edge[i].cost;
		}
		sort(edge, edge + lines, cmp);
		int sum = 0;
		int cur = 0;
		while (!isSameSet() && cur < lines){
			int a = findRoot(edge[cur].a);
			int b = findRoot(edge[cur].b);
			if (a != b){//add new member
				village[a] = b;
				sum += edge[cur].cost;
			}
			cur++;
		}
		cout << sum << endl;
	}
	return 0;
}
 