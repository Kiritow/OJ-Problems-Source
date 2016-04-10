#include <cstdio>
long long px[16];
int main()
{
	px[1]=0;
	px[2]=1;
	px[3]=2;
	for(int i=4;i<16;i++)
	{
		px[i]=(i-1)*(px[i-1]+px[i-2]);
	}
	int t;
	while(scanf("%d",&t)==1)
	{
		printf("%lld\n",px[t]);
	}
	return 0;
}