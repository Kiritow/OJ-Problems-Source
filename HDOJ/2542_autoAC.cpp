#include<stdio.h>
int k;
struct stu
{
    int x;
    int mx;
}bu[110];
int f(int j)
{
    int i,m=0,mxx=0;
     for(i=1;i<=100;i++)
              if(bu[i].mx)
                m=m+(j/i)*bu[i].x;
       return m;
}
int main()
{
    int i,j,x,t,m,n,P,H,l,mxx;
    double s,x1,t1,n1,y1;
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<=100;i++)
            bu[i].mx=bu[i].x=0;
            s=0;
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&x,&t);
            bu[t].x=bu[t].x+x;
            if(x>bu[t].mx)bu[t].mx=x;
            x1=x;
            t1=t;
            s=s+x1/t1;
        }
        scanf("%d%d",&P,&H);
        x1=H;
        y1=P;
        n1=(x1-y1)/s;
        n=n1;
        if(n==0)n=1;
        l=0;
        for (i=n;i<=100+n;i++)
        {     m=0;mxx=0;
           for(j=1;j<=100;j++)
           {
              if(bu[j].mx)
              {
                 m=m+(i/j)*bu[j].x;
                 if(i%j==0&&bu[j].mx>mxx)
                 mxx=bu[j].x;
              }
           }
           if(m+P>=H&&mxx<=P){l=i;break;}
           else if(m+P>=H)
           break;
        }
        if(l==0)
        {
            printf("Impossible\n");
            continue;
        }
        printf("%d",l);
        n1=x1/s;
        n=n1;
        for(j=n+100;j>=l;j--)
        {
            m=0; mxx=0;
             for(i=1;i<=100;i++)
          {
              if(bu[i].mx)
             {
                m=m+(j/i)*bu[i].x;
                if(j%i==0&&bu[i].mx>mxx)
                mxx=bu[i].mx;
             }
           }
           if(m+P>=H&&mxx<=P&&f(j-1)<H){printf(" %d\n",j);break;}
        }
    }
    return 0;
}
