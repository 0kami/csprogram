/**
 * https://www.nowcoder.com/practice/23c9fe571c1346bb91fdffea8a0b195f?tpId=40&tqId=21450&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 运行时间：3ms 占用内存：432k
 */ 
#include <iostream>
#include <algorithm>
using namespace std;

int village[101];

struct Edge{
	int a, b;
	int cost;
}edge[101];

bool cmp(Edge a, Edge b){//true is not change
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
	int n,m;
	while (cin >> n>>m){
		if (n == 0)break;
		for (int i = 1; i <= m; i++)village[i] = -1;//init
		village[0] = m;//size
		for (int i = 0; i < n; i++){
			cin >> edge[i].a >> edge[i].b >> edge[i].cost;
		}
		sort(edge, edge + n, cmp);
		int sum = 0;
		int cur = 0;
		while (!isSameSet() && cur < n){
			int a = findRoot(edge[cur].a);
			int b = findRoot(edge[cur].b);
			if (a != b){//add new member
				village[a] = b;
				sum += edge[cur].cost;
			}
			cur++;
		}
		if (!isSameSet())cout << "?" << endl;
		else cout << sum << endl;
	}
	return 0;
}