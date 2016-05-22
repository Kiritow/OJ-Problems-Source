#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct Node
{
    int sum,num;
}x[1005],y[1005];

bool rule1(Node a,Node b)
{
    return a.sum>b.sum;
}

bool rule2(Node a,Node b)
{
    return a.num<b.num;
}

int main()
{
    int m,n,k,l,d;
    cin >> m >> n >> k >> l >> d;
    for(int i=0;i<=m;i++)
    {
        x[i].num=i;
    }
    for(int i=0;i<=n;i++)
    {
        y[i].num=i;
    }
    for (int i=0,xi,yi,pi,qi;i<d;i++)
    {
        scanf("%d %d %d %d",&xi,&yi,&pi,&qi);
        if(xi==pi)
        {
            y[yi<qi?yi:qi].sum++;
        }
        else if(yi==qi)
        {
            x[xi<pi?xi:pi].sum++;
        }
    }
    sort(x,x+m,rule1);
    sort(y,y+n,rule1);
    sort(x,x+k,rule2);
    sort(y,y+l,rule2);
    for(int i=0;i<k;i++)
    {
        printf("%d ",x[i].num);
    }
    cout << endl;
    for(int i=0;i<l;i++)
    {
        printf("%d ",y[i].num);
    }
    return 0;
}
