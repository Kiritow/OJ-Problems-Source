#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,k,len,t1,t2,t3,t4,t;
    char s[1000];
    while(scanf("%d",&n)!=EOF&&n!=0)
    {    getchar();
        while(n)
        {    t1=0;t2=0;t3=0;t4=0;t=0;
            gets(s);
            len=strlen(s);
            for(i=0;i<len;i++)
            {
                if(s[i]>='0'&&s[i]<='9')
                {t1++;}
                else if(s[i]>='a'&&s[i]<='z')
                {t2++;}
                else if(s[i]>='A'&&s[i]<='Z')
                {t3++;}
                else
                {t4++;}
            }
            if(t1!=0)
                t++;
            if(t2!=0)
                t++;
            if(t3!=0)
                t++;
            if(t4!=0)
                t++;
            if(len>=8&&len<=16&&t>=3)
                printf("YES\n");
            else
                printf("NO\n");
            n--;
        }
    }
    return 0;
}
