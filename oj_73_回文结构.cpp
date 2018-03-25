/**
 * 一个链表，如1->2->3->4->5->6，给k=2，输出2->1->4->3->6->5；给k=3，输出3->2->1->6->5->4。
 * 也可以全程用vector
 */ 
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct node{
	int data;
	node *next;
};

int main(){
	int n,k;
	while (cin >> n>>k){
		node *head = nullptr, *temp = nullptr;
		stack<node*> s;
		for (int i = 0; i < n; i++){
			node *n=new node;
			cin >> n->data;
			n->next = nullptr;
			if (head == nullptr){
				temp=head = n;
			}
			else{
				temp->next = n;
				temp = n;
			}
		}
		vector<int> v;
		for (int i = 0; head!=nullptr; i++){
			if (s.size() == k){
				for (int j = 0; j < k; j++){
					temp = s.top();
					s.pop();
					v.push_back(temp->data);
				}
			}
			else{
				s.push(head);
				head = head->next;
			}
		}
		
		while (s.size()){
			temp = s.top();
			s.pop();
			v.push_back(temp->data);
		}
		for (int i : v){
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}