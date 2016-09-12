#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=100000+5;
int data[maxn];
int main()
{
    int m,p;
    while(scanf("%d%d",&m,&p)!=-1)
    {
        for(int i=0; i<m; i++)
          {
              scanf("%d",&data[i]);
                data[i]%=p;
          }
        sort(data,data+m);
        if(p-data[m-1]>data[m-2])
            printf("%d\n",data[m-1]+data[m-2]);
        else
        {
            int now=0;
            int ans=data[m-1]+data[m-2]-p;
            for(int i=m-1; i>=1; i--)
            {
                for(int j=now; j<i; j++)
                {
                    if(p-data[i]>data[j])
                    ans=max(data[i]+data[j],ans);
                    else
                    {
                        if(j>0)
                        now=j-1;
                        break;
                    }
                    if(ans==p-1)
                        break;
                }
                if(ans==p-1)
                        break;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
