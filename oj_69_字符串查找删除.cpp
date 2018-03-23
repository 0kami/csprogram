/**
 * https://www.nowcoder.com/practice/d5d0450134db4cb994a1b323a35262da?tpId=40&tqId=21501&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 运行时间：5ms 占用内存：612k
 */

#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	char c;
	while (cin >> s){
		cin >> c;
		int pos = s.find(c, 0);
		while (pos != string::npos){
			s.erase(pos, 1);
			pos = s.find(c, 0);
		}
		cout << s<<endl;
	}
	return 0;
}
