#include<cstdio>
#include<queue>
using namespace std;
int a[30010], u[30010];
int main()
{
	int n, m, i, j, k, x, ans;
	while(~scanf("%d%d",&m,&n))
	{	
		priority_queue<int, vector<int>, less<int> > que1;  //队列中的元素从大到小排序
		priority_queue<int, vector<int>, greater<int> > que2;   //队列中的元素从小到大排序
		for(i = 1; i <= m; i++)
			scanf("%d",&a[i]);
		for(j = 1; j <= n; j++)
			scanf("%d",&u[j]);
		i = 0;
		j = k = 1;
		while(j <= n)
		{
			if(i == u[j])  //弹出第k小的数
			{
				j++;
				if(que1.size() < k) //que1里的元素不够k个
				{
					x = que2.top();
					que1.push(x);
					que2.pop();
				}
				ans = que1.top(); 
				printf("%d\n",ans);
				k++;  //每次弹出一个数后，k的值都要加1
			}
			else
			{
				i++;
				//que1里的元素不够k个
				if(que1.size() < k) 
				{
					que2.push(a[i]); 
					x = que2.top();	
					que2.pop();
					que1.push(x);  //先把a[i]压入que2，再从que2里取出最小值，压入que1
				}

				//如果que1的元素达到k个，且要压入队列的值比que1中的当前最大值大，说明que1中当前的最大值并不是第k小
				else if(que1.top() > a[i])
				{ 
					x = que1.top();
					que1.pop();
					que2.push(x);
					que1.push(a[i]);
				}
				//que1中的元素个数达到k个，且要压入队列的值比que1中的当前最大值小，说明que1中当前的最大值就是是第k小，则把a[i]直接压入que2中
				else
				{
					que2.push(a[i]);
				}
			}
		}
	}
	return 0;
}
