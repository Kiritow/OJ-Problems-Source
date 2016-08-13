#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct num
{
    char a[5];
    int b;
    int c;
}st[102];
int main()
{
    int i,j,k,key,v;
    int n;
    int a[4];
    char c[5];
    while(cin>>n&&n)
    {
        int count=0;
        for(v=0;v<n;v++)
        {
            cin>>st[v].a>>st[v].b>>st[v].c;
        }
        for(v=3585;v<=9999;v++)
        {
             a[0]=v/1000;
             a[1]=v%1000/100;
             a[2]=v%100/10;
             a[3]=v%10;
             int flag=0;
        for(i=0;i<n;i++)
        {
          strcpy(c,st[i].a);
            int count1=0;
            int count2=0;
            for(j=0;j<4;j++)
            {    
                if(a[j]==c[j]-'0')
                {    
                    count1++;
                }
            }
            for(j=0;j<4;j++)
            {
                for(k=0;k<4;k++)
                {
                    if(a[j]==c[k]-'0')
                    {
                    count2++;
                    c[k]='#';
                    break;
                    }
                }
            }
            if(st[i].b!=count2||st[i].c!=count1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            count++;
            key=v;
        }
        }
  if(count!=1)
  {
      cout<<"Not sure"<<endl;
  }
  else
  {
      cout<<key<<endl;
  }
    }
    return 0;
}
