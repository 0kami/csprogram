/**
 * https://www.nowcoder.com/completeSubmissionInfo?submissionId=21961223
 * Not Finish
 * temp file
 */
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
const int MAX = 600;

struct Bin{
	vector<int> digits;//bin
	int s;
	Bin(){
		s = 0;
	}
	bool operator>(const Bin &a){
		if (s != a.s)return s>a.s;
		else if (s == a.s&&s == MAX)return false;
		if (digits.size() != a.digits.size())return digits.size() > a.digits.size();
		for (int i = 0; i <= digits.size();i++){
			if (digits[i] != a.digits[i])return digits[i] > a.digits[i];
		}
		return false;
	}
	Bin operator+(const Bin &a){
		Bin ret;
		int sizea = a.digits.size()-1;
		int sizeb = digits.size()-1;
		int flag=0;
		
		while (sizea >= 0 || sizeb >= 0 || flag){
			int tmp = (sizea >= 0 ? a.digits[sizea] : 0) + (sizeb >= 0 ? digits[sizeb] : 0) + flag;
			if (tmp >= 2){
				flag = tmp / 2;
				tmp %= 2;
			}
			else{
				flag = 0;
			}
			ret.digits.insert(ret.digits.begin(), tmp);
			sizea--;
			sizeb--;
		}
		ret.s = ret.digits.size();
		return ret;
	}
	int integer(){
		if (digits.size() == 0)return -1;
		int t = 0;
		int ans = 0;
		for (int i = digits.size()-1; i >= 0; i--){
			t = (ans + digits[i]);
			if (i == 0)ans = t;
			else ans = t * 2;
			ans %= 100000;
		}
		return ans;
	}
};

struct Edge{
	int pos;
	Bin cost;
};

vector<Edge> ascs[101];
Bin city[101];
bool mark[101];

void dijkstra(int n){
	
	int cur = 0;
	mark[cur] = true;
	for (int i = 1; i < n; i++){
		for (Edge t : ascs[cur]){
			if (mark[t.pos])continue;
			if (city[t.pos].s == MAX ||
				city[t.pos]>city[cur] + t.cost){
				city[t.pos] = city[cur] + t.cost;
			}
		}
		Bin min;
		min.s = MAX;
		for (int i = 0; i < n; i++){
			if (mark[i])continue;
			if (min > city[i]){
				min = city[i];
				cur = i;
			}
		}
		mark[cur] = true;
	}
}

int main(){
	int n, m;
	while (cin >> n >> m){
		int a, b;
		for (int i = 0; i < n; i++){
			ascs[i].clear();
			mark[i] = false;
			city[i].s = MAX;
		}
		for (int i = 0; i < m; i++){
			cin >> a >> b;
			Edge t;
			Bin *bin=new Bin;
			for (int j = 0; j < i; j++)
				bin->digits.insert(bin->digits.begin(), 0);
			bin->digits.insert(bin->digits.begin(), 1);
			bin->s = i + 1;
			t.pos = b;
			t.cost= *bin;
			ascs[a].push_back(t);
			t.pos = a;
			ascs[b].push_back(t);
		}
		
		dijkstra(n);
		for (int i = 1; i < n; i++){
			cout << city[i].integer() << endl;
		}
	}
	return 0;
}
 