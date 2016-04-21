#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


int C[131072];

char cmd[32];

int getsum(int left,int right,int pos,int leftbound,int rightbound)
{
    if(left<=leftbound&&right>=rightbound)
    {
        return C[pos];
    }
    if(right<leftbound||left>rightbound)
    {
        return 0;
    }
    int a=getsum(left,right,2*pos+1,leftbound,(leftbound+rightbound)/2);
    int b=getsum(left,right,2*pos+2,(leftbound+rightbound)/2+1,rightbound);
    return a+b;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int itt=1;itt<=t;itt++)
    {
        printf("Case %d:\n",itt);
        int N;
        scanf("%d",&N);
        int realn=1;
        while(realn<N)
        {
            realn*=2;
        }
        memset(C,0,sizeof(int)*realn);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&C[realn-1+i]);
        }
        int start=(realn-1)/2;
        while(start>0)
        {
            int L=start+1;
            for(int i=0;i<L;i++)
            {
                C[start+i]=C[2*(start+i)+1]+C[2*(start+i)+2];
            }
            start=(start-1)/2;
        }
        C[0]=C[1]+C[2];
        while(scanf("%s",cmd)==1)
        {
            if(strcmp(cmd,"End")==0)
            {
                break;
            }
            int a,b;
            scanf("%d %d",&a,&b);
            if(strcmp(cmd,"Query")==0)
            {
                int ans=getsum(a-1,b-1,0,0,realn-1);
                printf("%d\n",ans);
            }
            else if(strcmp(cmd,"Add")==0)
            {
                int pos=realn-1+a-1;
                while(pos>0)
                {
                    C[pos]+=b;
                    pos=(pos-1)/2;
                }
                C[0]+=b;
            }
            else if(strcmp(cmd,"Sub")==0)
            {
                int pos=realn-1+a-1;
                while(pos>0)
                {
                    C[pos]-=b;
                    pos=(pos-1)/2;
                }
                C[0]-=b;
            }
        }
    }/// end of for(...)

    return 0;
}
