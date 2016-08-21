#include<stdio.h>
#include<string.h>
int main()
{
    double s,n,m;
    int i,l;
    char h,c[200];
    while(scanf("%c %s",&h,c)==2)
    {
        getchar();
        l=strlen(c);
        if(h<='Z')
            h=h+32;
        for(i=0,n=0;i<l;i++)
        {
            if(c[i]<='Z')
                c[i]+=32;
            if(c[i]==h)
                n++;
        }
        s=n/l;
        printf("%.5lf\n",s);
    }
}
