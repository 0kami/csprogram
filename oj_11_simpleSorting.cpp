/**
 * https://www.nowcoder.com/practice/139761e0b59a405786898b7f2db9423f?tpId=40&tqId=21425&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n,temp,size;
	vector<int> vec;
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> temp;
			if (vec.empty()){
				vec.push_back(temp);
			}
			else{
				size = vec.size();
				for (int j = 0; j < size; j++){
					if (vec[j] == temp)break;
					else if (vec[j] < temp&&j != size - 1)continue;
					else if (vec[j] < temp&&j == size - 1)vec.push_back(temp);
					else{
						if (j == 0)
							vec.insert(vec.begin(), temp);
						else
							vec.insert(vec.begin() + j, temp);
						break;
					}
				}
			}
		}
		//print
		for (int j = 0; j < vec.size(); j++){
			cout << vec[j];
			if (j == vec.size() - 1)cout << endl;
			else cout << " ";
		}
		vec.clear();
	}
	return 0;
} 