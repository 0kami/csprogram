/**
 * 无oj 删除  / * * /
 */ 
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	string annotationL="/*";
	string annotationR = "*/";
	while (cin >> s){
		
		int posL = s.find(annotationL, 0);
		while (posL != string::npos){
			int posR = s.find(annotationR, posL);
			s.erase(posL, posR+2-posL);
			posL = s.find(annotationL, 0);
		}
		cout << s<<endl;
	}
	return 0;
}