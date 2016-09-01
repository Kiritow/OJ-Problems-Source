#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN  = 15+2;
int id[32786];
char s[MAXN][MAXN];
int gmax(int a,int b){return a>b?a:b;}
int gmin(int a,int b){return a<b?a:b;}
int main()
{
    int i,j,k;
    id[0] = 0;
    for(i=0; i<=32786; i++){///浜杩惰〃绀轰涓
        id[i] = id[i>>1] + (i&1);
    }
    while(scanf("%s",s[0])!=EOF){
        if(s[0][0]=='E')
            return 0;
        for(i=1; i<15; i++){
            scanf("%s",s[i]);
        }
        int ans = 15;
        for(i=0; i<(1<<15); i++){
            int col[15];
            memset(col,0,sizeof(col));
            for(j=0; j<15; j++){
                if((i&(1<<j))==0){
                    for(k=0; k<15; k++)
                        if(s[j][k]=='#')
                            col[k] = 1;
                }
            }
            int tt = 0;
            for(j=0; j<15; j++)
                if(col[j]==1)
                    tt++;
            tt = gmax(id[i],tt);
            ans = gmin(ans,tt);
        }
        printf("%d\n",ans);
    }
    return 0;
}
