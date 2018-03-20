/**
 * 无oj环境
 * 共K个盘
 * 1. 将K-1个盘从第一个柱子移到第三个柱子上，第一根柱子上留下最大的一个盘 计 f(k-1)次
 * 2. 将最大的盘从一移到二 计1次
 * 3. 将K-1个盘从第3移到第1 计 f(k-1)次
 * 4. 将最大的盘从2移到3  计1次
 * 5. 将K-1个盘从第1移到第3 计f(k-1)次
 * 总计 3*f(k-1)+2
 */ 
#include <iostream>

using namespace std;

long long hannuota(int n){
	if (n == 1)return 2;
	else return 3 * hannuota(n - 1) + 2;
}

int main(){
	int n;
	while (cin >> n){
		cout << hannuota(n) << endl;
	}
	return 0;
}