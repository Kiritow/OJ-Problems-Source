#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define Len 200
using namespace std;
typedef struct
{
    int S,E;
    int times,timee;
}node;
typedef struct
{
    int num,aver;
}nodf;
node E[Len];
nodf AN[Len];
int ID[1000];
int main()
{
    char SE;
    int id,h,m;
    int idnum,annum;
    int sum,ber;
    int x,y;
    idnum=0,annum=0;
    while(scanf("%d",&id)!=EOF)
    {   
        if(id==-1)
        {
            for(int i=0;i<annum;i++)
            printf("%d %d\n",AN[i].num,AN[i].aver);
            annum=0,idnum=0;
        }
        if(id==0)
        {
            cin>>SE;
            sum=0,ber=0;
            for(int i=0;i<idnum;i++)
            {
                if(E[ID[i]].S==1&&E[ID[i]].E==1)
                {
                    sum+=(E[ID[i]].timee-E[ID[i]].times);
                    ber++;
                }
            }
            if(ber==0)
            {
                AN[annum].aver=0;
                AN[annum].num=0;
                annum++;
            }
            else
            {   
                AN[annum].aver=sum/ber;
                AN[annum].num=ber;
                x=sum%ber;
                if((x*2)>=ber)
                AN[annum].aver++;
                annum++;
            }
            memset(E,0,sizeof(E));
            memset(ID,0,sizeof(ID));
            idnum=0;
        }
        if(id!=0&&id!=-1)
        {
            cin>>SE;
            scanf("%d:%d",&h,&m);
            if(SE=='S')
            {
                ID[idnum]=id;
                idnum++;
                E[id].times=h*60+m;
                E[id].S=1;
            }
            if(SE=='E')
            {
                E[id].timee=h*60+m;
                E[id].E=1;
            }
        }
}
return 0;
}
