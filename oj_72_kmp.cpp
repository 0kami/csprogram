/**
 *  no oj
ababcabcacbab
abcac
aabaabaabaac
aabaac
 */
#include <iostream>
#include <string>
using namespace std;


void getNext(int *next,string a){
    /*
    1. next[1]=0
       next[2]=1
    2. 求next[i]
        k=next[i-1]
        a[i-1]==a[k]? 相等则 next[i]=k+1
                      不相等则 k=next[k]
                             当k=0 next[i]=1
                             当k!=0 再返回到2
    */
	next[1] = 0;
	next[2] = 1;
	for (int i = 3; i <= next[0]; i++){
		int k = next[i - 1];
		while (true){
			if (a[i - 1] == a[k]){
				next[i] = k + 1;
				break;
			}
			else{
				k = next[k];
				if (k == 0){
					next[i] = 1;
					break;
				}
			}
		}
		
	}
}

int main(){
	string s, a;
	int next[100];
	while (cin >> s >> a){
		next[0] = a.size();
		getNext(next, a);
		int size = s.size();
		int asize = a.size()-1;
		int flag = false;
		for (int i = 0, j = 0; i < size; i++, j++){
			if (s[i] == a[j] && j == asize){
				flag = true;
				break;
			}
			else if (s[i] != a[j]){
				j = next[j];
			}
		}
		if (flag)cout << "YES" << endl;
		else cout << "NO"<<endl;
	}
	return 0;
} 