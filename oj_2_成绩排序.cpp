/**
 * 成绩排序 https://www.nowcoder.net/practice/0383714a1bb749499050d2e0610418b1?tpId=40&tqId=21333&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 当成绩相同时，要保持插入顺序，需选定稳定的排序算法
 * 稳定的排序算法:插入排序(n^2)、冒泡排序(n^2)、归并排序(nlog2n)、基数排序
 * 不稳定的排序算法:选择排序(n^2)、希尔排序、快速排序(nlog2n)、堆排序(nlog2n)
 */ 
#include <iostream>
#include <string>
using namespace std;

typedef struct student{
	string name;
	int score;
	bool operator < (const student &s) const{//重写算符
		return score < s.score;
	}
	bool operator >(const student &s) const{
		return score > s.score;
	}
}student;

class Sort{
public:
	/*
		冒泡排序
        范型
	*/
	template <class T> static T *BubbleSort(T *arr, int size, int order = 1){
		bool flag = true;
		for (int i = 0; flag && i < size - 1; i++){
			flag = false;
			for (int j = 0; j < size - 1 - i; j++){
				if (order == 1){//升序
					if (arr[j] > arr[j + 1]){
						swap(&arr[j], &arr[j + 1]);
						flag = true;
					}
				}
				else{
					if (arr[j] < arr[j + 1]){
						swap(&arr[j], &arr[j + 1]);
						flag = true;
					}
				}
			}
		}
		return arr;
	}
    /**
     * 范性
     */

	template <class T> static void swap(T *a, T *b){
		T temp;
		temp = *b;
		*b = *a;
		*a = temp;
	}

};

void _main(int n){
	int order;
	int size = n;
	cin >> order;
	student *students = new student[n];
	int i = 0;
	while (n-- > 0){
		cin >> students[i].name >> students[i].score;
		i++;
	}
	students=Sort::BubbleSort(students, size, order);
	for (i = 0; i < size; i++){
		cout << students[i].name << " " << students[i].score<<endl;
	}
}

int main(){
	int n;
	while ((scanf("%d", &n)) != EOF){//vs2013 不能用scanf 用scanf_s代替
		_main(n);
	}
	return 0;
}

