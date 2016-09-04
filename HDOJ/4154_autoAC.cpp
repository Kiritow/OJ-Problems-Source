#include<stdio.h>
#include<stdlib.h>
int f[1450]={0};
int main()
{
    int cmp(const void *a,const void *b);
    int t,i,max,p;
    while(scanf("%d",&t),t!=0)
    {
        max=0;
        p=0;
        for(i=0;i<t;i++)
        {
            scanf("%d",&f[i]);
        }
        qsort(f,t,sizeof(int),cmp);
        f[i]=1422;
        if((f[i]-f[i-1])>100)
        {
            printf("IMPOSSIBLE\n");
            p=1;
        }
        else
        {
            for(i=1;i<t;i++)
            {
                if((f[i]-f[i-1])>max)
                {
                    max=f[i]-f[i-1];
                    if(max>200)
                    {
                        p=1;
                        break;
                    }
                }
            }
            if(p==0)
            {
                printf("POSSIBLE\n");
            }
            else
            {
                printf("IMPOSSIBLE\n");
            }
        }
    }
    return 0;
}
int cmp(const void *a,const void *b)
{
    return *(int *)a-* (int*)b;
}
