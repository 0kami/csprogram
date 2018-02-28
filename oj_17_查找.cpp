/**
 * https://www.nowcoder.com/practice/d93db01c2ee44e8a9237d63842aca8aa?tpId=40&tqId=21531&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 排序后二分查找
 */

#include <iostream>
#include <algorithm>
using namespace std;

int compare(int a, int b){
	if (a == b)return 0;
	return a > b ? 1 : -1;
}
void _search(int data[], int size, int search){
	int base = 0, top = size,mid;
	bool flag = true;
	while (base <= top){
		mid = (base + top) / 2;
		int cmp = compare(search, data[mid]);
		if (cmp == 0){
			cout << "YES" << endl;
			flag = false;
			break;
		}
		else if (cmp > 0)base = mid + 1;
		else top = mid - 1;
	}
	if (flag)cout << "NO" << endl;
}

int main(){
	int n, m;
	int data[101];
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> data[i];
		}
		sort(data, data + n);
		cin >> m;
		int t;
		while (m-- > 0){
			cin >> t;
			_search(data, n, t);
		}
	}
	return 0;
} 