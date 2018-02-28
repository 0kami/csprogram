/**
 * https://www.nowcoder.com/practice/b42cfd38923c4b72bde19b795e78bcb3?tpId=40&tqId=21555&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

typedef struct Node{
	int data;
	Node *lchild, *rchild;
}Node;

void create(Node* &node,int data=-1){
	node = new Node;
	node->data = data;
	node->lchild = node->rchild = NULL;
}

void insert(Node* head,int n){
	if (head->data < 0){
		head->data = n;
		return;
	}
	if (head->data > n){
		if (head->lchild == NULL){
			Node *temp;
			create(temp,n);
			head->lchild = temp;
		}
		else{
			insert(head->lchild, n);
		}
	}
	else if (head->data == n){//舍去重复元素
		return;
	}
	else{
		if (head->rchild == NULL){
			Node *temp;
			create(temp, n);
			head->rchild = temp;
		}
		else{
			insert(head->rchild, n);
		}
	}
}

void prePrint(Node* node,int pre){
	if (node == NULL)return;
	if (node->data != pre)cout << node->data << " ";
	prePrint(node->lchild, node->data);
	prePrint(node->rchild, node->data);
}

void midPrint(Node* node, int pre){
	if (node == NULL)return;
	midPrint(node->lchild, node->data);
	if (node->data != pre)cout << node->data << " ";
	midPrint(node->rchild, node->data);
}

void postPrint(Node* node, int pre){
	if (node == NULL)return;
	postPrint(node->lchild, node->data);
	postPrint(node->rchild, node->data);
	if (node->data != pre)cout << node->data << " ";
}

int main(){
	int n,t;
	while (cin >> n){
		Node *head;
		create(head);
		while (n-- > 0){
			cin >> t;
			insert(head,t);
		}
		prePrint(head, -1);
		cout << endl;
		midPrint(head, -1);
		cout << endl;
		postPrint(head, -1);
		cout << endl;
	}
	return 0;
} 