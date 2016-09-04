#include <stdio.h>
#include <string.h>
char str[1000005];
int drow[8]={0,-1,-1,-1,0,1,1,1};
int dcol[8]={1,1,0,-1,-1,-1,0,1};
int main()
{
    __int64 r1,c1,val,r,c,i,j,n;
    __int64 s,ans;
    while(scanf("%s",str)!=EOF)
    {
        n=strlen(str);
        r=c=s=0;
        for (i=0;i<n;i++)
        {
            val=str[i]-'0';
            r1=r+drow[val];
            c1=c+dcol[val];
            s=s+r*c1-c*r1;
            r=r1;
            c=c1;
        } 
        if (s<0) s=-s;
        printf("%I64d\n",(n+s)/2+1);
    }
    return 0;
}
