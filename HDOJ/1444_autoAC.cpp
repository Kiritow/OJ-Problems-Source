#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char a[19][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
    char b[20][10]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    char c[10];
    int t,d,y,r,w;
    cin>>t;
    cout<<t<<endl;
    while(t--)
    {
       scanf("%d. %s %d",&d,c,&y);
       for(int i=0;i<19;i++)
          if(strcmp(c,a[i])==0)
                w=i;
       r=y*365+w*20+d;
       y=r/260;
       w=r%20;
       d=r%13;
       cout<<d+1<<" "<<b[w]<<" "<<y<<endl;
    }
    return 0;
}
