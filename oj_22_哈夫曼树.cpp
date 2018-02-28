/**
 * https://www.nowcoder.com/practice/162753046d5f47c7aac01a5b2fcda155?tpId=40&tqId=21520&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 哈夫曼树生成的新节点和 就是路径长度和
 * 同https://www.nowcoder.com/practice/e4c775b0f3ee42a4bb72c26d2e1eef8a?tpId=40&tqId=21510&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <queue>
#include <functional> #include greater
using namespace std;

int main(){
	int n;
	while (cin >> n){
		priority_queue<int, vector<int>, std::greater<int> > q;//两个尖括号要有空格 小根堆 默认为大根堆 std::less 要引用 funcitonal
		for (int i = 0; i < n;i++){
			int temp;
			cin >> temp;
			q.push(temp);
		}
		int res = 0;
		while (q.size()>1){
			int a = q.top();
			q.pop();
			int b = q.top();
			q.pop();
			res += a + b;
			q.push(a + b);
		}
		cout << res << endl;
	}
	return 0;
} 