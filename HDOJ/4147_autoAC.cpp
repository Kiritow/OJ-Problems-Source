#include<stdio.h>
#include<string.h>
int main()
{
    char str[10001];
    int s,b,d,f,F,i,j,len,sum,min;
    while(scanf("%d %d %d %d %d",&s,&b,&d,&f,&F)!=EOF)
    {
        min=99999;
        for(j=1;j<=s;j++)
        {
            sum=0;
            scanf("%s",str);
            len=strlen(str);
            for(i=0;i<=len-1;i++)
            {
                if(str[i]=='A')
                {
                    sum=sum+b+d+f;
                }
                if(str[i]=='B')
                {
                    sum=sum+2*b+2*d+F;
                }
                if(str[i]=='C')
                {
                    sum=sum+3*b+3*d+2*F;
                }
            }
            if(min>sum) {min=sum;}
        }
        printf("%d\n",min);
    }
    return 0;
}
