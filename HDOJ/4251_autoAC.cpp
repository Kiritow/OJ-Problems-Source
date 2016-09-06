#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int srted[N];
struct node
{
    int num[N];
    int val[N];
}t[40];
int n,m;
void build(int l,int r,int d)
{
    if(l==r) return;
    int mid=(l+r)>>1;
    int midd=srted[mid];
    int same=mid-l+1,samed=0,zn=l-1,yn=mid,i;
    for(i=l;i<=r;++i)
        if(t[d].val[i]<midd) --same;
    for(i=l;i<=r;++i)
    {
        if(i==l) t[d].num[i]=0;
        else t[d].num[i]=t[d].num[i-1];
        if(t[d].val[i]<midd)
        {
            ++t[d].num[i];
            t[d+1].val[++zn]=t[d].val[i];
        }else if(t[d].val[i]>midd)
        {
            t[d+1].val[++yn]=t[d].val[i];
        }else
        {
            if(samed<same)
            {
                ++samed;
                ++t[d].num[i];
                t[d+1].val[++zn]=t[d].val[i];
            }else
                t[d+1].val[++yn]=t[d].val[i];
        }
    }
    build(l,mid,d+1);
    build(mid+1,r,d+1);
}
int query(int a,int b,int k,int l,int r,int d)
{
    if(a==b) return t[d].val[a];
    int mid=(l+r)>>1;
    int sx=t[d].num[a-1],sy=t[d].num[b];
    if(a-1<l) sx=0;
    if(sy-sx>=k)
        return query(l+sx,l+sy-1,k,l,mid,d+1);
    else
    {
        int s1=(a==1?0:a-l-sx);
        int s2=(b-a+1)-(sy-sx);
        int nk=k-(sy-sx);
        return query(mid+1+s1,mid+s1+s2,nk,mid+1,r,d+1);
    }
}
int main()
{
    int cas=1;
    int i,a,b;
    while(cin>>n)
    {
        cout<<"Case "<<cas++<<":"<<endl;
        for(i=1;i<=n;++i)
        {
            cin>>srted[i];
            t[0].val[i]=srted[i];
        }
        sort(srted+1,srted+1+n);
        build(1,n,0);
        cin>>m;
        for(i=1;i<=m;++i)
        {
            cin>>a>>b;
            cout<<query(a,b,(a+b)/2-a+1,1,n,0)<<endl;
        }
    }
}
