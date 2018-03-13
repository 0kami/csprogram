/**
 * https://www.nowcoder.com/practice/0160bab3ce5d4ae0bb99dc605601e971?tpId=40&tqId=21359&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 在写的时候 一开始想到的是用flag来标识是否已经经过一次不同城市之间的迁移 发现逻辑会很难处理 一直卡在一个地方 不知道是那里错了
 * 参考了别人的代码 他用的是 当当前节点支持2 想要更新的下一节点支持1 此时 必然在前面的迁移过程发生了 不过城市之间的迁移，即 1->2 之后 后面的迁移只能是2->2
 * 运行时间：12ms 占用内存：640k
 */ 
#include <iostream>
#include <vector>

using namespace std;
#define INF 0x3fffffff
struct Road{
	int end;
	int cost;
};

bool mark[601];
int city[601];
vector<Road> roads[601];
int dis[601];

void dijkstra(){
	int sum = 0;// total time will be costed;
	mark[1] = true;// init set, add city 1
	int cur = 1,pre=0;// current city for starting
	dis[cur] = 0;
	int i;
	while (!mark[2]){// until reach city 2
		int size = roads[cur].size();
		for (i = 0; i < size; i++){
			int end = roads[cur][i].end;
			if (mark[end]||(city[cur]==2&&city[end]==1))continue;// already in set
			if (dis[end]>roads[cur][i].cost + dis[cur]){
				dis[end] = roads[cur][i].cost + dis[cur];
			}
		}
		pre = cur;
		int min = INF;
		for (i = 1; i <= dis[0]; i++){
			if (min > dis[i] && !mark[i]){
				min = dis[i];
				cur = i;
			}
		}
		if (pre!=cur){
			mark[cur] = true;
			sum = min;
		}
		else break;
	}
	if(mark[2])cout << sum<<endl;
	else cout << "-1"<<endl;
}

int main(){
	int n,m;
	while (cin >> n){
		if (n == 0)break;
		// init
		for (int i = 1; i <= n; i++){
			mark[i] = false;
			dis[i] = INF;
			roads[i].clear();
		}
		dis[0] = n;
		city[0] = n;
		// end init
		// input roads
		cin >> m;
		int a, b;
		for (int i = 0; i < m; i++){
			Road r;
			cin >> a >> b >> r.cost;
			if (a == b)continue;
			r.end = b;
			roads[a].push_back(r);
			r.end = a;
			roads[b].push_back(r);
		}// end input roads
		for (int i = 1; i <= n; i++){// support leader
			cin >> city[i];
		}// end support leader
		dijkstra();
	}
	return 0;
}