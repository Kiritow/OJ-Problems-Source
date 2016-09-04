#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN=1001;
int a[MAXN];
int b[MAXN];
bool cmp(int a,int b)
{
    return a>b;
}    
int main()
{
    int n,t;
    int sum;
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        int i;
        for(i=0;i<n;i++)
          scanf("%d",&a[i]);
        for(i=0;i<n;i++)
          scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n,cmp);
        sum=0;
        for(i=0;i<n;i++)
        {
            if(a[i]+b[i]-t>0)
              sum+=a[i]+b[i]-t;
        } 
        printf("%d\n",sum);   
    }   
    return 0; 
}
