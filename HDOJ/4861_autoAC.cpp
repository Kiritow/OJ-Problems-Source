#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
   int k,p;
   while(scanf("%d%d",&k,&p)!=EOF)
   {
       if((k/(p-1))%2==1)
       printf("YES\n");
       else
       printf("NO\n");
   }
   return 0;
}
