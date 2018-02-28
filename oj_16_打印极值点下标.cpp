/**
 * https://www.nowcoder.com/practice/7fd72f8ac7964ba3b8baa8735246e1f1?tpId=40&tqId=21385&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <vector>
using namespace std;

int compare(int a, int b){
	if (a == b)return 0;
	return a > b ? 1 : -1;
}

int main(){
	int k;
	int temp[80];
	int status,t_status;
	vector<int> result;
	while (cin >> k){
		for (int i = 0; i < k; i++){
			cin >> temp[i];
		}
		//check
		result.clear();
		for (int i = 0; i < k; i++){
			if (i == 0){
				status = compare(temp[i], temp[i + 1]);
				if (status != 0)result.push_back(0);
			}
			else if (i == k - 1&&status!=0){
				result.push_back(i);
			}
			else{
				t_status = compare(temp[i], temp[i + 1]);
				if (t_status == -status&&status!=0)result.push_back(i);
				status = t_status;
			}
		}
		int size = result.size();
		for (int i = 0; i < size; i++){
			cout << result[i];
			if (i != size - 1)cout << " ";
		}
		cout << endl;
	}
	return 0;
}
