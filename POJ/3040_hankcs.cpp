#include <iostream>
#include <functional>
#include <algorithm>
#include <limits>
using namespace std;
 
typedef pair<int, int> Coin;	// 硬币 面值和数量
Coin coin[20];
int need[20];
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; ++i)
	{
		cin >> coin[i].first >> coin[i].second;
	}
	int week = 0;
	// 面额不小于C的一定可以支付一周
	for (int i = 0; i < N; ++i)
	{
		if (coin[i].first >= C)
		{
			week += coin[i].second;
			coin[i].second = 0;
		}
	}
	sort(coin, coin + N, greater<Coin>());
	while(true)
	{
		int sum = C; // 等待凑足的sum
		memset(need, 0, sizeof(need));
		// 从大到小
		for (int i = 0; i < N; ++i)
		{
			if (sum > 0 && coin[i].second > 0)
			{
				int can_use = min(coin[i].second, 
								  sum / coin[i].first);
				if (can_use > 0)
				{
					sum -= can_use * coin[i].first;
					need[i] = can_use;
				}
			}
		}
		// 从小到大
		for (int i = N - 1; i >= 0; --i)
		{
			if (sum > 0 && coin[i].second > 0)
			{
				int can_use = min(coin[i].second - need[i],                   // 上个loop用掉了一些
								  (sum + coin[i].first - 1) / coin[i].first); // 允许多出不超过一个面值的金额
				if (can_use > 0)
				{
					sum -= can_use * coin[i].first;
					need[i] += can_use;
				}
			}
		}
 
		if(sum > 0)
		{
			break;
		}
 
		int add_up = numeric_limits<int>::max(); // 凑起来的week数
		// add_up多少个最优的week 受限于 每种面值能满足最优解下的需求个数多少次
		for (int i = 0; i < N; ++i)
		{
			if (need[i] == 0)
			{
				continue;
			}
			add_up = min(add_up, coin[i].second / need[i]);
		}
		week += add_up;
		// 最优解生效，更新剩余硬币数量
		for (int i = 0; i < N; ++i)
		{
			if (need[i] == 0)
			{
				continue;
			}
			coin[i].second -= add_up * need[i];
		}
	}
	cout << week << endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif
    return 0;
}
///////////////////////////End Sub//////////////////////////////////
