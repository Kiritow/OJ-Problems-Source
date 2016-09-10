#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;
int str[120];
int main()
{
  int n,i,res;
  while(scanf("%d",&n)!=EOF)
  {
      res=10;
      for(i=0;i<n;i++)
    {
       scanf("%d",&str[i]);
      if(str[i]&1==1&&res>str[i])
          res=str[i];
    }
    if(res==10){
        printf("-1\n");
        continue;
    }
    sort(str,str+n,greater<int>());
     int fir=-1,st=res;
    for(i=0;i<n;i++)
    {
        if(res==str[i]) res=-1;
        else
        {
            fir=str[i];
            break;
        }
    }
    if(fir==0) printf("-1\n");
    else
    {
        if(fir!=-1)
          printf("%d",fir);
        for( i++; i<n;i++)
        if(res==str[i])res=-1;
        else
         printf("%d",str[i]);
        printf("%d\n",st);
    }
  }
  return 0;
}
