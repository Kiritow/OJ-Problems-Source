#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 100001
#define Max(a,b) (a)>(b)?(a):(b)
#define Min(a,b) (a)<(b)?(a):(b)
struct Node
{
    int x,y,z;
}node[1005];
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int check2(int d,int l,int r)
{
    if(l%d==0 || r%d==0) return 1;
    else if(r/d>l/d) return 1;
    else return 0;
}
int check(int i,int j)
{
    if(node[i].y>node[j].z || node[j].y>node[i].z)
    {
        if(node[i].y>node[i].z) swap(i,j);
        int d=gcd(node[i].x,node[j].x);
        if(check2(d,node[j].y-node[i].z,node[j].z-node[i].y))
            return 1;
        else
            return 0;
    }
    return 1;
}
int main(){
    int n,i,j;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            scanf("%d %d %d",&node[i].x,&node[i].y,&node[i].z);
        int flag=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(check(i,j)) {flag=1;break;}    
            }
            if(flag) break;
        }
        if(!flag)printf("Can Take off\n");
        else printf("Cannot Take off\n");
    }
    return 0;
}
