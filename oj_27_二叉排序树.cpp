/**
 * https://www.nowcoder.com/practice/30a0153649304645935c949df7599602?tpId=40&tqId=21539&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
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
		cout << head->data << endl;
		head->data = n;
		return;
	}
	if (head->data > n){
		if (head->lchild == NULL){
			cout << head->data << endl;
			Node *temp;
			create(temp,n);
			head->lchild = temp;
		}
		else{
			insert(head->lchild, n);
		}
	}
	else{
		if (head->rchild == NULL){
			cout << head->data << endl;
			Node *temp;
			create(temp, n);
			head->rchild = temp;
		}
		else{
			insert(head->rchild, n);
		}
	}
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
	}
	return 0;
}