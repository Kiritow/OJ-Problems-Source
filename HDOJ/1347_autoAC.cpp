#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int b[10005];
int main()
{
    int n,m,i,j,max1,max2,l;
    int a;
    while(scanf("%d %d",&n,&m)!=EOF&&n!=0||m!=0)
    {
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&a);
                b[a]++;
            }
        }
        max1=-1;max2=-1;
        for(i=1;i<=10000;i++)
        {
            if(b[i]>max1)
            {
                max2=max1;
                max1=b[i];
            }
            else   
            {
                if(b[i]>max2)
                 {
                     max2=b[i];
                 }
             }
        }
        l=0;
        for(i=1;i<=10000;i++)
        {
            if(b[i]==max2)
            {
                if(l==0)
                {
                    printf("%d",i);
                    l++; 
                }
                else 
                printf(" %d",i);
            }
         }
        printf("\n");
    }
    return 0;
}
