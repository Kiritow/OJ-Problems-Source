#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int node[20000000]= {0};

int require(int targetleft,int targetright,int cnode,int leftbound,int rightbound)
{
    if(targetleft<=leftbound&&targetright>=rightbound)
    {
        return node[cnode];
    }
    if(targetright<leftbound||targetleft>rightbound)
    {
        return 0;
    }
    int a=require(targetleft,targetright,cnode*2+1,leftbound,(rightbound+leftbound)/2);
    int b=require(targetleft,targetright,cnode*2+2,(leftbound+rightbound)/2+1,rightbound);
    return max(a,b);
}

void special(int q)
{
    /// n==1
    int x=0;
    scanf("%d",&x);
    for(int i=0; i<q; i++)
    {
        char c[4];
        c[0]=c[1]=c[2]=c[3]=0;
        int a,b;
        scanf("%s %d %d",c,&a,&b);
        switch(c[0])
        {
        case 'Q':
            printf("%d\n",x);
            break;
        case 'U':
            x=b;
            break;
        }
    }
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)==2)
    {
        memset(node,0,20000000);

        if(n==1)
        {
            special(m);
            ///printf("XXXX\n");
            return 0;
        }

        int realn=1;
        while(realn<n) realn*=2;
        for(int k=realn-1; k<=realn+n-2; k++)
        {
            scanf("%d",&node[k]);
        }
        /// build tree
        int lastcur=realn;
        int cur=lastcur/2-1;
        while(cur>0)
        {
            for(int toadd=0; toadd<cur+1; toadd++)
            {
                node[cur+toadd]=max(node[2*(cur+toadd)+1],node[2*(cur+toadd)+2]);
            }
            lastcur=cur+1;
            cur=lastcur/2-1;
        }
        node[0]=max(node[1],node[2]);
        for(int query=0; query<m; query++)
        {
            char c[4];
            c[0]=c[1]=c[2]=c[3]=0;
            int a,b;
            scanf("%s %d %d",c,&a,&b);
            switch(c[0])
            {
            case 'U':
            {
                node[realn-1+a-1]=b;
                int cnt=(realn-1+a-1-1)/2;
                while(cnt>0)
                {
                    node[cnt]=max(node[cnt*2+1],node[cnt*2+2]);
                    cnt=(cnt-1)/2;
                }
                node[0]=max(node[1],node[2]);
            }
            break;
            case 'Q':
            {
                if(a==b)
                {
                    printf("%d\n",node[realn-1+a-1]);
                }
                else
                {
                    if(b<a)
                    {
                        int tmp=a;
                        a=b;
                        b=tmp;
                    }
                    int ans=require(a-1,b-1,0,0,realn-1);
                    printf("%d\n",ans);
                }
            }
            break;
            default:
                printf("ERROR\n");
            }/// end of switch
        }
    }
    return 0;
}
