#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int N = 300+10;
int s[N*N],g[N*N];
#define _cp(a,b) ((a)<=(b))
int _tmp[N*N];
int inv(int n,int* a){
    int l=n>>1,r=n-l,i,j;
    int ret=(r>1?(inv(l,a)+inv(r,a+l)):0);
    for (i=j=0;i<=l;_tmp[i+j]=a[i],i++)
        for (ret+=j;j<r&&(i==l||!_cp(a[i],a[l+j]));_tmp[i+j]=a[l+j],j++);
    memcpy(a,_tmp,sizeof(int)*n);
    return ret;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        int num=0;
        bool flag=true;
        for(int i=0;i<n*n;i++)
        {
            scanf("%d",&g[i]);
            if(flag && g[i]!=0)
                num++;
            if(g[i]==0)
                flag=false;
        }
        int temp=inv(n*n,g);
        temp-=num;
        if(!(n&1))
        temp+=(n-1-(num/n));
        if(temp&1)
            puts("NO");
        else puts("YES");
    }
    return 0;
}
