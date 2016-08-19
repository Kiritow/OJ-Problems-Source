#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const char biao[27][6]={{"00000"},{"00001"},{"00010"},{"00011"},{"00100"},{"00101"},{"00110"},{"00111"},{"01000"},{"01001"},{"01010"},{"01011"},{"01100"},{"01101"},{"01110"},{"01111"},{"10000"},{"10001"},{"10010"},{"10011"},{"10100"},{"10101"},{"10110"},{"10111"},{"11000"},{"11001"},{"11010"}};
int map[30][30];
string s;
bool m[1000];
int main()
{
    int T,r,c;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        memset(m,0,sizeof(m));
        memset(map,-1,sizeof(map));
        scanf("%d%d",&r,&c);
        getchar();
       getline(cin,s);
        int sum=0;
        for( int i = 0; s[i]!='\0' ; i++ )
        {
            int k=0;
            if(s[i]>='A' && s[i]<='Z') k=(int)(s[i]-'A')+1;
            for(int j=0;j<5;j++){
                 m[++sum] = biao[k][j]-'0';
            }
        }
        int tot=0,x,y;
        x=0;y=0;
        map[0][0] = m[++tot];
        while( tot < sum ) 
        {
            while(y+1<c && map[x][y+1]==-1) map[x][++y] = m[++tot];
            while(x+1<r && map[x+1][y]==-1) map[++x][y] = m[++tot];
            while(y-1>=0&& map[x][y-1]==-1) map[x][--y] = m[++tot];
            while(x-1>=0&& map[x-1][y]==-1) map[--x][y] = m[++tot];
        }
        printf("%d ",t);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(map[i][j]==-1) printf("0");
                else printf("%d",map[i][j]);
            }
              printf("\n");
    }
    return 0;
}
