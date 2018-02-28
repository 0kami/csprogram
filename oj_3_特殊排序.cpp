/**
 * https://www.nowcoder.net/practice/57f0f528bff149be9580af66f6292430?tpId=40&tqId=21543&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 
 */
#include <iostream>
#include <algorithm> //use sort quick sort algorithm

using namespace std;

void _main(int n){
	int *nums = new int[n];
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	if (n == 1){
		cout << nums[0] << endl;
		cout << "-1" << endl;
		return;
	}
	sort(nums, nums + n);
	cout << nums[n - 1] << endl;
	for (int i = 0; i < n - 1; i++){
		cout << nums[i];
		if (i != n - 2)cout << " " ;
	}
	cout << endl;
}


int main(){
	int n;
	while ((scanf("%d", &n)) != EOF){
		_main(n);
	}
	return 0;
} 