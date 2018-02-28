/**
 * https://www.nowcoder.net/practice/cc2291ab56ee4e919efef2f4d2473bac?tpId=40&tqId=21499&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 
 */
#include <iostream>
#include <algorithm> //use sort quick sort algorithm
#include <string.h>
using namespace std;


bool cmp(char c1, char c2){

	return strcmp(&c1, &c2) < 0;
}


int main(){
	char c[200];
	int length ;
	while ((cin>>c)){
		length = strlen(c);
		sort(c, c + length, cmp);
		cout << c << endl;
	}
	return 0;
}