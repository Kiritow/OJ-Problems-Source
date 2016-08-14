#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1002
using namespace std;
int n;
double map[N][N];
void floyd(){
    for(int k = 1;k<=n;k++)
    for(int i = 1;i<=n;i++)
    for(int j = 1;j<=n;j++)
    if(map[i][j] < map[i][k]*map[k][j])
         map[i][j] = map[i][k]*map[k][j];
}
int main(){
    int Q,a,b;
    while(~scanf("%d",&n)){
         memset(map,0,sizeof(map));
         for(int i = 1;i<=n;i++)
         for(int j = 1;j<=n;j++)
              scanf("%lf",&map[i][j]);
         scanf("%d",&Q);
         floyd();
         for(int i = 0;i<Q;i++){
            scanf("%d%d",&a,&b);
            if(!map[a][b]) printf("What a pity!\n");
            else           printf("%.3f\n",map[a][b]);
         }
    }
    return 0;
}
