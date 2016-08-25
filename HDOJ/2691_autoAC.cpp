#include <stdio.h>
#include <string.h>
const int Mod=199997;
const int maxn=1000000;
char names[]="BOWRYG";
int s,t;
int a[24],b[24];
int cnt,box[Mod];
struct edge{
 long long to;
 int next,step;
 bool flag;
} e[maxn];
struct point{
 int step;
 bool flag;
 char a[24];
} qu[maxn];
int tr[12][4]={{0,1,3,2},
 {4,5,13,12},
 {6,7,15,14},
 {8,9,17,16},
 {10,11,19,18},
 {20,21,23,22}};
int netr[12][8]={{11,10,9,8,7,6,5,4},
 {0,2,6,14,20,22,19,11},
 {2,3,8,16,21,20,13,5},
 {3,1,10,18,23,21,15,7},
 {17,9,1,0,4,12,22,23},
 {12,13,14,15,16,17,18,19}};
void pre()
{
 for(int i=6;i<12;i++)
 {
 for(int j=0;j<4;j++)
 tr[i][j]=tr[i-6][3-j];
 for(int j=0;j<8;j++)
 netr[i][j]=netr[i-6][7-j];
 }
}
void hash(int &p1,long long &p2)
{
 p2=0;
 for(int i=0;i<24;i++)
 p2=p2*6+a[i];
 p1=p2%Mod;
}
void add(int p1,long long p2,int step,bool flag)
{
 e[cnt].to=p2;e[cnt].step=step;e[cnt].flag=flag;
 e[cnt].next=box[p1];box[p1]=cnt++;
 t++;
 qu[t].step=step;
 qu[t].flag=flag;
 for(int i=0;i<24;i++) qu[t].a[i]=a[i];
}
void finds(int p1,long long p2,bool &flag,int &step)
{
 for(int p=box[p1];p!=-1;p=e[p].next)
 if (e[p].to==p2)
 {
 flag=e[p].flag;
 step=e[p].step;
 return ;
 }
 step=-1;
}
int makeit()
{
 bool flag=1,nowflag;
 int step,q1,q2,q3,nowstep;
 for(int i=0;i<24;i++)
 flag=flag&&(a[i]==b[i]);
 if (flag) return 0;
 cnt=0;
 memset(box,-1,sizeof(box));
 int p1;
 long long p2;
 s=0;t=0;
 hash(p1,p2);
 add(p1,p2,0,0);
 for(int i=0;i<24;i++) a[i]=b[i];
 hash(p1,p2);
 add(p1,p2,0,1);
 while(s!=t)
 {
 s++;
 step=qu[s].step;
 flag=qu[s].flag;
 for(int i=0;i<24;i++)
 a[i]=qu[s].a[i];
 for(int i=0;i<12;i++)
 {
 q1=a[tr[i][0]];
 q2=a[netr[i][0]];
 q3=a[netr[i][1]];
 for(int j=0;j<3;j++)
 a[tr[i][j]]=a[tr[i][j+1]];
 a[tr[i][3]]=q1;
 for(int j=0;j<6;j++)
 a[netr[i][j]]=a[netr[i][j+2]];
 a[netr[i][6]]=q2;a[netr[i][7]]=q3;
 hash(p1,p2);
 finds(p1,p2,nowflag,nowstep);
 if (nowstep==-1)
 add(p1,p2,step+1,flag);
 else
 if (nowflag!=flag) return nowstep+step+1;
 int ii=(i+6);
 if (ii>=12) ii-=12;
 q1=a[tr[ii][0]];
 q2=a[netr[ii][0]];
 q3=a[netr[ii][1]];
 for(int j=0;j<3;j++)
 a[tr[ii][j]]=a[tr[ii][j+1]];
 a[tr[ii][3]]=q1;
 for(int j=0;j<6;j++)
 a[netr[ii][j]]=a[netr[ii][j+2]];
 a[netr[ii][6]]=q2;a[netr[ii][7]]=q3;
 }
 }
}
int trans(char ch)
{
 for(int i=0;i<6;i++)
 if (names[i]==ch) return i;
 return -1;
}
int main()
{
 int cas;
 char s[10];
 pre();
 scanf("%d",&cas);
 while(cas--)
 {
 for(int i=0;i<24;i++)
 {
 scanf("%s",s);
 a[i]=trans(s[0]);
 }
 for(int i=0;i<24;i++)
 {
 scanf("%s",s);
 b[i]=trans(s[0]);
 }
 printf("%d\n",makeit());
 }
 return 0;
}
