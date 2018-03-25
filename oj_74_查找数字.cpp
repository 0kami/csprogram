/**
 * 对于一个M*N的数组，里面的顺序是按照从小到大排的，给你一个数，判断这个数在不在这个数组里。
3 3
1 2 3
4 5 6
7 8 9
10
3 3
1 2 3
4 5 6
7 8 9
5
3 3
1 2 3
4 5 6
7 8 9
9
3 3
1 2 3
4 5 6
7 8 9
1
 */ 
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void find(vector<int> &v, int k,int start,int end){
	int mid = (start + end) / 2;
	if (start > end){
		cout << "Not Found!" << endl;
		return;
	}
	if (v[mid] == k){
		cout << "Found" << endl;
		return;
	}
	else if(v[mid]<k){
		find(v, k, mid + 1, end);
	}
	else if (v[mid] > k){
		find(v, k, start, mid - 1);
	}
}

int main(){
	int m, n,k;
	while (cin >> m >> n){
		vector<int> *v=new vector<int>[m];
		int temp;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cin >> temp;
				v[i].push_back(temp);
			}
		}
		cin >> k;
		bool flag = true;
		for (int i = 0; i < m; i++){
			if (v[i][0]<=k&&v[i][v[i].size()-1]>=k){
				flag = false;
				find(v[i], k,0,v[i].size());
				break;
			}
		}
		if (flag)cout << "Not Found!" << endl;
		delete[] v;
	}
	return 0;
}