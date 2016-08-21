#include<stdio.h>
#include<string.h>
int main()
{
    int l,l1,l2,i;
    char a[205],b[205],c[205],*p;
    while(scanf("%s %s",a,b)!=EOF)
    {
        l1=strlen(a)-1;
        l2=strlen(b)-1;
        l=l1>l2?l1:l2;
        l++;
        c[0]='A';
        for(i=l;i>0;i--,l1--,l2--)
        {
            if(l1>=0&&l2>=0)
                c[i]=a[l1]+b[l2]-65;
            else if(l1>=0&&l2<0)
                    c[i]=a[l1];
                else if(l1<0&&l2>=0)
                    c[i]=b[l2];
        }
        c[l+1]='\0';
        for(i=l;i>0;i--)
            if(c[i]>'Z')
            {
                c[i-1]+=1;
                c[i]=c[i]-26;
            }
        for(p=c;;p++)
        {
            if(*p!='A')
                break;
        }
        puts(p);
    }
}
