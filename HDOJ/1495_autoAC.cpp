#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
int mark[105][105][105];
int flag;
int a,b,c;
int maxx,minn;
struct dian
{
  int map[3];
  int step;    
}st;
void bfs(dian st)
{
    queue<dian> p;
    mark[st.map[0]][st.map[1]][st.map[2]]=1;
    p.push(st);
    dian v,vn;
    while(!p.empty())
       {
         vn=p.front();
         p.pop();
         if(vn.map[0]==a/2&&vn.map[1]==a/2)
           {
             flag=1;
             printf("%d\n",vn.step);
             return;         
           }
         for(int i=1;i<=10;i++)
           {
             v.map[0]=vn.map[0];
             v.map[1]=vn.map[1];
             v.map[2]=vn.map[2];
             v.step=vn.step+1;
             if(i==1) {v.map[0]-=(maxx-v.map[1]);v.map[1]=maxx;}
             else if(i==2){v.map[0]=0;v.map[1]+=vn.map[0];}
             else if(i==3){v.map[0]-=(minn-v.map[2]);v.map[2]=minn;}
             else if(i==4){v.map[0]=0;v.map[1]+=vn.map[0];}
             else if(i==5){v.map[1]=0;v.map[0]+=vn.map[1];}
             else if(i==6){v.map[1]=0;v.map[2]+=vn.map[1];}               
             else if(i==7){v.map[1]-=(minn-v.map[2]);v.map[2]=minn;}
             else if(i==8){v.map[2]=0;v.map[1]+=vn.map[2];}
             else if(i==9){v.map[2]=0;v.map[0]+=vn.map[2];}
             else if(i==10){v.map[2]-=(maxx-v.map[1]);v.map[1]=maxx;}
             if(v.map[0]>a||v.map[0]<0||v.map[1]>maxx||v.map[1]<0||v.map[2]>minn||v.map[2]<0) continue;
             if(mark[v.map[0]][v.map[1]][v.map[2]]) continue;
             mark[v.map[0]][v.map[1]][v.map[2]]=1;
             p.push(v);
           }
       }    
}
int main()
{
  while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
      if(a==0&&b==0&&c==0)  break;
      flag=0;
      memset(mark,0,sizeof(mark));
      if(b==c)  {printf("1\n"); continue;}
      if(a%2==1)  {printf("NO\n"); continue;}
      if(b>c)  {maxx=b;minn=c;}
      else {maxx=c;minn=b;}
      st.map[0]=a;
      st.map[1]=0;
      st.map[2]=0;
      st.step=0;
      bfs(st);    
      if(!flag)  printf("NO\n");   
    }
}
