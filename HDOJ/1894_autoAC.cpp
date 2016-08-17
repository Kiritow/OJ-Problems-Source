#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
string a[100010];
int main()
{
       int cas,i,j,n,cnt;
       cin>>cas;
       while(cas--)
       {
           cnt=0;
           cin>>n;
           for(i=0;i<n;i++)
               cin>>a[i];
               sort(a,a+n);
           for(i=0;i<n-1;i++)
           {
               for(j=i+1;j<n;j++)
               {
                   if(a[i].size()>=a[j].size()) break;
                    if(a[i].compare(0,a[i].size(),a[j],0,a[i].size())==0)
                             cnt++;
                    else break;
               }
           }
           if(cnt>11519)  cnt=cnt%11519;
           printf("%d\n",cnt);
       }
       return 0;
}
