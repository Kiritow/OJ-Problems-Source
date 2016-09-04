#include<iostream>
#include<cmath>   
#include<string>
using namespace std;
char s[110000];
int ct[110000];
int main()
{
    int t,i,sum,len,j,max,move;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
      scanf("%s",&s);
      len=strlen(s);
      memset(ct,0,sizeof(ct));
      sum=0;
      for(j=0;j<len;j++)
      {
        if(s[j]=='A'){sum++;}
        ct[j]=sum;
      }
       max=ct[sum-1];
       for(j=0;j+sum<=len;j++)
        {
            move=ct[j+sum-1]-ct[j-1];
            if (move>max)
                max=move;
        }
        for(;j<len;j++)
        {
            move=ct[(j+sum)%len-1]+ct[len-1]-ct[j-1];
            if (move>max)
                max=move;
        }
        printf("Case %d: %d\n",i,sum-max);
    }
     return 0;
}
