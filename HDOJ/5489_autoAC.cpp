#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std ;
const int maxn = 1e5+10 ;
int a[maxn] , b[maxn] ;
int c[maxn] ;
pair<int , int> pre[maxn] ;
int len_b = 0 ;
int len_a = 0 ;
int find_b(int l , int r , int v)
{
    while(l<=r)
    {
        int mid = (l+r)>> 1 ;
        if(b[mid]>=v)
        l = mid+1 ;
        else r = mid - 1 ;
    }
    return l;
}
int find_a(int l , int r ,int v)
{
    while(l<=r)
    {
        int mid = (l + r) >> 1 ;
        if(a[mid]<=v)
        l = mid+1 ;
        else r = mid - 1 ;
    }
    return l ;
}
int find_ans_a(int l , int r , int v)
{
    while(l<=r)
    {
        int mid = (l+r)>>1 ;
        if(a[mid]<=v)
        l = mid + 1 ;
        else r = mid - 1 ;
    }
    return r ;
}
int find_ans_b(int l , int r , int v)
{
    while(l<=r)
    {
        int mid = (l+r) >> 1 ;
        if(b[mid] >= v)
        l = mid + 1 ;
        else r = mid - 1 ;
    }
    return r ;
}
void debuga()
{
    for(int i = 1;i <= len_a;i++)
    printf("%d%c" , a[i] , i == len_ ?'\n' :' ') ;
}
int main()
{
    int t ;
    scanf("%d" , &t) ;
    int cas = 0 ;
    while(t--)
    {
        int n , l ;
        scanf("%d%d" , &n , &l) ;
        for(int i = 1;i <= n;i++)
        a[i] = b[i] = 0 ;
        for(int i = 1;i <= n;i++)
        scanf("%d" , &c[i]) ;
        len_a = len_b  = 0 ;
        for(int j = n;j > l;j--)
        {
            int pos = find_b(1 , len_ , c[j]) ;
            pre[j] = make_pair(pos , b[pos]) ;
            if(!b[pos])len_b++ ;
            b[pos] = c[j] ;
        }
        int ans = len_ ;
        for(int i = 1;i <= n-l;i++)
        {
            int pos = find_a(1 , len_ , c[i]) ;
            if(a[pos] == 0)len_a++ ;
            a[pos] = c[i] ;
            pair<int , int> tmp = pre[i+l] ;
            if(tmp.second == 0)len_b--;
            else b[tmp.first] = tmp.second ;
            int pos_1 = find_ans_b(1  , len_ , c[i]) ;
            ans = max(pos+pos_ , ans) ;
            if(tmp.second != 0)
            {
                int pos_2 = find_ans_a(1 , len_ , tmp.second) ;
                ans = max(ans , pos_2 + tmp.first) ;
            }
        }
        printf("Case #%d: " , ++cas) ;
        printf("%d\n" , ans) ;
    }
    return  0 ;
}
