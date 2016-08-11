#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	int from,to;
	int l;
}data[100011];
int main()
{
	int u;
	int n;
	int num;
	int a[100011];
	int ans;
	scanf ("%d",&u);
	while (u--)
	{
		scanf ("%d",&n);
		for (int i = 1 ; i <= n ; i++)
			scanf ("%d",&a[i]);
		num = 1;
		ans = 1;
		data[num].from = 1;
		data[num].l = 1;
		for (int i = 2 ; i <= n ; i++)
		{
			if (a[i] > a[i-1])
			{
				data[num].l++;
				data[num].to = i;
				ans = max (ans,data[num].l);
			}
			else
			{
				num++;
				data[num].from = i;
				data[num].to = i;
				data[num].l = 1;
			}
		}
		if (ans == n || ans == n-1)		//特判一下
		{
			printf ("%d\n",n);
			continue;
		}
//		if (ans == n - 1)		//题目不清晰，不知道是否可以把该数改为负数 
//		{
//			if ((a[1] < a[2]) || (a[1] >= a[2] && a[2] != 0))
//				printf ("%d\n",n);
//			else
//				printf ("%d\n",ans);
//			continue;
//		}
		ans++;
		for (int i = 1 ; i < num ; i++)
		{
			if (data[i+1].l == 1 || data[i].l == 1)		//子串长度为1挺麻烦的，单独处理下 
			{
				ans = max (ans , data[i+1].l + 1);
				ans = max (ans , data[i].l + 1);
				if (data[i+1].l == 1 && i != num-1)
				{
					if (a[data[i+1].to-1] + 1 < a[data[i+2].from])
						ans = max (ans , data[i].l + data[i+2].l + 1);
				}
			}
			else
			{
				if (a[data[i].to-1] + 1 < a[data[i+1].from])		//修改前一个子串的最后一个数 
					ans = max (ans , data[i].l + data[i+1].l);
				if (a[data[i+1].from-1] + 1 < a[data[i+1].from+1])		//修改后一个子串的第一个数 
					ans = max (ans , data[i].l + data[i+1].l);
			}
		}
		printf ("%d\n",ans);
	}
	return 0;
}
