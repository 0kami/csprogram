/**
 * https://www.nowcoder.com/practice/912b15e237ef44148e44018d7b8750b6?tpId=40&tqId=21346&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * or print 3 2 1
 */
#include <iostream>

using namespace std;

int main(){
	int cSet[] = { 1, 6 };
	for (int a = 1; a < 5; a++)
		for (int b = 1; b <= 5-a; b++)
            if (1 * 2 + 1 * 10 + b * 110 + a * 100 == 532)
                cout << a << " " << b << " " << 1 << endl;
				
	return 0;
}