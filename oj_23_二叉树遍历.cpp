/**
 * https://www.nowcoder.com/practice/6e732a9632bc4d12b442469aed7fe9ce?tpId=40&tqId=21544&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <string>
using namespace std;

typedef struct Node{
	char data;
	Node *lchild,*rchild;
}Node;


Node *recover(string preOrder, string midOrder){
	char c = preOrder.at(0);
	Node *cur=new Node;
	cur->data = c;
	cur->rchild = cur->lchild = NULL;
	int pos = midOrder.find(c);
	if (preOrder.size() == 1)
		return cur;
	string preTemp, midTemp;
	if (pos != 0){
		preTemp = preOrder.substr(1, pos);
		midTemp = midOrder.substr(0, pos);
		cur->lchild = recover(preTemp, midTemp);
	}
	if (pos + 1 != preOrder.size()){
		preTemp = preOrder.substr(pos + 1, preOrder.size());
		midTemp = midOrder.substr(pos + 1, midOrder.size());
		cur->rchild = recover(preTemp, midTemp);
	}
	
	return cur;

}

void postOrderPrint(Node *head){
	if (head->lchild != NULL)
		postOrderPrint(head->lchild);
	if (head->rchild != NULL)
		postOrderPrint(head->rchild);
	cout << head->data;
}

int main(){
	string preOrder;
	string midOrder;
	string postOrder;
	while (cin >> preOrder >> midOrder){
		Node *head;
		head = recover(preOrder, midOrder);
		postOrderPrint(head);
		cout << endl;
	}
	return 0;
} 