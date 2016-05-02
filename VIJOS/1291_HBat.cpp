#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n,m,a[2010],t[2010];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    scanf("%d",&t[i]);
    int left=m;
    sort(t+1,t+m+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>0;j--)
        {
            if(a[i]>t[j]&&t[j]!=0)
            {    
                t[j]=0;
                left--;
                break;
            }
        }
    } 
    printf("%d",left);
}    
