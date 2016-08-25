#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
#include<math.h>
#include<string>
using namespace std;
typedef long long ll;
#define PI acos(-1.0)
#define INF 2*1e9
#define eps   1e-6
using namespace std;
#define MAXN 100010
int n,m;
int a[1010][1010];
int l[1010],r[1010];
char map[1010][1010],map1[1010][1010];
bool can[50][50];
char  ok[5][7]={"wabww","xbcxx", "yacyy","zabcz"}; 
char tar[]= "abc";
int solve();
int main()
{
    memset(can,0,sizeof(can));
    memset(map1,0,sizeof(map1));
    int i,j ,k ;
    for(i=0;i<111;i++) map1[i][0]='1';
    for(i=0;i<4;i++) 
    {
        for(j=1;j<5;j++) 
        {
            can[ok[i][0]-'a'][ok[i][j]-'a'] = 1;
        }
    }
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;scanf("%s",map[i++]+1) );  
        int ans =-1;
        for(k=0;k<strlen(tar);k++)
        {
            memset(a,0,sizeof(a));
            for(i=1;i<=n;i++)
            for(j=1;j<=m;j++) 
            {
                map1[i][j] = map[i][j];
                if(can[ map[i][j]-'a' ][tar[k]-'a'] )
                    map1[i][j] = tar[k];
                if(map1[i][j]==map1[i-1][j]) 
                    a[i][j] =1+a[i-1][j];
                else 
                    a[i][j] = 1;
            }
            int qqq=solve();
            if( qqq>ans ) ans =qqq;
        }
        printf("%d\n",ans);
    }
}
int solve()
{
    int i,j;
    int ans = -1 ,t;
    for(i=1;i<=n;i++)
    {
        a[i][0]= a[i][m+1] =-1;
        for(j=1;j<=m;j++) 
            r[j]=l[j] =j;
        for(j=1;j<=m;j++) 
        {
             while( map1[i][j] == map1[i][l[j]-1] && a[i][j]<= a[i][l[j]-1] )
                l[j]= l[l[j]-1 ];
        }
        for(j=m;j>=1;j--) 
        {
            while( map1[i][j]==map1[i][r[j]+1] && a[i][j]<= a[i][ r[j]+1] )
                r[j] =r[r[j]+1] ;
        }
        for(j=1;j<=m;j++) 
        {
            t= a[i][j]*( r[j]-l[j] +1 );
            if(t> ans) 
                ans= t;
        }
    }
    return ans;
}
