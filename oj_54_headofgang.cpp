/**
 * https://www.nowcoder.com/practice/a31b1ea6c87647bc86e382acaf21c53b?tpId=40&tqId=21469&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 运行时间：6ms 占用内存：384k
 * map 内部自己按键排序
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef struct {
	string root;
	int weight;
	int out;//use for calculating a gang's total times
	void init(int weight,int type){//type=1 signify out
		root = "";
		if(type==1)out = weight;
		else out = 0;
		this->weight = weight;
	}
}Attributes;

map<string, Attributes> persons;// {name:root name}
string findRoot(string a,string max){//是否同属于一个集合 并优化集合
	if (persons[a].root == ""){
		if (persons[a].weight>=persons[max].weight)
			return a;
		else{
			persons[a].root = max;
			return max;
		}
	}
	else{
		if (persons[a].weight > persons[max].weight){
			max = a;
		}
		string tmp = findRoot(persons[a].root,max);
		if(a==tmp)persons[a].root = "";
		else persons[a].root = tmp;
		return tmp;
	}
}

void insert(string name, int time,int type){
	if (persons.find(name) == persons.end()){//new person
		Attributes atr;
		atr.init(time,type);
		persons.insert(make_pair(name, atr));
	}
	else{
		if(type==1)persons[name].out += time;
		persons[name].weight += time;
	}

}

int main(){
	int n,k;
	while (cin >> n>>k){
		persons.clear();
		string a, b;
		int time;
		for (int i = 0; i < n; i++){
			cin >> a >> b>>time;
			insert(a, time,1);
			insert(b, time,0);
			string rootA = findRoot(a,a);
			string rootB = findRoot(b,b);
			if (rootA != rootB)persons[rootA].root = rootB;//根节点合并
		}
		//calculate gangs number
		map<string,int*> gangs;//head:[0]number of persons[1]total weights
		map<string, Attributes>::iterator iter;
		for (iter = persons.begin(); iter != persons.end(); iter++){
			string tmp = findRoot(iter->first, iter->first);
			if (gangs.find(tmp) == gangs.end()){
				int *t = new int[2]{ 1, iter->second.out };
				gangs.insert(make_pair(tmp, t));
			}
			else{
				gangs[tmp][0]++;
				gangs[tmp][1] += iter->second.out;
			}
		}
		map<string, int*>::iterator iter2;
		int sum = gangs.size();
		for (iter2 = gangs.begin(); iter2 != gangs.end(); iter2++){
			if (iter2->second[0] <= 2 || iter2->second[1] <= k)sum--;
		}
		cout << sum << endl;
		for (iter2 = gangs.begin(); iter2 != gangs.end(); iter2++){
			if (iter2->second[0] > 2 && iter2->second[1] > k)cout << iter2->first << " " << iter2->second[0] << endl;
		}
	}
	return 0;
} 