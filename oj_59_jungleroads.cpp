/**
 * https://www.nowcoder.com/practice/75c19b92d6b942f08989b335afbc73c3?tpId=40&tqId=21380&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 运行时间：3ms 占用内存：436k
 * MST
 */
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int village[28];

struct Edge{
	int a, b;
	int cost;
}edge[76];

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
	int n;
	while (cin >> n){
		if (n == 0)break;
		for (int i = 1; i <= n; i++)village[i] = -1;//init
		village[0] = n;//size
		char tmp;
		int k,a,cost;
		int t = 0;
		for (int i = 0; i < n-1; i++){
			cin >> tmp >> k;
			a = tmp - 'A'+1;
			for (int i = 0; i < k; i++){
				cin >> tmp >> cost;
				edge[t].a = a;
				edge[t].b = tmp - 'A'+1;
				edge[t].cost = cost;
				t++;
			}
		}
		sort(edge, edge + t, cmp);
		int sum = 0;
		int cur = 0;
		while (cur < t){
			int a = findRoot(edge[cur].a);
			int b = findRoot(edge[cur].b);
			if (a != b){//add new member
				village[a] = b;
				sum += edge[cur].cost;
			}
			cur++;
		}
		cout<< sum << endl;
	}
	return 0;
}
