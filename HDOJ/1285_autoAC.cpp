#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdlib>
int a[501][501];
int b[501],w[501];
int n,m,i,j,s,t;
using namespace std;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(w,0,sizeof(w));
        for(i=1;i<=m;i++)
        {
            cin>>s>>t;
            if(!a[s][t])
            {
                a[s][t]++;        
                b[t]++;
            }
        }
        int numb=0;
        while(1)
        {
            j=1;
            if(b[j]!=0)            
            {
                while(1)
                {
                    j++;
                    if(b[j]==0)
                        break;
                    if(j>n)
                        break;
                }
            }
            b[j]=-1;               
            w[numb]=j;              
            numb++;
            for(i=1;i<=n;i++)
            {
                if(a[j][i]>0)
                {
                    b[i]--;
                    a[j][i]=-1;    
                }
            }
            if(numb>n)
                break;
        }
        for(i=0;i<numb-2;i++)      
            cout<<w[i]<<' ';
        cout<<w[numb-2]<<endl;
    }
    return 0;
}
