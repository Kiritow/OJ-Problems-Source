#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std ;
const int maxn = 2e5 + 10 ;
int str[maxn] ;
int p[maxn] ;
void pk(int n)
{
    int i;
    int mx = 0;
    int id=0;
    for(i=0; i<n; i++)
    {
        if( mx > i )
            p[i] = min( p[2*id-i], mx-i );
        else
            p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]] && i - p[i] >= 0 && i + p[i] < n; p[i]++);
        if( p[i] + i > mx )
        {
            mx = p[i] + i;
            id = i;
        }
    }
}
int main()
{
    int t  ;
    int cas = 0 ;
    int  n ;
    scanf("%d" , &t) ;
    while(t--)
    {
        scanf("%d" , &n) ;
        for(int i = 0;i <= 2*n+1;i++)
        p[i] = 0 ;
        int len = 0 ;
        str[len++] = -1 ;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d" , &str[len++]) ;
            str[len++] = -1 ;
        }
        int ans = 1 ;
        pk(len) ;
        for(int i = 2;i < len-1 ;i += 2)
          for(int j = ans;j <= p[i] ;j += 2)
            if(p[i + j -1]>= j)
              ans = j;
        ans = ans/2*3 ;
        printf("Case #%d: ",++cas) ;
        cout<<ans<<endl;
    }
    return 0 ;
}
