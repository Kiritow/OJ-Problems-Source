#include<stdio.h>
#include<string.h>
int s[1<<15];
int n,m,k,element;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int ans=0;
        memset(s,0,sizeof(s));
        while(n--)
        {
            int set=0;
            scanf("%d",&k);
            while(k--)
            {
                scanf("%d",&element);
                set=set|(1<<(element-1));
            }
            s[set]=1;
            for(int j=0;j<=(1<<14);j++)
            {
                if(s[j]){s[set|j]=1;}
            }
        }
        for(int i=0;i<=1<<14;i++)
        {
            if(s[i]){ans++;}
        }
        printf("%d\n",ans);
    }
    return 0;
}
