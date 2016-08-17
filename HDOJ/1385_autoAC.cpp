#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
#define maxn 50
#define INF 0xffffff
#define Min(a, b) (a > b ? b : a)
int map[maxn][maxn], n;
int patl[maxn][maxn];
int f[maxn];
void floyd();
int main()
{
    while(cin >> n, n)
    {
        int i, j, a, b, next;
        for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == -1)
                map[i][j] = INF;
        }
        for(i=1; i<=n; i++)
            cin >> f[i];
        floyd();
        while(cin >> a >> b, a != -1)
        {
            next = a;
            printf("From %d to %d :\nPath: ", a, b);
            while(next != b)
            {
                printf("%d-->", next);
                next = patl[next][b];
            }
            printf("%d\n", next);
            printf("Total cost : %d\n\n", map[a][b]);
        }
    }
    return 0;
}
void floyd()
{
    int k, i, j;
    for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
        patl[i][j] = j;
    for(k=1; k<=n; k++)
    for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
    {
        int new_patl = map[i][k] + map[k][j] + f[k];
        if(map[i][j] > new_patl)
        {
            map[i][j] = new_patl;
            patl[i][j] = patl[i][k];
        }
        else if(map[i][j] == new_patl)
            patl[i][j] = Min(patl[i][j], patl[i][k]);
    }
}
