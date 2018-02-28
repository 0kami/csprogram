/**
 * https://www.nowcoder.com/practice/f54d8e6de61e4efb8cce3eebfd0e0daa?tpId=40&tqId=21355&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * https://itimetraveler.github.io/2017/08/22/%E3%80%90%E7%AE%97%E6%B3%95%E3%80%91%E5%A4%A7%E6%95%B0%E7%9B%B8%E4%B9%98%E9%97%AE%E9%A2%98%E5%8F%8A%E5%85%B6%E9%AB%98%E6%95%88%E7%AE%97%E6%B3%95/
 * 用的算法
 * 98*21
 *      9 8
 *  *   2 1
 * -------------
 *      9 8
 *  18 16        //先不进位
 * -------------
 *  18 25 8     //进位
 * -------------
 *  2058
 */
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

class BigInteger{
public:
	vector<int> digits;
	BigInteger(){
	}
	BigInteger(int x){
		while (x > 0){//low -> high
			digits.insert(digits.begin(), x % 10);
			x /= 10;
		}
	}
	void print();
	BigInteger operator*(BigInteger &a);
};

void BigInteger::print(){
	for (int i : digits)
		cout << i;
	cout << endl;
}

BigInteger BigInteger::operator*(BigInteger &a){
	vector<int> temp;
	BigInteger ret;
	int size = digits.size();
	int asize = a.digits.size();
	int flag=0;
	int start = 0;
	for (int i = asize-1; i >= 0; i--){//21
		start = flag;
		for (int j = size - 1; j >= 0; j--){//98
			if (temp.size() > start)
				temp[start] = digits[j] * a.digits[i] + temp[start];
			else
				temp.push_back(digits[j] * a.digits[i]);
			start++;
		}
		flag++;
	}
	size = temp.size()-1;
	flag = 0;
	int t;
	for (int i : temp){
		t = i + flag;
		if (t >= 10){
			ret.digits.insert(ret.digits.begin(), t % 10);
			flag = t / 10;
		}
		else{
			ret.digits.insert(ret.digits.begin(),t);
			flag = 0;
		}
	}
	if (flag != 0)ret.digits.insert(ret.digits.begin(), flag);
	return ret;
}

int main(){
	int n;
	while (cin >> n){
		BigInteger a(1);
		for (int i = 2; i <= n; i++){
			BigInteger b(i);
			a = a*b;
		}
		a.print();
	}
	return 0;
}
