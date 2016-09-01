#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
char str[100005];
int n;
int main()
{
    while(scanf("%d",&n)==1&&n)
    {
        scanf("%s",str);
        int h=0,t=0;
        for(int i=0;i<n;i++)
            if(str[i]=='H')
                h++;
            else t++;
        if(h%2==0 && t%2==0)
        {
            h/=2;t/=2;
        }
        else 
        {
            printf("-1\n");
            continue;
        }
        int hh=0,tt=0;
        for(int i=0;i<n/2;i++)
            if(str[i]=='H')
                hh++;
            else tt++;
        if(hh==h && tt==t)
        {
            printf("1\n%d\n",n/2);
            continue;
        }
        for(int i=n/2,j=0;i<n;i++,j++)
        {
            if(str[i]=='H')
                hh++;
            else tt++;
            if(str[j]=='H')
                hh--;
            else tt--;
            if(hh==h && tt==t)
            {
                printf("2\n%d %d\n",j+1,i+1);
                break;
            }
        }
    }
    return 0;
}
