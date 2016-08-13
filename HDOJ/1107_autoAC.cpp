#include<stdio.h>
#include<string.h>
int w,s,e;
struct sl
{
  int neili,wuyi,hp,dps,x,y,flag,fang;    
}cuns[1005];
struct em
{
  int neili,wuyi,hp,dps,x,y,flag,fang;
}cune[1005];
struct wd
{
  int neili,wuyi,hp,dps,x,y,flag,fang;    
}cunw[1005];
struct map
{
  int sll,emm,wdd,slll,emmm,wddd;
}mmap[13][13];
void shaolingzou()
{
  for(int i=0;i<s;i++)
    {
       if(cuns[i].flag==1)
         {
           if(cuns[i].x==12)  cuns[i].fang=-1;
           if(cuns[i].x==1)   cuns[i].fang=1;
           mmap[cuns[i].x][cuns[i].y].sll--;
           cuns[i].x+=cuns[i].fang;
           mmap[cuns[i].x][cuns[i].y].sll++; 
           mmap[cuns[i].x][cuns[i].y].slll=i;        
         }    
    }
}
void wudangzou()
{
  for(int i=0;i<w;i++)
    {
       if(cunw[i].flag==1)
         {
            if(cunw[i].y==12)  cunw[i].fang=-1;
            if(cunw[i].y==1)   cunw[i].fang=1;
            mmap[cunw[i].x][cunw[i].y].wdd--;
            cunw[i].y+=cunw[i].fang;
            mmap[cunw[i].x][cunw[i].y].wdd++;
            mmap[cunw[i].x][cunw[i].y].wddd=i;    
         }
    }    
}
void emeizou()
{
  for(int i=0;i<e;i++)
     {
        if(cune[i].flag==1)
          {
            if(cune[i].x==12||cune[i].y==12)  cune[i].fang=-1;
            if(cune[i].x==1||cune[i].y==1)    cune[i].fang=1;
            if(cune[i].x==12&&cune[i].y==1)  continue;
            if(cune[i].y==12&&cune[i].x==1)  continue;
            mmap[cune[i].x][cune[i].y].emm--;
            cune[i].x+=cune[i].fang;
            cune[i].y+=cune[i].fang;
            mmap[cune[i].x][cune[i].y].emm++;
            mmap[cune[i].x][cune[i].y].emmm=i;        
          }    
     }    
}
void slove()
{
       for(int i=1;i<=12;i++)
         for(int j=1;j<=12;j++)
           {
           if(mmap[i][j].sll+mmap[i][j].wdd+mmap[i][j].emm==2)
             { 
                if(mmap[i][j].sll==1&&mmap[i][j].wdd==1)
                  {
                    int slll=mmap[i][j].slll;
                    int wddd=mmap[i][j].wddd; 
                    cuns[slll].hp-=cunw[wddd].dps;
                    cunw[wddd].hp-=cuns[slll].dps;
                    double a=(0.8*cunw[wddd].neili+0.2*cunw[wddd].wuyi)*(cunw[wddd].hp+10)/100;
                    cunw[wddd].dps=(int)a;    
                    double b=(0.5*cuns[slll].neili+0.5*cuns[slll].wuyi)*(cuns[slll].hp+10)/100;
                    cuns[slll].dps=(int)b;
                    if(cuns[slll].hp<=0)  {cuns[slll].flag=0; mmap[i][j].sll--;}
                    if(cunw[wddd].hp<=0)  {cunw[wddd].flag=0; mmap[i][j].wdd--;}
                  }    
                if(mmap[i][j].sll==1&&mmap[i][j].emm==1)
                  {
                    int slll=mmap[i][j].slll;
                    int emmm=mmap[i][j].emmm;
                    cuns[slll].hp-=cune[emmm].dps;
                    cune[emmm].hp-=cuns[slll].dps;    
                    double b=(0.5*cuns[slll].neili+0.5*cuns[slll].wuyi)*(cuns[slll].hp+10)/100;
                    cuns[slll].dps=(int)b;
                    double c=(0.2*cune[emmm].neili+0.8*cune[emmm].wuyi)*(cune[emmm].hp+10)/100;
                    cune[emmm].dps=(int)c;
                    if(cuns[slll].hp<=0)  {cuns[slll].flag=0; mmap[i][j].sll--;}
                    if(cune[emmm].hp<=0)  {cune[emmm].flag=0; mmap[i][j].emm--;}
                  }    
                if(mmap[i][j].emm==1&&mmap[i][j].wdd==1)
                  {
                    int emmm=mmap[i][j].emmm;
                    int wddd=mmap[i][j].wddd; 
                    cune[emmm].hp-=cunw[wddd].dps;
                    cunw[wddd].hp-=cune[emmm].dps;
                    double c=(0.2*cune[emmm].neili+0.8*cune[emmm].wuyi)*(cune[emmm].hp+10)/100;
                    cune[emmm].dps=(int)c;
                    double a=(0.8*cunw[wddd].neili+0.2*cunw[wddd].wuyi)*(cunw[wddd].hp+10)/100;
                    cunw[wddd].dps=(int)a;
                    if(cune[emmm].hp<=0)  {cune[emmm].flag=0; mmap[i][j].emm--;}    
                    if(cunw[wddd].hp<=0)  {cunw[wddd].flag=0; mmap[i][j].wdd--;}    
                  }
             }        
        }
}
void clear()
{
  memset(mmap,0,sizeof(mmap));
  memset(cuns,0,sizeof(cuns));
  memset(cunw,0,sizeof(cunw));
  memset(cune,0,sizeof(cune));    
}
int main()
{
   int T,N;
   char menpai[10];
   scanf("%d",&T);
   while(T--)
     {
       clear();
       w=s=e=0;
       scanf("%d",&N);
       while(scanf("%s",menpai)!=EOF)
       {
        if(menpai[0]=='0')  break;
        if(menpai[0]=='W')
         {
           scanf("%d%d%d%d%d",&cunw[w].x,&cunw[w].y,&cunw[w].neili,&cunw[w].wuyi,&cunw[w].hp);
           double a=(0.8*(double)cunw[w].neili+0.2*(double)cunw[w].wuyi)*((double)cunw[w].hp+10)/100.0;
           mmap[cunw[w].x][cunw[w].y].wdd++;
           mmap[cunw[w].x][cunw[w].y].wddd=w;
           cunw[w].dps=(int)a; 
           cunw[w].flag=1;
           cunw[w].fang=1;
           w++;
         }
        if(menpai[0]=='S')
         {
           scanf("%d%d%d%d%d",&cuns[s].x,&cuns[s].y,&cuns[s].neili,&cuns[s].wuyi,&cuns[s].hp);
           double b=(0.5*(double)cuns[s].neili+0.5*(double)cuns[s].wuyi)*((double)cuns[s].hp+10)/100.0;
           cuns[s].dps=(int)b;
           mmap[cuns[s].x][cuns[s].y].sll++;
           mmap[cuns[s].x][cuns[s].y].slll=s;
           cuns[s].fang=1;
           cuns[s].flag=1;    
           s++;
         }
        if(menpai[0]=='E')
         {
           scanf("%d%d%d%d%d",&cune[e].x,&cune[e].y,&cune[e].neili,&cune[e].wuyi,&cune[e].hp);
           double c=(0.2*(double)cune[e].neili+0.8*(double)cune[e].wuyi)*((double)cune[e].hp+10)/100;
           cune[e].dps=(int)c;
           mmap[cune[e].x][cune[e].y].emm++;
           mmap[cune[e].x][cune[e].y].emmm=e;
           cune[e].fang=1;
           cune[e].flag=1;
           e++;
         }
       }
       for(int i=1;i<=N;i++)
         {
              slove();
              shaolingzou();
              wudangzou();
              emeizou();
         }
       int sum=0,count=0;
       for(int i=0;i<s;i++)
         {
           if(cuns[i].flag==1)
             {
               count++;
               sum+=cuns[i].hp;        
             }          
         }
       printf("%d %d\n",count,sum);
       sum=count=0;
       for(int i=0;i<w;i++)
         {
           if(cunw[i].flag==1)
             {
               count++;
               sum+=cunw[i].hp;        
             }          
         }
        printf("%d %d\n",count,sum);
        count=sum=0;
        for(int i=0;i<e;i++)
         {
           if(cune[i].flag==1)
             {
               count++;
               sum+=cune[i].hp;        
             }          
         }
        printf("%d %d\n",count,sum);
        printf("***\n");
     }    
}
