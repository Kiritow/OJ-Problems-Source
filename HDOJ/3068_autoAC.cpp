#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
char s[211000],c[111000];
int p[211000];
void init()
{
    int i,j;
    s[0]='@';
    for(i=0;c[i]!=0;i++)
    {
        s[2*i+1]='#';
        s[2*i+2]=c[i];
    }
    s[2*i+1]='#';
    s[2*i+2]=0;
}
int manacher()
{
    int id=0,mx=0,i;
    for(i=1;s[i]!=0;i++)
    {
        p[i]=mx>i?min(p[2*id-i],mx-i):1;
        while(s[i+p[i]] == s[i-p[i]])p[i]++;
        if(i+p[i]>mx)
        {
            mx=i+p[i];
            id=i;
        }
    }
    mx=0;
    for(i=1;s[i]!=0;i++)
    {
        if(p[i]>mx)mx=p[i];
    }
    return mx-1;
}
int main()
{
    while(~scanf("%s",c))
    {
        init();
        printf("%d\n",manacher());
    }
    return 0;
}
