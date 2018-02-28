/**
 * https://www.nowcoder.com/practice/fe8bff0750c8448081759f3ee0d86bb4?tpId=40&tqId=21358&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 坑点 把num当成字符串来比较时 100和50 是50比较大 应为比较的是1 和5 （strcmp）
 * 2分查找 while(left<right) 
 */
#include <iostream>
#include <string>
using namespace std;

typedef struct person{
	int num;
	string name;
	string gender;
	int age;
}person;

void print(person &p){
	cout << p.num
		<< " "
		<< p.name
		<< " "
		<< p.gender
		<< " "
		<< p.age
		<< endl;
}

int compare_f(int a, int b){
	if (a == b)return 0;
	return a > b ? 1 : -1;
}

void find(int search, person *persons, int n){//二分查找
	int base=0, top=n, mid;
	bool flag = true;
	while (base <= top){
		mid = (base + top) / 2;
		int cmp = compare_f(search, persons[mid].num);
		if (cmp == 0){
			print(persons[mid]);
			flag = false;
			break;
		}
		else if (cmp > 0){
			base = mid + 1;
		}
		else if (cmp < 0){
			top = mid - 1;
		}
	}
	if (flag)cout << "No Answer!" << endl;
}

int main(){
	int n,m;
	int search;
	person *persons;
	while (cin >> n){
		persons = new person[n];
		for (int i = 0; i < n; i++){
			cin >> persons[i].num >> persons[i].name >> persons[i].gender >> persons[i].age;
		}
		cin >> m;
		while (m-- > 0){
			cin >> search;
			find(search, persons, n);
		}
		delete [] persons;
	}
	return 0;
} 