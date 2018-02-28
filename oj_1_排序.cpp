//https://www.nowcoder.net/practice/508f66c6c93d4191ab25151066cb50ef?tpId=40&tqId=21542&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
//排序 用了冒泡排序
#include <iostream>
using namespace std;

void printArray(int arr[],int size){
	for (int i = 0; i < size; i++){
		cout << arr[i]<<" ";
		//if (i != size - 1)cout << " ";
	}
}

void swap(int *a, int *b){
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

int *BubbleSort(int *arr, int size){
	bool flag=true;
	for (int i = 0; flag && i < size - 1; i++){
		flag = false;
		for (int j = 0; j < size-1-i; j++){
			if (arr[j] > arr[j + 1]){
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
	}
	return arr;
}


int main(){
	int n;
	cin >> n;
	int temp = n;
	int *d = new int[n];
	while (n-- > 0){
		cin >> d[n];
	}
	d = BubbleSort(d, temp);//sort(d, d+temp); 先include algorithm c++的快排算法
	//如果要倒序 sort(d,d+temp,cmp)
	//bool cmp(x,y){return x>y}
	printArray(d, temp);
	return 0;
}