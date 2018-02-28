/**
 * https://www.nowcoder.com/practice/e91982a145944ceab6bb9a4a508e0e26?tpId=40&tqId=21511&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

int main(){
	int n;
	int temp;
	while (cin >> n){
		stack<int> s;
		string order;
		while (n-- > 0){

			cin >> order;
			if (order == "P"){
				cin >> temp;
				s.push(temp);
				cout << endl;
			}
			else if (order == "A"){
				if (s.empty())cout << "E" << endl;
				else cout << s.top() << endl;
			}
			else if (!s.empty() && order == "O"){
				s.pop();
			}
			else if (s.empty() && order == "O"){
				cout << endl;
			}
		}


	}
	return 0;
} 