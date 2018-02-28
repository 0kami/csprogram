/**
 * https://www.nowcoder.com/practice/7b18aa6b7cc14f8eaae6b8acdebf890b?tpId=40&tqId=21433&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

map<string, int> operatorLevelMap = {
	{ "+", 1 },
	{ "-", 1 },
	{ "*", 2 },
	{ "/", 2 }
};

stack<string> operatorStack;
stack<double> numberStack;

vector<string> split(string &source){
	vector<string> retData;
	string temp = "";
	for (char c : source){
		if (c == '+' || c == '*' || c == '-' || c == '/'||c=='#'){
			retData.push_back(temp);
			temp = c;
			retData.push_back(temp);
			temp = "";

		}
		else{
			temp += c;
		}
	}
	if (temp != "")retData.push_back(temp);
	return retData;
}

double calculate(string &opt){
	double b = numberStack.top();
	numberStack.pop();
	double a = numberStack.top();
	numberStack.pop();
	if (opt == "+"){
		return a + b;
	}
	else if (opt == "-"){
		return a - b;
	}
	else if (opt == "*"){
		return a * b;
	}
	else if (opt == "/"){
		return a*1.0 / b*1.0;
	}
	return NULL;
}

int main(){
	string line;
	while (getline(cin, line)){//接受string流 cin.getline 字符流　允许空格
		line += "#";//add end char
		vector<string> splitedStr = split(line);
		double res = 0;
		string opt;
		for (string v : splitedStr){
			if (v == "+" || v == "*" || v == "-" || v == "/"){
				opt = operatorStack.empty() ? "" : operatorStack.top();
				while (opt != "" && operatorLevelMap[opt] >= operatorLevelMap[v]){//pop top element 逃出栈时确定栈中是否存在与当前算符同样level的算符 如果存在继续计算
					operatorStack.pop();
					res = calculate(opt);
					numberStack.push(res);
					opt = operatorStack.empty() ? "" : operatorStack.top();
				}
				operatorStack.push(v);
			}
			else if (v == "#"){//clear stack
				while (!operatorStack.empty()){
					opt = operatorStack.top();
					operatorStack.pop();
					res = calculate(opt);
					numberStack.push(res);
				}
			}
			else{
				numberStack.push(atoi(v.c_str()));
			}
		}
		cout << setiosflags(ios::fixed)
			<< setprecision(0)
			<< res << endl;
	}

	return 0;
} 