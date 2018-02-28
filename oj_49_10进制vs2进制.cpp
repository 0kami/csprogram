/**
 * https://www.nowcoder.com/practice/fd972d5d5cf04dd4bb4e5f027d4fc11e?tpId=40&tqId=21357&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
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
	BigInteger(string x){
		for (char c : x){
			digits.push_back((int)(c - '0'));
		}
	}
	void print();
	BigInteger operator*(BigInteger &a);
	BigInteger operator*(int &a);
	BigInteger operator/(const int &a);
	BigInteger & operator+=(const int &a);
	void insert(int n){
		digits.insert(digits.begin(), n);
	}
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

BigInteger BigInteger::operator*(int &a){
	BigInteger t(a);
	return t*(*this);
}

BigInteger & BigInteger::operator += (const int &a){
	int cur = digits.size()-1;
	int flag = a;
	do{
		digits[cur] += flag;
		if (digits[cur] >= 10){
			flag = digits[cur] / 10;
			digits[cur] %= 10;
			cur--;
		}
		else{
			flag = 0;
		}
	} while (flag);
	return *this;
}

BigInteger BigInteger::operator / (const int &a){
	BigInteger ret;
	int size = digits.size();
	int flag=0;
	int tmp=0;
	for (int i = 0; i < size; i++){
		tmp = flag * 10 + digits[i];
		if (tmp < a){
			flag = tmp;
			ret.digits.push_back(0);
		}
		else{
			flag = tmp%a;
			tmp /= a;
			ret.digits.push_back(tmp);
		}
	}
	tmp = ret.digits[0];
	while (tmp == 0){
		ret.digits.erase(ret.digits.begin());
		if (ret.digits.size() != 0)tmp = ret.digits[0];
		else break;
	}
	return ret;
}

void reverseBin(BigInteger orign){
	BigInteger ret;
	while (orign.digits.size() > 0){
		ret.insert(orign.digits.back() % 2);
		orign = orign / 2;
	}
	int size = ret.digits.size();
	BigInteger t(2), ans("0");
	for (int i = size-1; i >=0; i--){
		if (i == size - 1 && i != 0){
			if (ret.digits[i])ans = t*ret.digits[i];
		}
		else if (i == 0){
			if (ret.digits[i])ans += ret.digits[i];
		}
		else{
			if (ret.digits[i])ans += ret.digits[i];
			ans = t*ans;
		}
		 
	}
	ans.print();
}

int main(){
	string n;
	while (cin >> n){
		BigInteger a(n);
		reverseBin(a);
	}
	return 0;
} 