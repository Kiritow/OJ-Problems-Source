#include<stdio.h>
#define   N 1000000
struct stdent
{
    int p[N];
}stu;
int main()
{int i,k;
        for(i=1;i<1000000;i++)
    {k=i;
    stu.p[i]=0;
      for(;k!=0;k/=10)
                if(k%10==4||k%100==62)  {stu.p[i]=1;break;}
    }
    int a,b,t;
    while(~scanf("%d%d",&a,&b)&&(a||b))
    {t=b-a+1;
        for(;a<=b;a++)
        {
           t-=stu.p[a];
        }
        printf("%d\n",t);
    }
    return 0;
}
