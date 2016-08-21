#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
const int MAX=101;
char s[MAX];
char k[MAX];
using namespace std;
int main()
{
    int t,n,m,i,j,q,p;
    cin>>t;
    while(t--)
    {
        cin>>n;
        p=1;
        q=0;
        getchar();
        while(n--)
        {
            gets(s);
            m=strlen(s);
            if(strcmp(s,"Caps")==0)
            {
                p=-p;
                continue;
            }
            if(m>1)
            {
                    for(i=0;i<m;i++)
                    {
                        if(s[i]==' ')
                        break;
                    }
                    if(p==1)
                    k[q++]=s[i+1]-32;
                    else
                    k[q++]=s[i+1];
                    continue;
            }
            if(p==1)
            k[q++]=s[0];
            else
            k[q++]=s[0]-32;
        }
        for(j=0;j<q;j++)
        cout<<k[j];
        cout<<endl;
    }
    return 0;
}
