#include <stdio.h>
int main()
{
    int sc[200001],i,j,k,mx,mi,a,b,m,n;
    char t;
    while(~scanf("%d%d",&n,&m))
    {
        mx = -1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&sc[i]);
            if(mx<sc[i])
            {
                mx = sc[i];
                mi = i;
            }
        }
        for(i=0;i<m;i++)
        {
            scanf("%*c%c%d%d",&t,&a,&b);
            if(t=='Q')
            {
                if(a<=mi&&mi<=b&&sc[mi]==mx) k=mx;
                else 
                {
                    k=sc[a];
                    for(j=a+1;j<=b;j++)
                        if(k<sc[j]) k=sc[j];
                }
                printf("%d\n",k);
            }else
            {
                sc[a]=b;
                if(b>mx)
                {
                    mx = b;
                    mi = a;
                }
            }
        }
    }
    return 0;
}
