#include<iostream>
using namespace std;
int f[5009];
int main()
{
	int t;
	int n,i;
	
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			for(i=1;i<=n;i++)
				f[i]=i;
			int t;
			if(n<=3)
			{
				printf("1");
				for(i=2;i<=n;i++)
					printf(" %d",i);
				printf("\n");
				continue;
			}
			while(1)
			{
				int leap=0;
				for(i=1;i<=n;i++)
				{
					if(f[i]!=-1)
					{
						leap++;
					}
					if(leap==2)
					{
						leap=0;
						f[i]=-1;
					}
				}
				t=0;
				for(i=1;i<=n;i++)
					if(f[i]!=-1)
						t++;
					
					if(t<=3)
						break;
					
					leap=0;
					for(i=1;i<=n;i++)
					{
						if(f[i]!=-1)
							leap++;
						if(leap==3)
						{
							f[i]=-1;
							leap=0;
						}
					}
					t=0;
					for(i=1;i<=n;i++)
						if(f[i]!=-1)
							t++;
						if(t<=3)
							break;
						
			}
			for(i=1;i<=n;i++)
				if(f[i]!=-1)
				{
					printf("%d",f[i]);
					break;
				}
				i++;
				for(;i<=n;i++)
					if(f[i]!=-1)
						printf(" %d",f[i]);
					printf("\n");
		}
	}
	
	return 0;
}
