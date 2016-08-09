#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct
{
	__int64 x;
	__int64 rl, rr, ll, lr;
}Point;
Point s[5005];
__int64 net[5005];
__int64 AtoB(Point a, Point b)
{
	if(b.x<a.x)
		return abs(a.x-b.x)+a.ll+b.rr;
	return abs(a.x-b.x)+a.lr+b.rl;
}
int main(void)
{
	__int64 n, a, b, i, j, k, temp, sum, best;
	scanf("%I64d%I64d%I64d", &n, &a, &b);
	for(i=1;i<=n;i++)
		scanf("%I64d", &s[i].x);
	for(i=1;i<=n;i++)
		scanf("%I64d", &s[i].rl);
	for(i=1;i<=n;i++)
		scanf("%I64d", &s[i].rr);
	for(i=1;i<=n;i++)
		scanf("%I64d", &s[i].ll);
	for(i=1;i<=n;i++)
		scanf("%I64d", &s[i].lr);
	sum = AtoB(s[a], s[b]);
	net[a] = b;
	for(i=1;i<=n;i++)
	{
		if(i==a || i==b)
			continue;
		k = 10000000000000ll;
		for(j=a;j!=b;j=net[j])
		{
			temp = AtoB(s[j], s[i])+AtoB(s[i], s[net[j]])-AtoB(s[j], s[net[j]]);
			if(temp<k)
			{
				k = temp;
				best = j;
			}
		}
		sum += k;
		net[i] = net[best];
		net[best] = i;
	}
	printf("%I64d\n", sum);
	return 0;
}
