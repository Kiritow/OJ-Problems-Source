#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stack>
#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define M 100005
char a[M];
int main()
{
    int i,l,t,k;
    int ji[30];
    while(gets(a))
    {
        memset(ji,0,sizeof(ji));
        l=strlen(a);t=0;
        for(i=0;i<l;i++)
        {
            if(a[i]=='h')
               t++;
            k=a[i]-'a';
            if(k==0)
            {
                if(ji[k]<t)
                    ji[k]++;
            }
            if(k==15)
            {
                if(ji[k]<2*t&&ji[k]<ji[0]*2)
                    ji[k]++;
            }
            if(k==24)
            {
                if(ji[k]<t&&ji[k]<ji[0]&&ji[k]<ji[15]/2)
                    ji[k]++;
            }
        }
        if(ji[0]<t)
            t=ji[0];
        if(ji[15]/2<t)
            t=ji[15]/2;
        if(ji[24]<t)
            t=ji[24];
        printf("%d\n",t);
    }
    return 0;
}
