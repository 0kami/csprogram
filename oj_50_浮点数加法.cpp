/**
 * https://www.nowcoder.com/practice/ddec753f446e4ba4944e35378ba635c8?tpId=40&tqId=21410&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

class BigFloat{
public:
	vector<int> integer;//整数部分
	vector<int> decimal;//小数部分
	BigFloat(){}
	BigFloat(string x){
		int pos = x.find('.');
		int size = x.size();
		for (int i = 0; i < pos; i++){
			integer.push_back(x[i] - '0');
		}
		for (int i = pos + 1; i < size; i++){
			decimal.push_back(x[i] - '0');
		}
	}
	BigFloat operator+(BigFloat &a);
	int & addDecimal(vector<int> &a, vector<int> &b, int flag, vector<int> &ret);
	int & addInteger(vector<int> &a, vector<int> &b, int flag, vector<int> &ret);
	void print(){
		for (int i : integer)
			cout << i;
		cout << ".";
		for (int i : decimal)
			cout << i;
		cout << endl;
	}
};

int & BigFloat::addDecimal(vector<int> &a, vector<int> &b, int flag,vector<int> &ret){
	int sizeA = a.size() - 1;
	int sizeB = b.size() - 1;
	int size = sizeA > sizeB ? sizeA : sizeB;
	int tmp;
	while (size>= 0){
		tmp = flag + (size<a.size() ? a[size] : 0) + (size<b.size()?b[size]:0);
		if (tmp >= 10){
			flag = tmp / 10;
			tmp %= 10;
		}
		else{
			flag = 0;
		}
		ret.insert(ret.begin(), tmp);
		if (size >= 0)size--;
	}
	return flag;
}
int & BigFloat::addInteger(vector<int> &a, vector<int> &b, int flag, vector<int> &ret){
	int sizeA = a.size() - 1;
	int sizeB = b.size() - 1;
	int tmp;
	while (sizeA >= 0 || sizeB >= 0){
		tmp = flag + (sizeA==-1?0:a[sizeA]) + (sizeB==-1?0:b[sizeB]);
		if (tmp >= 10){
			flag = tmp / 10;
			tmp %= 10;
		}
		else{
			flag = 0;
		}
		ret.insert(ret.begin(), tmp);
		if (sizeA >= 0)sizeA--;
		if (sizeB >= 0)sizeB--;

	}
	return flag;
}

BigFloat BigFloat::operator + (BigFloat &a){
	int flag = 0;
	BigFloat ret;
	flag = addDecimal(decimal, a.decimal, flag, ret.decimal);
	flag = addInteger(integer, a.integer, flag, ret.integer);
	if (flag)ret.integer.insert(ret.integer.begin(), flag);
	return ret;
}

int main(){
	string a,b;
	while (cin >> a>>b){
		BigFloat f1(a),f2(b);
		BigFloat ans = f1 + f2;
		ans.print();
	}
	return 0;
}  