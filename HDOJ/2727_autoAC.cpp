#include<iostream>
using namespace std;
const int size=23;
const int num=251;
int n;  
int m;  
int lastx,lasty;
int map[size][size];  
bool link[num][num];  
int posx[]={0,-1,-2,-2,-1,1,2,2,1};   
int posy[]={0,2,1,-1,-2,-2,-1,1,2};
typedef class chess
{
    public:
    int color;   
    int r,c;
    int connet[8];  
    int pc;  
    chess()
    {
        color=-1;
        pc=0;
    }
}PEG;
void LinePeg(PEG* peg,int i);  
bool CheckWin(PEG* peg,bool flag);  
int main(void)
{
    while(cin>>n>>m)
    {
        if(!n && !m)
            break;
        memset(map,0,sizeof(map));
        memset(link,false,sizeof(link));
        PEG* peg=new PEG[m+1];
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            map[x][y]=i;  
            peg[i].r=x;
            peg[i].c=y;
            if(i%2)
                peg[i].color=1;  
            else
                peg[i].color=0;  
            if(i==m)  
            {
                lastx=x;
                lasty=y;
            }
            LinePeg(peg,i);  
        }
        if(CheckWin(peg,true) && !CheckWin(peg,false))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
void LinePeg(PEG* peg,int i)
{
    int color=peg[i].color;
    for(int k=1;k<=8;k++)
    {
        int r=peg[i].r+posx[k];
        int c=peg[i].c+posy[k];
        if(r>=0 && r<=n && c>=0 && c<=n)  
        {
            if(map[r][c] && peg[ map[r][c] ].color==color)  
            {
                switch(k)  
                {
                    case 1:  
                    {
                        if(link[ map[r][c-2] ][ map[r+1][c] ])
                            break;
                        if(c-3>=0 && link[ map[r][c-3] ][ map[r+1][c-1] ])
                            break;
                        if(c+1<=n && link[ map[r][c-1] ][ map[r+1][c+1] ])
                            break;
                        if(r-1>=0)
                        {
                            if(link[ map[r-1][c-2] ][ map[r+1][c-1] ])
                                break;
                            if(link[ map[r-1][c-1] ][ map[r+1][c] ])
                                break;
                            if(link[ map[r-1][c] ][ map[r+1][c-1] ])
                                break;
                        }
                        if(r+2<=n)
                        {
                            if(link[ map[r+2][c-2] ][ map[r][c-1] ])
                                break;
                            if(link[ map[r+2][c-1] ][ map[r][c-2] ])
                                break;
                            if(link[ map[r+2][c] ][ map[r][c-1] ])
                                break;
                        }
                        int a=map[peg[i].r][peg[i].c];
                        int b=map[r][c];
                        peg[a].connet[peg[a].pc++]=b;
                        peg[b].connet[peg[b].pc++]=a;
                        link[a][b]=link[b][a]=true;
                        break;
                    }
                    case 2:  //60搴逛
                    {
                        if(link[ map[r][c-1] ][ map[r+2][c] ])
                            break;
                        if(r-1>=0 && link[ map[r-1][c-1] ][ map[r+1][c] ])
                            break;
                        if(r+3<=n && link[ map[r+1][c-1] ][ map[r+3][c] ])
                            break;
                        if(c-2>=0)
                        {
                            if(link[ map[r][c-2] ][ map[r+1][c] ])
                                break;
                            if(link[ map[r+1][c-2] ][ map[r+2][c] ])
                                break;
                            if(link[ map[r+2][c-2] ][ map[r+1][c] ])
                                break;
                        }
                        if(c+1<=n)
                        {
                            if(link[ map[r][c-1] ][ map[r+1][c+1] ])
                                break;
                            if(link[ map[r+1][c-1] ][ map[r][c+1] ])
                                break;
                            if(link[ map[r+1][c-1] ][ map[r+2][c+1] ])
                                break;
                        }
                        int a=map[peg[i].r][peg[i].c];
                        int b=map[r][c];
                        peg[a].connet[peg[a].pc++]=b;
                        peg[b].connet[peg[b].pc++]=a;
                        link[a][b]=link[b][a]=true;
                        break;
                    }
                    case 3:  //120搴逛
                    {
                        if(link[ map[r][c+1] ][ map[r+2][c] ])
                            break;
                        if(r-1>=0 && link[ map[r-1][c+1] ][ map[r+1][c] ])
                            break;
                        if(r+3<=n && link[ map[r+1][c+1] ][ map[r+3][c] ])
                            break;
                        if(c-1>=0)
                        {
                            if(link[ map[r][c-1] ][ map[r+1][c+1] ])
                                break;
                            if(link[ map[r+1][c-1] ][ map[r][c+1] ])
                                break;
                            if(link[ map[r+2][c-1] ][ map[r+1][c+1] ])
                                break;
                        }
                        if(c+2<=n)
                        {
                            if(link[ map[r+1][c] ][ map[r][c+2] ])
                                break;
                            if(link[ map[r+2][c] ][ map[r+1][c+2] ])
                                break;
                            if(link[ map[r+1][c] ][ map[r+2][c+2] ])
                                break;
                        }
                        int a=map[peg[i].r][peg[i].c];
                        int b=map[r][c];
                        peg[a].connet[peg[a].pc++]=b;
                        peg[b].connet[peg[b].pc++]=a;
                        link[a][b]=link[b][a]=true;
                        break;
                    }
                    case 4:  //150搴逛
                    {
                        if(link[ map[r][c+2] ][ map[r+1][c] ])
                            break;
                        if(c-1>=0 && link[ map[r+1][c-1] ][ map[r][c+1] ])
                            break;
                        if(c+3<=n && link[ map[r+1][c+1] ][ map[r][c+3] ])
                            break;
                        if(r-1>=0)
                        {
                            if(link[ map[r-1][c] ][ map[r+1][c+1] ])
                                break;
                            if(link[ map[r-1][c+1] ][ map[r+1][c] ])
                                break;
                            if(link[ map[r-1][c+2] ][ map[r+1][c+1] ])
                                break;
                        }
                        if(r+2<=n)
                        {
                            if(link[ map[r][c+1] ][ map[r+2][c] ])
                                break;
                            if(link[ map[r][c+1] ][ map[r+2][c+2] ])
                                break;
                            if(link[ map[r][c+2] ][ map[r+2][c+1] ])
                                break;
                        }
                        int a=map[peg[i].r][peg[i].c];
                        int b=map[r][c];
                        peg[a].connet[peg[a].pc++]=b;
                        peg[b].connet[peg[b].pc++]=a;
                        link[a][b]=link[b][a]=true;
                        break;
                    }
                    case 5:  //210搴逛
                    {
                        if(link[ map[r-1][c] ][ map[r][c+2] ])
                            break;
                        if(c-1>=0 && link[ map[r-1][c-1] ][ map[r][c+1] ])
                            break;
                        if(c+3<=n && link[ map[r-1][c+1] ][ map[r][c+3] ])
                            break;
                        if(r-2>=0)
                        {
                            if(link[ map[r-2][c] ][ map[r][c+1] ])
                                break;
                            if(link[ map[r-2][c+1] ][ map[r][c+2] ])
                                break;
                            if(link[ map[r-2][c+2] ][ map[r][c+1] ])
                                break;
                        }
                        if(r+1<=n)
                        {
                            if(link[ map[r][c] ][ map[r-1][c+1] ])
                                break;
                            if(link[ map[r+1][c+1] ][ map[r-1][c] ])
                                break;
                            if(link[ map[r+1][c+2] ][ map[r-1][c+1] ])
                                break;
                        }
                        int a=map[peg[i].r][peg[i].c];
                        int b=map[r][c];
                        peg[a].connet[peg[a].pc++]=b;
                        peg[b].connet[peg[b].pc++]=a;
                        link[a][b]=link[b][a]=true;
                        break;
                    }
                    case 6:  //240搴逛
                    {
                        if(link[ map[r-2][c] ][ map[r][c+1] ])
                            break;
                        if(r-3>=0 && link[ map[r-3][c] ][ map[r-1][c+1] ])
                            break;
                        if(r+1<=n && link[ map[r-1][c] ][ map[r+1][c+1] ])
                            break;
                        if(c-1>=0)
                        {
                            if(link[ map[r-2][c-1] ][ map[r-1][c+1] ])
                                break;
                            if(link[ map[r-1][c-1] ][ map[r][c+1] ])
                                break;
                            if(link[ map[r][c-1] ][ map[r-1][c+1] ])
                                break;
                        }
                        if(c+2<=n)
                        {
                            if(link[ map[r-1][c] ][ map[r-2][c+2] ])
                                break;
                            if(link[ map[r-2][c] ][ map[r-1][c+2] ])
                                break;
                            if(link[ map[r-1][c] ][ map[r][c+2] ])
                                break;
                        }
                        int a=map[peg[i].r][peg[i].c];
                        int b=map[r][c];
                        peg[a].connet[peg[a].pc++]=b;
                        peg[b].connet[peg[b].pc++]=a;
                        link[a][b]=link[b][a]=true;
                        break;
                    }
                    case 7:  //300搴逛
                    {
                        if(link[ map[r-2][c] ][ map[r][c-1] ])
                            break;
                        if(r-3>=0 && link[ map[r-3][c] ][ map[r-1][c-1] ])
                            break;
                        if(r+1<=n && link[ map[r-1][c] ][ map[r+1][c-1] ])
                            break;
                        if(c-2>=0)
                        {
                            if(link[ map[r-2][c-2] ][ map[r-1][c] ])
                                break;
                            if(link[ map[r-1][c-2] ][ map[r-2][c] ])
                                break;
                            if(link[ map[r][c-2] ][ map[r-1][c] ])
                                break;
                        }
                        if(c+1<=n)
                        {
                            if(link[ map[r-1][c-1] ][ map[r-2][c+1] ])
                                break;
                            if(link[ map[r][c-1] ][ map[r-1][c+1] ])
                                break;
                            if(link[ map[r-1][c-1] ][ map[r][c+1] ])
                                break;
                        }
                        int a=map[peg[i].r][peg[i].c];
                        int b=map[r][c];
                        peg[a].connet[peg[a].pc++]=b;
                        peg[b].connet[peg[b].pc++]=a;
                        link[a][b]=link[b][a]=true;
                        break;
                    }
                    case 8:  //330搴逛
                    {
                        if(link[ map[r][c-2] ][ map[r-1][c] ])
                            break;
                        if(c-3>=0 && link[ map[r][c-3] ][ map[r-1][c-1] ])
                            break;
                        if(c+1<=n && link[ map[r][c-1] ][ map[r-1][c+1] ])
                            break;
                        if(r-2>=0)
                        {
                            if(link[ map[r-2][c-2] ][ map[r][c-1] ])
                                break;
                            if(link[ map[r-2][c-1] ][ map[r][c-2] ])
                                break;
                            if(link[ map[r-2][c] ][ map[r][c-1] ])
                                break;
                        }
                        if(r+1<=n)
                        {
                            if(link[ map[r-1][c-1] ][ map[r+1][c-2] ])
                                break;
                            if(link[ map[r-1][c-1] ][ map[r+1][c] ])
                                break;
                            if(link[ map[r-1][c] ][ map[r+1][c-1] ])
                                break;
                        }
                        int a=map[peg[i].r][peg[i].c];
                        int b=map[r][c];
                        peg[a].connet[peg[a].pc++]=b;
                        peg[b].connet[peg[b].pc++]=a;
                        link[a][b]=link[b][a]=true;
                        break;
                    }
                }
            }
        }
    }
    return;
}
bool CheckWin(PEG* peg,bool flag)
{
    int NUM;
    if(!flag)  
        NUM=map[lastx][lasty];
    for(int k=0;k<=n;k++)
    {
        int p=map[0][k];
        if(p && p!=NUM && peg[p].color==1)
        {
            int queue[num];
            bool vist[num]={false};
            int head=0;
            int tail=0;
            queue[tail++]=p;
            vist[p]=true;
            while(head<tail)
            {
                int s=queue[head++];
                if(peg[s].r==n)
                    return true;
                for(int i=0;i<peg[s].pc;i++)
                {
                    int x=peg[s].connet[i];
                    if(!vist[x])
                    {
                        vist[x]=true;
                        if(!flag && x==NUM)
                            continue;
                        queue[tail++]=x;
                    }
                }
            }
        }
    }
    return false;
}
