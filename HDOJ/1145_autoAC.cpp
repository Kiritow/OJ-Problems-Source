#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
double ex[30+5]={0.0};
double mon[30+5]={0.0};
double t=0.0;
int n=0;
double bp=0.0;
int main()
{
    mon[0]=1;
    for(int i=1;i<=30;i++)
    {
        mon[i]=mon[i-1]*2;
    }
    while(scanf("%d%lf",&n,&t)!=EOF&&(n>0))
    {
        ex[n]=mon[n];
        for(int i=n-1;i>=0;i--)
        {
            bp=mon[i]/ex[i+1];
            if(bp<=t)
            {
                ex[i]=(1+t)/2 * ex[i+1];
            }
            else
            {
                ex[i]=(bp-t)/(1-t) * mon[i] + (1-bp)/(1-t) * (1+bp)/2 * ex[i+1];
            }
        }
        printf("%.3lf\n",ex[0]);
    }
    return(0);
}
