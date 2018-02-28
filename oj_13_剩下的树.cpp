/**
 * https://www.nowcoder.com/practice/f5787c69f5cf41499ba4706bc93700a2?tpId=40&tqId=21356&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 
 */
#include <iostream>
using namespace std;

int main(){
	int l,m;
	int trees[10001];
	
	while (cin>>l>>m){
		for (int i = 0; i <= l; i++)
			trees[i] = 1;
		for (int i = 0; i < m; i++){
			int left, right;
			cin >> left >> right;
			for (int j = left; j <= right; j++){
				if (j > l)break;
				if (trees[j] == 1)trees[j] = 0;
			}
		}
		int sum = 0;
		for (int i = 0; i <= l; i++){
			if (trees[i] == 1)sum++;
		}
		cout << sum<<endl;
	}
	return 0;
} 