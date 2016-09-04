#include<stdio.h>
#include<string.h>
int main()
{
    char c[20];
    while(scanf("%s",c),c[0]!='E')
    {
        int x=0,y,flag=1;
        int k;
        for(int i=0;c[i];i++)
        {
            if(c[i]=='-'&&i==0)
                flag=-1;
            else
            x=x*10+c[i]-48;
        }
        x=x*flag;
        scanf("%d",&y);
        if(x<0)
            x=-x;
        if(y<0)
            y=-y;
        if(y<x) {k=x;x=y;y=k;}
        if(y<=2*x)
        {
            if(x==1&&y==1)
                printf("2\n");
            else if(x==2&&y==2)
                printf("4\n");
            else
                printf("%d\n",(x+y)/3+(x+y)%3);
        }
        else
        {
            int ans=x;
            int c=(y-2*x)%4;
            ans+=c;
            ans+=(y-2*x-c)/2;
            if(y==1&&x==0)
                ans=3;
            printf("%d\n",ans);
        }
    }
    return 0;
}
