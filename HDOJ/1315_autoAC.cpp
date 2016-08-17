#include<stdio.h>
char s[100];
int pd(double p,int i)
{
    int j;
    double g=0;
    if(p<2||p>16) return 0;
    if(s[i]=='#') return 0;
    for(j=i;s[j]!='\0';j++)
    {
        if(s[j]=='#') break;
        if(p>10&&(s[j]<'0'||(s[j]>'9'&&s[j]<'a')||s[j]>'a'+p-11)) return 0;
        if(p<=10&&!(s[j]>='0'&&s[j]<='0'+p-1)) return 0;
        if(s[j]>='a'&&s[j]<='f') g=g*p+10+s[j]-'a';
        else g=g*p+s[j]-'0';
    }
    if(s[j]=='#'&&s[j+1]=='\0'||s[j]=='#'&&s[j+1]=='#'&&pd(g,j+2))
        return 1;
    else return 0;
}
int main()
{
    int t,j;
    double p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        p=0;
        for(j=0;;j++)
        {
            if(s[j]>='0'&&s[j]<='9')
                p=p*10+s[j]-'0';
            else break;
        }
        if(s[j]=='#'&&pd(p,j+1)||p==0&&s[j]=='\0') printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
