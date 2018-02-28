/**
 * https://www.nowcoder.com/practice/f7eba38f7cd24c45982831e0f38518f9?tpId=40&tqId=21486&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 * 贪心算法
 * 当前站点的价钱price1与下一个站点price2
 * 如果price1>price2 则购买到下一个站点的油
 * 如果price1<price2 则再范围内一次往下找比price1便宜的站点
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

typedef struct gasStation{
	double Di;//the distance from hangzhou to this gas station
	double Pi;// the gas per unit price
}gasStation;

typedef struct Info{
	double cmax;//最大的载油量
	double totalDistance;//hangzhou to somewhere
	double davg;//the average distance per unit gas that the car can run
	int n;//the number of gas stations
	double maxDi;//max distance
	double remain;//remain distance
	double already = 0;
	double cost = 0;
	int cur;
	double curGas;
	int nextPos;
	bool success;//能找到下一个站点
	gasStation *next;
}Info;

bool sortByDistance(gasStation g1, gasStation g2){
	return g1.Di < g2.Di;
}

bool sortByPrice(gasStation g1, gasStation g2){
	return g1.Pi < g2.Pi;
}

void choose(Info &info, gasStation *gs){//choose gas station
	double cur_price = gs[info.cur].Pi;
	int t = -1;
	double min=1000000000000;
	info.success = false;
	for (int i = info.cur + 1; i < info.n; i++){
		if (gs[i].Di - gs[info.cur].Di>info.maxDi)break;
		if (cur_price > gs[i].Pi){//在有效范围内存在比当前站点更便宜的站点
			info.nextPos = i;
			info.next = &gs[i];
			info.success = true;
			return;
		}
		if (min > gs[i].Pi){//当不存在比当前站点更便宜的站点时选择有效范围内的最便宜的站点
			t = i;
			min = gs[i].Pi;
		}
	}
	if (t != -1){
		info.success = true;
		info.nextPos = t;
		info.next = &gs[t];
	}
}

int main(){
	Info info;
	while (cin >> info.cmax >> info.totalDistance >> info.davg >> info.n){
		gasStation *gs = new gasStation[info.n];

		//initial
		info.cur = 0;
		info.cost = 0;
		info.already = 0;
		info.maxDi = info.cmax*info.davg;
		info.remain = info.totalDistance;//remain distance
		info.curGas = 0;
		//initial end
		for (int i = 0; i < info.n; i++){
			cin >> gs[i].Pi >> gs[i].Di;
		}
		sort(gs, gs + info.n, sortByDistance);
		
		while (info.remain > 0){
			choose(info, gs);
			if (!info.success){
				if (info.cur != info.n - 1 || (info.cur == info.n - 1&&info.remain>info.maxDi))
					cout << "The maximum travel distance = "
						<< setiosflags(ios::fixed)
						<< setprecision(2)
						<< info.already + info.curGas*info.davg+info.maxDi
						<< endl;
				else{//last station
					info.cost += gs[info.cur].Pi*(info.remain / info.davg - info.curGas);
					info.remain = 0;
				}
				break;

			}
			else{
				double temp = (info.next->Di - gs[info.cur].Di) ;
				if (gs[info.cur].Pi > info.next->Pi){
					info.cost += gs[info.cur].Pi*(temp / info.davg - info.curGas);
					info.cur = info.nextPos;//update next gas station
					info.remain -= temp;
					info.already += temp;
					info.curGas = 0;//下一个状态时
				}
				else{
					if (info.remain >= info.maxDi){
						info.cost += gs[info.cur].Pi*(info.cmax-info.curGas);
						info.curGas = info.cmax - temp / info.davg;
						info.cur = info.nextPos;//update next gas station
						info.remain -= temp;
						info.already += temp;
					}
					else{
						info.cost += gs[info.cur].Pi*(info.remain/info.davg - info.curGas);
						info.remain = 0;
						info.already =info.totalDistance;
					}
				}
			}
			
		}//end while
		if (info.remain == 0)cout << setiosflags(ios::fixed) << setprecision(2) << info.cost << endl;
		//delete new
		delete[] gs;
	}
	return 0;
}  