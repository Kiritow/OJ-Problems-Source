#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int ans[300];
char str[300];
int n,b;
map<char,int>toINT;
map<int,char>toCHAR;
int i,j;
void init()
{
     for( i = 0;i< 10;++i )
     {
         toINT[ '0' + i ] = i;
         toCHAR[ i ] = '0' +i;
     }
     for( i = 0; i< 26; ++i )
     {
         toINT[ 'a' + i ] = i+10;
         toCHAR[ i + 10 ] = 'a' + i;
     }
}
int main()
{
    init();
    while( ~scanf("%d %d",&n,&b) )
    {
        memset(ans,0,sizeof(ans));
        int ml = 0;
        str[0] = '\0';
        while( n-- )
        {
            scanf("%s",str);
            int len = strlen(str)-1;
            ml = ml > len? ml : len;
            for( i = len ,j=0; i>=0 ;--i,j++ )
                ans[ j ] = ( toINT[str[i]] + ans[j] ) %b;
        }
        for( i = ml; i>=0 ; --i )
            if( ans[i] !=0)
                break;
        if( i < 0)
            puts("0");
        else
        {
            for(;i>=0;--i)
                putchar( toCHAR[ ans[i] ] );
            puts("");
        }
    }
}
