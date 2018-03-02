/**
 * https://www.nowcoder.com/practice/e372b623d0874ce2915c663d881a3ff2?tpId=40&tqId=21483&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 最短路径 floyd(n^3 适合200以下) && dijkstra
 * 运行时间：108ms 占用内存：8048k
 */ 
#include <iostream>
#include <vector>
using namespace std;

struct Edge{
	int position;//next position
	int cost;
	int distance;
};
vector<Edge> ascs[1001];
int dist[1001];
int cost[1001];
bool mark[1001];
const int MAX = 1215752192;

Edge getMin(){
	Edge min;
	min.position = MAX;
	min.distance = MAX;
	min.cost = MAX;
	for (int i = 1; i <= dist[0]; i++){
		if (mark[i])continue;
		if (min.distance > dist[i] || (min.distance == dist[i] && min.cost > cost[i])){
			min.position = i;
			min.distance = dist[i];
			min.cost = cost[i];
		}
	}
	return min;
}

void dijkstra(int s){
	mark[s] = true;
	Edge min;
	min.position = s;//第一轮
	dist[min.position] = 0;
	cost[min.position] = 0;
	int n = dist[0];
	for (int i = 1; i<dist[0]; i++){//n-1轮
		for (Edge t : ascs[min.position]){//以min.position为起点 找最近的一个点
			if (mark[t.position])continue;//已经有这个点在最短路径上
			if (dist[t.position] == MAX ||//当前这个点的dist上为max 遍历到的值肯定会比max小
				dist[t.position] > dist[min.position] + t.distance ||
				(dist[t.position] == dist[min.position] + t.distance&&cost[t.position] > cost[min.position] + t.cost)){
				dist[t.position] = dist[min.position] + t.distance;
				cost[t.position] = cost[min.position] + t.cost;
			}
		}
		min = getMin();//将最小值加入集合,作为下一个起点
		if (min.position == MAX)break;
		mark[min.position] = true;
	}
}

int main(){
	int n, m;
	while (cin >> n >> m){
		if (n == 0 && m == 0)break;
		for (int i = 1; i <= n; i++){//init
			dist[i] = MAX;//can not reach
			cost[i] = MAX;
			mark[i] = false;
			ascs[i].clear();
		}
		dist[0] = n;
		int tmp,t;
		while (m-- > 0){
			cin >> tmp;
			Edge *e = new Edge;
			cin >> e->position >> e->distance >> e->cost;
			ascs[tmp].push_back(*e);
			t = tmp;
			tmp = e->position;
			e->position = t;
			ascs[tmp].push_back(*e);
		}
		int s;
		cin >> s >> t;
		dijkstra(s);
		cout << dist[t] << " " << cost[t] << endl;
	}
	return 0;
}