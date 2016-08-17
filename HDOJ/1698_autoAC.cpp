#include<stdio.h>
const int n = 1000005;
int map[n][3];
int main()
{
    int i,M,z,N,sum,v;
    scanf("%d",&N);
    for(i=1; i<=N; i++)
    {
        sum = 0;
        int Q,j;
        scanf("%d%d",&M,&Q);
        for(j=1; j<=Q; j++)
            scanf("%d%d%d",&map[j][0],&map[j][1],&map[j][2]);
        for(j=1; j<=M; j++)
        {
            v = 1;
            for(int k=Q; k>=0; k--)
                if(map[k][0]<=j && j<=map[k][1])
                {
                    v = map[k][2];
                    break;
                }
                sum += v;
        }
        printf("Case %d: The total value of the hook is %d.\n",i,sum);
    }
}
