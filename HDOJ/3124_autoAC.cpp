#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
#define left Left
#define right Right
#define eps 1e-8
#define maxn 60000
double x[maxn],y[maxn],r[maxn];
int left[maxn],right[maxn],up[maxn],rank_up[maxn];
int n;
set<int> my_set;
double mid;
bool cmp_left(const int &a,const int &b)
{
    return x[a]-r[a] < x[b]-r[b];
}
bool cmp_right(const int &a,const int &b)
{
    return x[a]+r[a] < x[b]+r[b];
}
bool cmp_up(const int &a,const int &b)
{
    if(y[a]==y[b])
    return  x[a] < x[b];
    else return y[a] < y[b];
}
double my_sqr(double a)
{
    return a*a;
}
bool is_cross(int a,int b)
{
    a=up[a],b=up[b];
    double t1,t2;
    t1=my_sqr(x[a]-x[b])+my_sqr(y[a]-y[b]),t2=my_sqr(r[a]+r[b]+mid+mid);
    if(t1<=t2)
    return true;
    return false;
}
bool insert(int a)
{
    set<int>::iterator it=my_set.insert(a).first;
    if(it!=my_set.begin())
    {
        if(is_cross(a,*--it))
        return true;
        it++;
    }
    if(++it!=my_set.end())
    {
        if(is_cross(a,*it))
        return true;
    }
    return false;
}
bool is_ok()
{
    my_set.clear();
    int i=0,j=0;
    while(i<n || j<n)
    {
        if(j==n ||(i!=n && x[left[i]]-r[left[i]]-mid<x[right[j]]+r[right[j]]+mid))
        {   
            if(insert(rank_up[left[i++]]))
                return true;
        }
        else
        my_set.erase(rank_up[right[j++]]);
    }
    return false;
}
double find_ans()
{
    double l=0,ri=sqrt(my_sqr(x[0]-x[1])+my_sqr(y[0]-y[1]))-r[0]-r[1];
    while(l+eps<ri)
    {
        mid=(l+ri)/2;
        if(is_ok())
        ri=mid;
        else
        l=mid;
    }
    printf("%.6lf\n",l+ri);
    return 0;
}
int main()
{
    int t,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
        for(i=0;i<n;i++)
        {
            left[i]=i;
            right[i]=i;
            up[i]=i;
        }
        sort(left,left+n,cmp_left);
        sort(right,right+n,cmp_right);
        sort(up,up+n,cmp_up);
        for(i=0;i<n;i++)
        rank_up[up[i]]=i;
        find_ans();
    }
    return 0;
}
