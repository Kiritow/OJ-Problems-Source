#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  int n;
  char a[1005];
  while(scanf("%d",&n)!=EOF)
     {
       scanf("%s",a);
       int date=0,poww=0,wei=1,sum=0,cheng=1,flag=0;
       for(int i=strlen(a)-1;i>=0;i--)
         {
           if(a[i]>='0'&&a[i]<='9')
            {
             date+=(a[i]-'0')*wei;
             wei*=10;
             poww=0;
            }
           else if(a[i]=='^')
            {
             poww=wei=1;    
            }
           else if(a[i]=='X'&&poww)
            {
             cheng*=pow(n*1.0,date*1.0);
             poww=date=0;
             wei=1;
            }
           else if(a[i]=='X')
            {
             cheng*=n;    
             poww=0;
             wei=1;
            }
           else if(a[i]=='-')
            {
             if(date==0)
             sum-=cheng;    
             else sum-=cheng*date;
             date=poww=0;
             wei=cheng=1;
            }
           else if(a[i]=='+') 
            {
             if(date==0)  
             sum+=cheng;    
             else sum+=date*cheng;
             date=poww=0;
             wei=cheng=1;
            }  
           if(i==0)
            {
              if(a[i]=='+'||a[i]=='-')  continue;
              else  flag=1;    
            }        
         }    
       if(flag)  
       {
        if(date==0)
        sum+=cheng;
        else sum+=date*cheng;
       }
       printf("%d\n",sum);    
     }    
}
