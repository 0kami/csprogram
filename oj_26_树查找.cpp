/**
 * https://www.nowcoder.com/practice/9a10d5e7d99c45e2a462644d46c428e4?tpId=40&tqId=21526&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

typedef struct Node{
	int data;
	Node *lchild, *rchild;
}Node;

void create(Node* &n){
	int m;
	n = new Node;
	cin >> n->data;
	n->lchild = n->rchild = NULL;
}

Node *build(int n){//建立时按照遍历的思路
	queue<Node*> q;
	Node *head;
	create(head);
	q.push(head);
	n--;
	Node *cur, *lchild, *rchild;
	while (n-- > 0){
		cur = q.front();
		q.pop();
		create(lchild);
		cur->lchild = lchild;
		q.push(lchild);
		if (n-- > 0){
			create(rchild);
			cur->rchild = rchild;
			q.push(rchild);
		}
	}
	return head;
}

void print(Node* &head,int size,int d){
	queue<Node*> q;
	q.push(head);
	int i = 0;
	int base = pow(2, d - 1) - 1;//上下限 二叉树性质
	int top = pow(2, d) - 1;
	bool flag = true;
	if (size < base + 1){
		cout << "EMPTY" << endl;
		return;
	}
	while (i < size){
		Node* cur = q.front();
		q.pop();
		i++;
		if (i > base&&i < top){
			cout << cur->data << " ";
		}
		else if (i == top){
			cout << cur->data << endl;
			break;
		}
		if(cur->lchild!=NULL)q.push(cur->lchild);
		if (cur->rchild != NULL)q.push(cur->rchild);
	}
	
}

int main(){
	int n,d;
	while (cin >> n){
		Node *head=build(n);
		cin >> d;
		print(head, n, d);
	}
	return 0;
} 