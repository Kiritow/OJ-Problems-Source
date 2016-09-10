#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int x,y;
int main()
{
    while(~scanf("%d%d",&x,&y))
    {
        if(y<x) printf("-1\n");
        else if(x==1) printf("%d\n",y-1);
        else
        {
            if(x==2)
                printf("%d\n",(y+1)/2);
            else if(x==3)
            {
                int a[3]={2,3,4};
                printf("%d\n",(y-3)/3+a[(y-3)%3]);
            }
            else if(x==4)
            {
                int a[4]={3,4,4,5};
                printf("%d\n",(y-4)/4+a[(y-4)%4]);
            }
            else if(x==5)
            {
                int a[5]={4,5,5,6,6};
                printf("%d\n",(y-5)/5+a[(y-5)%5]);
            }
            else if(x==6)
            {
                int a[]={5,6,6,6,7,7};
                printf("%d\n",(y-6)/6+a[(y-6)%6]);
            }
            else if(x==7)
            {
                int a[7]={6,7,7,7,8,8,9};
                printf("%d\n",(y-7)/7+a[(y-7)%7]);
            }
            else if(x==8)
            {
                int a[8]={7,8,8,9,8,9,9,10};
                printf("%d\n",(y-8)/8+a[(y-8)%8]);
            }
            else if(x==9)
            {
                int a[9]={8,9,9,9,9,10,10,10,11};
                printf("%d\n",(y-9)/9+a[(y-9)%9]);
            }
            else if(x==10)
            {
                int a[10]={9,10,10,10,11,10,11,11,11,12};
                printf("%d\n",(y-10)/10+a[(y-10)%10]);
            }
        }
    }
}
