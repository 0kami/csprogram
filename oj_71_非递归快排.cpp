/**
 * 
10
10 9 8 7 6 5 4 3 2 1
10
8 9 10 2 5 6 2 3 7 1
10
8 9 10 2 6 5 2 3 7 1

 */ 

#include <iostream>
#include <stack>
using namespace std;

void push(int left, int right, stack<int*> &s){
	if (left < right){
		int *temp=new int[2];
		temp[0] = left;
		temp[1] = right;
		s.push(temp);
	}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(int* unsorted){
	stack<int*> s;
	int range[2];
	range[0] = 1;
	range[1] = unsorted[0];
	s.push(range);
	while (!s.empty()){//基准位不动
		int *temp = s.top();
		s.pop();
		int left = temp[0];
		int right = temp[1];
		int min = (left + right) / 2;
		int pivot = unsorted[min];// 基准位为中间  直接将第一个元素与中间的交换位置
		unsorted[min] = unsorted[left];
		while (left < right){
			while (left<right && pivot<unsorted[right])right--;//右-》左
			if (left < right){
				unsorted[left++] = unsorted[right];
			}
			while (left<right && pivot>unsorted[left])left++;//左-》右
			if (left<right){
				unsorted[right--] = unsorted[left];
			}
		}
		unsorted[left] = pivot;
		push(temp[0], left - 1, s);
		push(left + 1, temp[1], s);
	}
}

int main(){
	int n;
	int unsorted[100];
	while (cin >> n){
		unsorted[0] = n;
		for (int i = 1; i <= n; i++){
			cin >> unsorted[i];
		}
		quicksort(unsorted);
		for (int i = 1; i <= unsorted[0]; i++){
			cout << unsorted[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

