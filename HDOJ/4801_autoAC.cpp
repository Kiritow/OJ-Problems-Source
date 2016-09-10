#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
int B[6][24]={ {6,1,12,3,5,11,16,7,8,9,4,10,18,13,14,15,20,17,22,19,0,21,2,23}, //ok
               {20,1,22,3,10,4,0,7,8,9,11,5,2,13,14,15,6,17,12,19,16,21,18,23}, //ok
               {1,3,0,2,23,22,4,5,6,7,10,11,12,13,14,15,16,17,18,19,20,21,9,8}, //ok
               {2,0,3,1,6,7,8,9,23,22,10,11,12,13,14,15,16,17,18,19,20,21,5,4}, //ok
               {0,1,8,14,4,3,7,13,17,9,10,2,6,12,16,15,5,11,18,19,20,21,22,23}, //ok
               {0,1,11,5,4,16,12,6,2,9,10,17,13,7,3,15,14,8,18,19,20,21,22,23}  //ok
              };
int ans;
void update(int *h)
{
    int sum=0;
    if (h[0]==h[1] && h[1]==h[2] && h[2]==h[3]) sum++;
    if (h[4]==h[5] && h[5]==h[10] && h[10]==h[11]) sum++;
    if (h[6]==h[7] && h[7]==h[12] && h[12]==h[13]) sum++;
    if (h[8]==h[9] && h[9]==h[14] && h[14]==h[15]) sum++;
    if (h[16]==h[17] && h[17]==h[18] && h[18]==h[19]) sum++;
    if (h[20]==h[21] && h[21]==h[22] && h[22]==h[23]) sum++;
    ans=max(ans,sum);
}
void dfs(int N,int *h)
{
    update(h);
    if (!N) return;
    int k,i,p[24];
    for (k=0;k<6;k++)
    {
           for (i=0;i<24;i++) p[i]=h[B[k][i]];
           dfs(N-1,p);
    }
    return;
}
int main()
{
    int N,i,h[24];   
    while (~scanf("%d",&N))
    {
            for (i=0;i<24;i++) scanf("%d",&h[i]);
            ans=0;
            dfs(N,h);
            printf("%d\n",ans);
    }
    return 0;
}
