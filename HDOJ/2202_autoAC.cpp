#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8
struct node
{
    int x,y;
}
;
node p[50005];
node res[50005];
int cross(node p0,node p1,node p2)
{
    return (p0.x-p2.x)*(p1.y-p2.y)-(p1.x-p2.x)*(p0.y-p2.y);
}
bool cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    else
        return a.x<b.x;
}
int Graham(int n)
{
    int len;
    int top=0;
    sort(p,p+n,cmp);
    for(int i=0; i<n; i++)
    {
        while(top>1&&cross(res[top-1],p[i],res[top-2])<=0)
            top--;
        res[top++]=p[i];
    }
    len=top;
    for(int i=n-2; i>=0; i--)
    {
        while(top>len&&cross(res[top-1],p[i],res[top-2])<=0)
            top--;
        res[top++]=p[i];
    }
    if(n>1)
        top--;
    return top;
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
            cin>>p[i].x>>p[i].y;
        int dian=Graham(n);
        int ans=-22;
        for(int i=0; i<dian; i++)
            for(int j=i+1; j<dian; j++)
                for(int k=j+1; k<dian; k++)
                    ans=max(ans,cross(res[j],res[k],res[i]));
        printf("%.2lf\n",0.5*ans);
    }
    return 0;
}
