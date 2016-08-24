#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=50050;
char str[maxn];
int  num[maxn];
int sa[maxn]; 
int ran[maxn];
int height[maxn]; 
int wa[maxn], wb[maxn], wv[maxn], wd[maxn];
int X[maxn],  que[maxn];
int pos;
int cmp(int *r, int a, int b, int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r, int n, int m){         
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i ++) wd[i] = 0;
    for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
    for(i = 1; i < m; i ++) wd[i] += wd[i-1];
    for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p){
        for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[wv[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++){
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
        }
    }
}
void calHeight(int *r, int n){           
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) ran[sa[i]] = i;
    for(i = 0; i < n; height[ran[i ++]] = k){
        for(k ? k -- : 0, j = sa[ran[i]-1]; r[i+k] == r[j+k]; k ++);
    }
}
int find(int tmp, int n)
{
    int l=0, r=n, mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(X[mid]==tmp) return mid;
        else if(X[mid]<tmp) l=mid+1;
        else r=mid-1;
    }
}
bool judge(int mid, int rear, int k)
{
    sort(que,que+rear);
    int pre=que[0], cnt=1;
    for(int i=1; i<rear; i++)
        if(que[i]-pre>=mid) pre=que[i], cnt++;
    return cnt>=k;
}
bool check(int mid, int n, int k)
{
    int rear=0;
    for(int i=1; i<=n; i++)
    {
        if(height[i]<mid)
        {
            if(judge(mid,rear,k))
            {
                pos=sa[i-1];
                return true;
            }
            rear=0, que[rear++]=sa[i];
        }
        else que[rear++]=sa[i];
    }
    if(judge(mid,rear,k))
    {
        pos=sa[n-1];
        return true;
    }
    return false;
}
int main()
{
    int n, k, T;
    cin >> T;
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++) scanf("%d",num+i), X[i]=num[i];
        sort(X,X+n);
        int ep=0;
        for(int i=1; i<n; i++)
            if(X[i]!=X[ep]) X[++ep]=X[i];
        for(int i=0; i<n; i++)
            num[i]=find(num[i],ep)+2;
        num[n]=0;
        da(num,n+1,n+5);
        calHeight(num,n);
        int l=1, r=n, mid, ans=0;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(check(mid,n,k))
            {
                l=mid+1;
                ans=mid;
            }
            else r=mid-1;
        }
        printf("%d\n",ans);
        for(int i=pos; i<pos+ans; i++) printf("%d\n",X[num[i]-2]);
        if(T) puts("");
    }
    return 0;
}
