#include<stdio.h>
#include<string.h>
struct cal{
    int id;
    int state;
    int score;
    int kill_ZG;
    int kill_ZC;
    int kill_FZ;
    int kill_NJ;
    int killed_by;
}player[101];
int num_ZG,num_ZC,num_FZ,num_NJ;
int n,m,flag;
int whether_win();
void calc_score(int num);
int main()
{
    int t,i,a,b,id;
    char name[3];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(player,0,sizeof(player[0])*n);
        num_ZG=num_ZC=num_FZ=num_NJ=0;
        for(i=0;i<n;i++){
            scanf("%s",name);
            switch(name[1]){
            case 'G':player[i].id=1;num_ZG++;break;
            case 'C':player[i].id=2;num_ZC++;break;
            case 'Z':player[i].id=3;num_FZ++;break;
            case 'J':player[i].id=4;num_NJ++;break;
            }
        }
        flag=whether_win();
        while(m--){
            scanf("%d%d",&a,&b);
            if(flag)
                continue;
            player[b].state=1;
            if(!num_FZ&&!num_ZC&&num_NJ==1&&num_ZG==1)
                player[b].killed_by=player[a].id;
            id=player[b].id;
            switch(id){
            case 1:num_ZG--;player[a].kill_ZG++;break;
            case 2:num_ZC--;player[a].kill_ZC++;break;
            case 3:num_FZ--;player[a].kill_FZ++;break;
            case 4:num_NJ--;player[a].kill_NJ++;break;
            }
            flag=whether_win();
        }
        calc_score(flag);
        printf("%d",player[0].score);
        for(i=1;i<n;i++)
            printf(" %d",player[i].score);
        printf("\n");
    }
    return 0;
}
int whether_win(void)
{
    if(!num_FZ&&!num_NJ)
        return 1;
    if(!num_ZG){
        if(num_NJ==1&&!num_FZ&&!num_ZC)
            return 2;
        else
            return 3;
    }
    return 0;
}
void calc_score(int num)
{
    int i;
    switch(num){
    case 1:
        for(i=0;i<n;i++)
            switch(player[i].id){
            case 1:player[i].score=4+num_ZC*2+player[i].kill_FZ+player[i].kill_NJ;break;
            case 2:player[i].score=5+num_ZC+player[i].kill_FZ+player[i].kill_NJ;break;
            case 4:if(player[i].killed_by==1) player[i].score=n;break;
        }
        break;
    case 2:
        for(i=0;i<n;i++)
            switch(player[i].id){
            case 1:player[i].score=1;break;
            case 4:if(!player[i].state) player[i].score=4+n*2;break;
        }
        break;
    case 3:
        for(i=0;i<n;i++)
            switch(player[i].id){
            case 3:player[i].score=num_FZ*3+player[i].kill_ZC+player[i].kill_NJ+player[i].kill_ZG*2;break;
            case 4:if(!player[i].state) player[i].score=1;
        }
        break;
    }
    return;
}
