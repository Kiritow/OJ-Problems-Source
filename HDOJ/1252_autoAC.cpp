#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,ok,p1,p2,p3;
int ans[51][51][51];
char map[51][51];
struct Hike{
    char a,b,c;
};
void bfs()
{
    int i,a,b,c;
    queue<Hike>Q;
    Hike tmp;
    ans[p1][p2][p3] = 0;
    tmp.a = p1;
    tmp.b = p2;
    tmp.c = p3;
    Q.push(tmp);
    while(!Q.empty())
    {
        tmp = Q.front();    Q.pop();
        a = tmp.a;    b = tmp.b;    c = tmp.c;
        if((a == b) && (a == c))    
        {
            ok = a;    break;
        }
        int current = ans[a][b][c];    
        current ++;
        char *color ;
        char bcColor = map[b][c];    
        color = map[a]+1;
        for(i=1;i<=n;i++,color++)
        {  
            if(i != a && *color == bcColor && ans[i][b][c] > current)
            {
                ans[i][b][c] = current;
                tmp.a = i;    tmp.b = b;    tmp.c = c;
                Q.push(tmp);
            }
        }
        char acColor = map[a][c];    
        color = map[b] + 1;
        for(i=1;i<=n;i++,color++)
        {
            if(i != b && *color == acColor && ans[a][i][c] > current)
            {
                ans[a][i][c] = current;
                tmp.a = a;    tmp.b = i;    tmp.c = c;
                Q.push(tmp);
            }
        }    
        char abColor = map[a][b];    
        color = map[c] + 1;
        for(i=1;i<=n;i++,color++)
        {
            if(i != c && *color == abColor && ans[a][b][i] > current)
            {
                ans[a][b][i] = current;
                tmp.a = a;    tmp.b = b;    tmp.c = i;
                Q.push(tmp);
            }
        }
    }
}
int main()    
{
    int i,j;
    char str[110];
    while(scanf("%d",&n)!=EOF && n)
    {    
        scanf("%d%d%d\n",&p1,&p2,&p3);
        for(i=1;i<=n;i++)
        {
            gets(str);
            for(j=0;j<n;j++)
                sscanf(str+2*j,"%c",&map[i][j+1]);
            map[i][n+1] = '\0';
        }
        ok = 0;    
        fill(&ans[0][0][0],&ans[0][0][0]+51*51*51,255);
        bfs();
        if(ok) printf("%d\n",ans[ok][ok][ok]);
        else    printf("impossible\n");
    }
    return 0;
}
