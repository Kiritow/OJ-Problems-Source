#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[30];
    int score;
    int kick;
    int lost;
}TEAM;
int is_exist(int len,TEAM *p,const char *s)
{
    int i;
    for(i = 0 ; i < len ; ++i)
    {
        if(!strcmp(p[i].name,s))
            return 1;
    }
    return 0;
}
int find(TEAM *p,int len,const char *s)
{
    int i;
    for(i = 0 ; i < len ; ++i)
    {
        if(!strcmp(p[i].name,s))
            return i;
    }
    return -1;
}
void swap(TEAM *p1,TEAM *p2)
{
    TEAM t = *p1;
    *p1 = *p2;
    *p2 = t;
}
void sort(TEAM *p,const int LEN)
{
    int i,j;
    for(i = 0 ; i < LEN ; ++i)
    {
        for(j = i + 1 ; j < LEN ; ++j)
        {
            if(p[i].score < p[j].score)
                swap(&p[i],&p[j]);
            else if(p[i].score == p[j].score)
            {
                if(p[i].kick - p[i].lost < p[j].kick - p[j].lost)
                    swap(&p[i],&p[j]);
                else if(p[i].kick - p[i].lost == p[j].kick - p[j].lost)
                {
                    if(p[i].kick < p[j].kick)
                        swap(&p[i],&p[j]);
                    else if(p[i].kick == p[j].kick)
                    {
                        if(strcmp(p[i].name,p[j].name) > 0)
                            swap(&p[i],&p[j]);
                    }
                }
            }
        }
    }
}
int main(int argc, char *argv[])
{
    int T,a,b;
    char t1[30],t2[30],vs[5],fen[10];
    TEAM team[5010];
    while(scanf("%d",&T) != EOF)
    {
        memset(team,0,sizeof(team));
        int t = T * (T - 1);
        int ix_team = 0;
        while(t--)
        {
            scanf("%s%s%s%s",t1,vs,t2,fen);
            sscanf(fen,"%d:%d",&a,&b);
            if(ix_team < T)
            {
                if(0 == is_exist(ix_team,team,t1))
                    strcpy(team[ix_team++].name,t1);
                if(0 == is_exist(ix_team,team,t2))
                    strcpy(team[ix_team++].name,t2);
            }
            int ix1 = find(team,ix_team,t1);
            int ix2 = find(team,ix_team,t2);
            int score;
            if(a > b) score = 3;
            else if(a == b) score = 1;
            else score = 0;
            team[ix1].kick += a;
            team[ix1].lost += b;
            team[ix1].score += score;
            if(b > a) score = 3;
            else if(b == a) score = 1;
            else score = 0;
            team[ix2].kick += b;
            team[ix2].lost += a;
            team[ix2].score += score;
        }
        sort(team,T);
        int i;
        for(i = 0 ; i < T ; ++i)
            printf("%s %d\n",team[i].name,team[i].score);
        printf("\n");
    }
    return 0;
}
