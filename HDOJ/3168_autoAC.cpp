#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX=1000005,MAXN=105,INF=1<<30;
int n,b,c;
int has[MAXN],
pos[MAX];
int main()
{
 bool endFlag;
 int u,v,p,adv,ft;
 while(scanf("%d %d %d",&n,&b,&c)==3){
 memset(has,0,sizeof(has));
 for(int i=0;i<n;i++) pos[i]=1;
 for(int i=0;i<b;i++){
 scanf("%d %d",&u,&v);
 has[u]=v;
 }
 endFlag=0;
 for(int i=0;i<c;i++){
 scanf("%d",&ft);
 if(endFlag){
 continue;
 }
 p=i%n;
 adv=pos[p]+ft;
 if(has[adv])
 adv=has[adv];
 if(adv<=100)
 pos[p]=adv;
 else
 pos[p]=100;
 if(pos[p]==100){
 endFlag=1;
 }
 }
 for(int i=0;i<n;i++)
 printf("Position of player %d is %d.\n",i+1,pos[i]);
 }
 return 0;
}
