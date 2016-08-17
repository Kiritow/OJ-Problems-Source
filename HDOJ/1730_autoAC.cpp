#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{ 
  int n,m;
  int i;
  int ti,ji;
  int ans;
  while(scanf("%d%d",&n,&m)!=EOF)
  {
      ans=0;
     while(n--)
     {
        scanf("%d%d",&ti,&ji);
       ans^=abs(abs(ti-ji)-1);
     }
     printf("%s\n",ans==0?"BAD LUCK!":"I WIN!");
  }
 return 0;
}
