/**
 * https://www.nowcoder.com/practice/41b14b4cd0e5448fb071743e504063cf?tpId=40&tqId=21371&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 运行时间：4ms 占用内存：528k
 * 最小生成树 自己生成边数据
 */ 
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int freckles[101];

struct Dot{
	double x, y;
	int order;
}dot[101];

struct Edge{
	Dot a, b;
	double cost;
	void calculate(){
		if (a.x == b.x)
			cost = abs(a.y - b.y);
		else if (a.y == b.y)
			cost = abs(a.x - b.x);
		else
			cost = sqrt(pow(a.x - b.x, 2)+pow(a.y - b.y, 2));
	}
}edge[5000];

bool cmp(Edge a, Edge b){//true is not change
	return a.cost < b.cost;
}

int findRoot(int x){
	if (freckles[x] == -1)return x;
	int tmp = findRoot(freckles[x]);
	freckles[x] = tmp;
	return tmp;
}

bool isSameSet(){
	int res = 0;
	for (int i = 1; i <= freckles[0]; i++){
		if (freckles[i] == -1)res++;
		if (res > 1)return false;
	}
	return true;
}

int main(){
	int n;
	while (cin >> n){
		if (n == 0)break;
		for (int i = 1; i <= n; i++)freckles[i] = -1;//init
		freckles[0] = n;//size
		for (int i = 0; i < n; i++){
			cin >> dot[i].x>>dot[i].y;
			dot[i].order = i + 1;
		}
		int t = 0;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++){
				edge[t].a = dot[i];
				edge[t].b = dot[j];
				edge[t].calculate();
				t++;
			}
		sort(edge, edge + t, cmp);
		double sum = 0;
		int cur = 0;
		while (!isSameSet() && cur < t){
			int a = findRoot(edge[cur].a.order);
			int b = findRoot(edge[cur].b.order);
			if (a != b){//add new member
				freckles[a] = b;
				sum += edge[cur].cost;
			}
			cur++;
		}
		cout <<fixed
			<<setprecision(2)
			<< sum << endl;
	}
	return 0;
}