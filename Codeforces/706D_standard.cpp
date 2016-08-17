#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int q;
int sz = 1;
struct node
{
	int zero;
	int one;
	int cnt1;
	int cnt0;
}a[10000000];

int main()
{
	cin >> q;
	for (int i = 0; i <= q; i++)
	{
		char c;
		int x;
		if(i==0)
		{
		    c='+';
		    x=0;
		}
		else
		cin >> c >> x;
		if (c == '+')
		{
			int bit[32];
			for (int i = 0; i < 32; i++)
			{
				bit[i] = x % 2;
				x /= 2;
			}
			int v = 1;
			for (int i = 31; i >= 0; i--)
			{
				if (bit[i] == 1)
				{
					a[v].cnt1++;
					if (a[v].one == 0)
					{
						sz++;
						a[v].one = sz;
					}
					v = a[v].one;
				}
				else
				{
					a[v].cnt0++;
					if (a[v].zero == 0)
					{
						sz++;
						a[v].zero = sz;
					}
					v = a[v].zero;
				}
			}
		}
		if (c == '-')
		{
			int bit[32];
			for (int i = 0; i < 32; i++)
			{
				bit[i] = x % 2;
				x /= 2;
			}
			int v = 1;
			for (int i = 31; i >= 0; i--)
			{
				if (bit[i] == 1)
				{
					a[v].cnt1--;
					v = a[v].one;
				}
				else
				{
					a[v].cnt0--;
					v = a[v].zero;
				}
			}
		}
		if (c == '?')
		{
			int ans = 0;
			int bit[32];
			for (int i = 0; i < 32; i++)
			{
				bit[i] = x % 2;
				x /= 2;
			}
			int v = 1;
			for (int i = 31; i >= 0; i--)
			{
				if (bit[i] == 1)
				{
					if (a[v].cnt0 > 0)
					{
						ans += (1 << i);
						v = a[v].zero;
					}
					else
					{
						v = a[v].one;
					}
				}
				else
				{
					if (a[v].cnt1 > 0)
					{
						ans += (1 << i);
						v = a[v].one;
					}
					else
					{
						v = a[v].zero;
					}
				}
			}
			cout << ans << endl;
		}
	}
}
