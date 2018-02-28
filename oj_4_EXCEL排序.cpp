/**
 * https://www.nowcoder.net/practice/bf3ec474bb7d410dbb9d5bbcd07a93e5?tpId=40&tqId=21476&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 
 */
#include <iostream>
#include <algorithm> //use sort quick sort algorithm
#include <string.h>
using namespace std;

typedef struct data{
	char num[7];
	char name[9];
	int score;
}data;

bool cmp1(data d1, data d2){// sort num
	return strcmp(d1.num, d2.num) < 0;
}

bool cmp2(data d1, data d2){// sort name
	int d = strcmp(d1.name, d2.name);
	if (d != 0)return d < 0;
	return strcmp(d1.num, d2.num) < 0;
}

bool cmp3(data d1, data d2){// sort num
	if(d1.score!=d2.score)return d1.score<d2.score;
	return strcmp(d1.num, d2.num) < 0;
}

void _main(int n,int c){
	data *d = new data[n];
	for (int i = 0; i < n; i++){
		cin >> d[i].num >> d[i].name >> d[i].score;
	}
	switch (c){
	case 1:
		sort(d, d + n, cmp1);
		break;
	case 2:
		sort(d, d + n, cmp2);
		break;
	case 3:
		sort(d, d + n, cmp3);
		break;
	}
	cout << "Case:" << endl;
	for (int i = 0; i < n; i++){
		cout << d[i].num << " " << d[i].name << " " << d[i].score << endl;
	}
}


int main(){
	int c,n;
	while ((scanf("%d %d", &n,&c)) != EOF){
		_main(n,c);
	}
	return 0;
} 