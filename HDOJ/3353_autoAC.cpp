#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string.h>
using namespace std;
#define MAXN 1000000
int prime[MAXN],num;
bool notprime[MAXN];
int pa[MAXN],ma[MAXN];
int pb[MAXN],mb[MAXN];
void PRIME()
{
    int i,j;
    num=0;
    memset(notprime,false,sizeof(notprime));
    for(i=2;i<MAXN;i++)
       if(!notprime[i])
       {
           prime[num++]=i;
           for(j=i+i;j<MAXN;j+=i)
             notprime[j]=true;
       }    
}    
int main()
{
    int a,b;
    int na,nb;
    int i,j,t;
    int iCase=0;
    PRIME();
    while(scanf("%d%d",&a,&b))
    {
        if(a==0&&b==0) break;
        iCase++;
        na=nb=0;
        for(i=0;i<num&&a>0;i++)
        {
            if(a%prime[i]==0)
            {
                t=0;
                while(a%prime[i]==0)
                {
                    t++;
                    a/=prime[i];
                }   
                pa[na]=prime[i];
                ma[na++]=t; 
            }    
        }  
        for(i=0;i<num&&b>0;i++)
        {
            if(b%prime[i]==0)
            {
                t=0;
                while(b%prime[i]==0)
                {
                    t++;
                    b/=prime[i];
                }    
                pb[nb]=prime[i];
                mb[nb++]=t;
            }    
        }  
        int X=0,D=0;    
        i=0;j=0;
        while(i<na&&j<nb)
        {
            if(pa[i]==pb[j])
            {
                X++;
                D+=abs(ma[i]-mb[j]);
                i++;
                j++;
            }
            else if(pa[i]<pb[j])
            {
                X++;
                D+=ma[i];
                i++;
            }       
            else
            {
                X++;
                D+=mb[j];
                j++;
            }     
        }   
        while(i==na&&j<nb)
        {
            X++;
            D+=mb[j];
            j++;
        }
        while(i<na&&j==nb)
        {
            X++;
            D+=ma[i];
            i++;
        }   
        printf("%d. %d:%d\n",iCase,X,D);      
    }    
    return 0;
}
