/**
 * https://www.nowcoder.com/practice/3d6dd9a58d5246f29f71683346bb8f1b?tpId=40&tqId=21455&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <queue>
#include <string>
#include <math.h>
using namespace std;

typedef struct Node{
	char data;
	Node *lchild, *rchild;
}Node;

void create(Node* &node,char data=-1){
	node = new Node;
	node->data = data;
	node->lchild = node->rchild = NULL;
}

void insert(Node* head,char n){
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
	else if (head->data == n){
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

void prePrint(Node* node,string &ans){
	if (node == NULL)return;
	ans += node->data;
	prePrint(node->lchild, ans);
	prePrint(node->rchild, ans);
}

void midPrint(Node* node, string &ans){
	if (node == NULL)return;
	midPrint(node->lchild, ans);
	ans += node->data;
	midPrint(node->rchild, ans);
}

void postPrint(Node* node, string &ans){
	if (node == NULL)return;
	postPrint(node->lchild, ans);
	postPrint(node->rchild, ans);
	ans += node->data;
}

void check(string* str){
	Node *head;
	string line;
	create(head);
	cin >> line;
	for (char c : line){
		insert(head, c);
	}

	prePrint(head, str[0]);
	midPrint(head, str[1]);
}

int main(){
	int n,t;
	while (cin >> n){
		if (n == 0)break;
		string str[2];
		check(str);
		while (n-- > 0){
			string temp[2];
			check(temp);
			if (temp[0] == str[0] && temp[1] == str[1])cout << "YES"<<endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
} 