#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct q
{
	int a,p;
};
int cmp(const void *a,const void *b)
{
	return (*(q*)a).p-(*(q*)b).p;
}
int main()
{
	q qs[11];
	int cash,n,i,j,con[100001];
	char dp[100001];
	while(scanf("%d%d",&cash,&n)==2)
	{
		if(!n)
		{
			putchar('0');putchar('\n');
			continue;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&(qs[i].a),&(qs[i].p));//a[i]是钞票数，p[i]是钞票面值
		}
		qs[n].a=0;
		if(!cash)
		{
			putchar('0');putchar('\n');
			continue;
		}
		qsort(qs,n,sizeof(q),cmp);//先规划小面额的dp末尾不会出现错误
		memset(dp,0,sizeof(dp));
		memset(con,0,sizeof(con));
		dp[cash]=1;
		con[cash]=qs[0].a;
		for(i=0;i<n;i++)
		{
			for(j=cash;j>=qs[i].p;j--)
			{
				if(dp[j])
				{
					if(con[j] && !dp[j-qs[i].p])
					{
						con[j-qs[i].p]=con[j]-1;
						dp[j-qs[i].p]=1;
					}
					con[j]=qs[i+1].a;
				}
			}
		}
		for(i=0;!dp[i];i++);
		printf("%d\n",cash-i);
	}
	return 0;
}
