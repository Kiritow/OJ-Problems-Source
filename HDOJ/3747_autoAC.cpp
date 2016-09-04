#include"stdio.h"
int min(int a,int b)
{
    return a>b?b:a;
}
int main()
{
    int y1,y2,y3,y4;
    int ans;
    int i;
    int n;
    char str1[55],str2[55];
    while(scanf("%d",&n)!=-1)
    {
        scanf("%s%s",str1,str2);
        y1=0;
        for(i=0;i<n;i++)    if(str1[i]!=str2[i])    y1++;
        y2=1;
        for(i=0;i<n;i++)    if(str2[i]=='0')        y2++;
        y3=1;
        for(i=0;i<n;i++)
        {
            if(str1[i]=='0')    str1[i]='1';
            else                str1[i]='0';
        }
        for(i=0;i<n;i++)    if(str1[i]!=str2[i])    y3++;
        y4=2;
        for(i=0;i<n;i++)    if(str2[i]=='1')        y4++;
        ans=min(min(min(y1,y2),y3),y4);
        printf("%d\n",ans);
    }
    return 0;
}
