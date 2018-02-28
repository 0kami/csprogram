/**
 * https://www.nowcoder.com/practice/987123efea5f43709f31ad79a318ca69?tpId=40&tqId=21467&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 
 * map init
 * 
 * 
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;



int main(){
	int n,temp,search;
	map<int, int> scores;
	while ((cin>>n)){
		if (n == 0)break;
		for (int i = 0; i < n; i++){
			cin >> temp;
			if (scores.find(temp) == scores.end()){//not found
				scores.insert(make_pair(temp,1));
			}
			else{
				scores[temp]++;
			}
		}
		cin >> search;
		if (scores.find(search) == scores.end()){//not found
			cout << "0"<<endl;
		}
		else{
			cout << scores[search] << endl;
		}
	}
	return 0;
} 