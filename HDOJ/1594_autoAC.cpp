#include<iostream>
#include<cstdio>
using namespace std;
int abs(int a)
{
    if(a<0)return -a;
    return a;
}
int main()
{
    int i,n;
    while(scanf("%d",&n)!=EOF)
   {
       int x,y,max;
       scanf("%d%d",&x,&y);
       max=abs(y-x);
       int xx=1,yy=2;
       for(i=2;i<n;i++)
        {
            x=y;
          scanf("%d",&y);
          if(abs(y-x)>max)
            {
                max=abs(y-x);
                xx=i;yy=i+1;
            }
        }
        printf("%d %d\n",xx,yy);
   }
   return 0;
}
