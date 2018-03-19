/**
 * 
 * 没有oj环境，写个代码 练习BFS
 * 题目名:胜利大逃亡
 * 测试数据:
 */
/* 
Input:
1
3 3 4 20
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0
Output:
    11
 */ 
#include <iostream>
#include <queue>

using namespace std;
struct Node{
	int x, y, z;
	int time;
};

int map[50][50][50];
bool mark[50][50][50];//确认是否已经便利到或是墙 不考虑

void bfs(int x, int y, int z,int t){
	queue<Node> queues;
	Node temp,cur,end;
	temp.x = 0;
	temp.y = 0;
	temp.z = 0;
	temp.time = 0;
	mark[0][0][0] = true;
	end.x = x - 1;
	end.y = y - 1;
	end.z = z - 1;
	queues.push(temp);
	int min = 1000000;
	while (!queues.empty()){
		temp=cur = queues.front();
		queues.pop();
		if (cur.x == x&&cur.y == y&&cur.z == z){//已经到达改点，该点后面的点无需再继续遍历下去
			if (cur.time<min)min = cur.time;
			continue;
		}
		
		if (cur.z > 0 && !mark[cur.x][cur.y][cur.z - 1]){//同一层左移
			temp.z--;
			temp.time++;
			queues.push(temp);
			mark[cur.x][cur.y][cur.z - 1] = true;
			temp = cur;
		}
		if (cur.z < z&& !mark[cur.x][cur.y][cur.z + 1]){//同一层右移
			temp.z++;
			temp.time++;
			queues.push(temp);
			mark[cur.x][cur.y][cur.z + 1] = true;
			temp = cur;
		}
		if (cur.y > 0 && !mark[cur.x][cur.y - 1][cur.z]){//同一层上移
			temp.y--;
			temp.time++;
			queues.push(temp);
			mark[cur.x][cur.y - 1][cur.z] = true;
			temp = cur;
		}
		if (cur.y < y && !mark[cur.x][cur.y + 1][cur.z]){// down
			temp.y++;
			temp.time++;
			queues.push(temp);
			mark[cur.x][cur.y + 1][cur.z] = true;
			temp = cur;
		}
		if (cur.x > 0 && !mark[cur.x - 1][cur.y][cur.z]){// down side
			temp.x--;
			temp.time++;
			queues.push(temp);
			mark[cur.x-1][cur.y][cur.z] = true;
			temp = cur;
		}
		if (cur.x < x && !mark[cur.x+ 1][cur.y][cur.z]){//up side
			temp.x++;
			temp.time++;
			queues.push(temp);
			mark[cur.x +1][cur.y][cur.z] = true;
			temp = cur;
		}
	}
	cout<<min<<endl;
}

int main(){
	int K, x, y, z, t, a, b, c;
	while (cin >> K){
		cin >> a >> b >> c >> t;
		
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				for (int k = 0; k < c; k++){
					cin >> map[i][j][k];
					mark[i][j][k] = (bool)map[i][j][k];
				}
		bfs(a - 1, b - 1, c - 1,t);
	}
	return 0;
}