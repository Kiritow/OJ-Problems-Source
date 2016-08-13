#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<time.h>
#include<map>
#include<algorithm>
#define ll long long
#define eps 1e-5
#define oo 1000000007
#define pi acos(-1.0)
#define MAXN 100005
#define MAXM 500005
using namespace std;  
int P[2][26],father[26];
bool used[26];
char s[1005];
int getfather(int x)
{
       if (father[x]==x) return x;
       return father[x]=getfather(father[x]);
}
int main()
{        
       int i,cases,n,m,x,y,t1,t2; 
       scanf("%d",&cases);
       while (cases--)
       {
               scanf("%d",&n); 
               memset(used,false,sizeof(used));
               memset(P,0,sizeof(P));
               for (i=0;i<26;i++) father[i]=i;
               for (i=1;i<=n;i++)
               {
                      scanf("%s",s+1);
                      x=s[1]-'a',y=s[strlen(s+1)]-'a'; 
                      P[0][x]++,P[1][y]++;
                      father[getfather(x)]=getfather(y);
                      used[x]=used[y]=true;
                      m=getfather(x);
               } 
               if (n==1) 
               {
                      printf("Ordering is possible.\n");
                      continue;
               } 
               for (i=0;i<26;i++)
                  if (used[i] && getfather(i)!=m) break;
               if (i<26)
               {
                      printf("The door cannot be opened.\n");
                      continue;
               }
               t1=t2=0;
               for (i=0;i<26;i++)
               {
                      if (P[0][i]==P[1][i]) continue;
                      if (P[0][i]+1==P[1][i]) t1++;
                      else
                      if (P[1][i]+1==P[0][i]) t2++;
                      else break;
               }
               if (i<26 || !(t1==1 && t2==1 || !t1 && !t2))
                      printf("The door cannot be opened.\n"); 
                 else 
                      printf("Ordering is possible.\n");
       }
       return 0;
}
