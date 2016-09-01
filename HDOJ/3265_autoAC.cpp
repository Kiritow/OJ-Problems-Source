#include<iostream>
#include<vector>
#include<string.h>
#include <algorithm>
using namespace std;
const int maxx=55555;
struct node
{
    __int64 sum,color;
}tree[maxx<<3];
struct seg
{
    int x1,x2,y,color;
    seg(int a,int b,int c,int d):x1(a),x2(b),y(c),color(d){}
    bool operator < (const seg &t)const{
        return y < t.y;
    }
};
void pushUp(int no,int l,int r)
{
    if(tree[no].color) tree[no].sum=r-l+1;
    else if(l==r) tree[no].sum=0;
    else tree[no].sum=tree[no<<1].sum+tree[no<<1|1].sum;
}
void update(int x1,int x2,int color,int l,int r,int no)
{
    if(x1<=l&&r<=x2)
    {
        tree[no].color+=color;
        pushUp(no,l,r);
        return;
    }
    int m=(l+r)>>1;
    if(x1<=m) update(x1,x2,color,l,m,no<<1);
    if(x2>m) update(x1,x2,color,m+1,r,no<<1|1);
    pushUp(no,l,r);
}
int main()
{
    int n,x1,x2,x3,x4,y1,y2,y3,y4,i;
    while(cin>>n,n)
    {
        vector<seg> v;
        for(i=1;i<=n;++i)
        {
            cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
            if(x1<x3)
            {
                v.push_back(seg(x1,x3,y1,1));
                v.push_back(seg(x1,x3,y2,-1));
            }
            if(x4<x2)
            {
                v.push_back(seg(x4,x2,y1,1));
                v.push_back(seg(x4,x2,y2,-1));
            }
            if(y1<y3)
            {
                v.push_back(seg(x3,x4,y1,1));
                v.push_back(seg(x3,x4,y3,-1));
            }
            if(y4<y2)
            {
                v.push_back(seg(x3,x4,y4,1));
                v.push_back(seg(x3,x4,y2,-1));
            }
        }
        sort(v.begin(),v.end());
        memset(tree,0,sizeof(tree));
        __int64 ret=0;
        int end=v.size();
        for(i=0;i<end-1;++i)
        {
            if(v[i].x2>v[i].x1)
                update(v[i].x1,v[i].x2-1,v[i].color,0,maxx,1);
            ret+=tree[1].sum*(v[i+1].y-v[i].y);
        }
        printf("%I64d\n",ret);
    }
    return 0;
}
