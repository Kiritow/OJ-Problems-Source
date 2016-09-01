#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAXN=10;
int hei[10];
int mp[300];
int a[30][5];
int p[100][30];
char s[100];
int first,anss;
int Cnt[10]={2,4,4,1,2,4,2};
int Dx[7][4]=
{
 0,0,0,0,
 0,-1,-1,-1,
 0,-1,-1,-1,
 0,0,-1,-1,
 0,0,-1,-1,
 0,-1,-1,-1,
 0,0,-1,-1
};
int Dy[7][4]=
{
 0,1,2,3,
 0,0,1,2,
 0,-2,-1,0,
 0,1,0,1,
 0,1,-1,0,
 0,-1,0,1,
 0,1,1,2
};
int rotx(int x,int y,int rot)
{
 if (rot==0) return x;
 if (rot==1) return y;
 if (rot==2) return -x;
 if (rot==3) return -y;
}
int roty(int x,int y,int rot)
{
 if (rot==0) return y;
 if (rot==1) return -x;
 if (rot==2) return -y;
 if (rot==3) return x;
}
bool set(int now,int id,int pos,int rot)
{
 for (int i=0; i<4; i++)
 {
 int dx1=Dx[id][i];
 int dy1=Dy[id][i];
 int dx=rotx(dx1,dy1,rot);
 int dy=roty(dx1,dy1,rot);
 if (pos+dy<0||pos+dy>=5) return false;
 }
 int target=0;
 for (int ii=MAXN; ii>=0; ii--)
 {
 for (int i=0; i<4; i++)
 {
 int dx1=Dx[id][i];
 int dy1=Dy[id][i];
 int dx=rotx(dx1,dy1,rot);
 int dy=roty(dx1,dy1,rot);
 if (ii+dx<0)
 {
 target=ii+1;
 break;
 }
 if (a[ii+dx][pos+dy]==1)
 {
 target=ii+1;
 break;
 }
 }
 if (target!=0) break;
 }
 for (int i=0; i<4; i++)
 {
 int dx1=Dx[id][i];
 int dy1=Dy[id][i];
 int dx=rotx(dx1,dy1,rot);
 int dy=roty(dx1,dy1,rot);
 //printf("%d %d\n",pos+dx,target+dy);
 a[target+dx][pos+dy]=1;
 }
 p[now][0]=target;
 p[now][1]=0;
 for (int i=MAXN; i>=0; i--)
 {
 bool find=true;
 for (int j=0; j<5; j++)
 if (a[i][j]!=1) find=false;
 if (find)
 {
 p[now][p[now][1]+2]=i;
 for (int j=i; j<MAXN; j++)
 for (int k=0; k<5; k++)
 a[j][k]=a[j+1][k];
 for (int k=0; k<5; k++)
 a[MAXN][k]=0;
 p[now][1]++;
 }
 }
 return true;
}
void remove(int now,int id,int pos,int rot)
{
 for (int ii=p[now][1]-1; ii>=0; ii--)
 {
 int line=p[now][ii+2];
 for (int i=MAXN; i>line; i--)
 for (int j=0; j<5; j++)
 a[i][j]=a[i-1][j];
 for (int j=0; j<5; j++)
 a[line][j]=1;
 }
 int target=p[now][0];
 for (int i=0; i<4; i++)
 {
 int dx1=Dx[id][i];
 int dy1=Dy[id][i];
 int dx=rotx(dx1,dy1,rot);
 int dy=roty(dx1,dy1,rot);
 a[target+dx][pos+dy]=0;
 }
}
void dfs(int now,int end)
{
 if (now==end)
 {
 int ans=0;
 for (int i=0; i<5; i++)
 {
 int max=0;
 for (int j=MAXN; j>=0; j--)
 if (a[j][i]==1)
 {
 max=(j+1);
 break;
 }
 ans+=max*max;
 }
 if (first||ans<anss)
 anss=ans;
 first=0;
 return;
 }
 for (int i=0; i<5*Cnt[mp[s[now]]]; i++)
 {
 int x=i/Cnt[mp[s[now]]];
 int rot=i%Cnt[mp[s[now]]];
 if (set(now,mp[s[now]],x,rot))
 {
 dfs(now+1,end);
 remove(now,mp[s[now]],x,rot);
 }
 }
}
int main()
{
 mp['I']=0;
 mp['J']=1;
 mp['L']=2;
 mp['O']=3;
 mp['S']=4;
 mp['T']=5;
 mp['Z']=6;
 int t;
 scanf("%d",&t);
 for (int ii=1; ii<=t; ii++)
 {
 scanf("%s",s);
 memset(a,0,sizeof(a));
 first=1;
 int len=strlen(s);
 dfs(0,len);
 printf("Case %d: %d\n",ii,anss);
 }
 return 0;
}
