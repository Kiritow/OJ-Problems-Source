#include <cstdio>
#include <cstring>
struct Snooker{
    char name[2][30];
    int score[2];
    int ball_cnt[10];
    int red_cnt;
    int turn;
    int next;
    bool over;
    bool foul[5];
    int penalty;
    int ball_first;
    bool replaced[10];
    bool first;
    bool second;
    bool last;
    char stroke[2000];
    char ball_name[10];
}game;
void init1()
{
    int i;
    game.score[0] = game.score[1] = 0;
    game.ball_cnt[1] = 15;
    for(i=2;i<=7;i++)
        game.ball_cnt[i] = 1;
    game.turn = 0;
    game.next = 1;
    game.last = false;
    game.over = false;
}
void init2()
{
    game.red_cnt = 0;
    memset(game.foul,false,sizeof(game.foul));
    game.penalty = 4;
    game.ball_first = -1;
    memset(game.replaced,false,sizeof(game.replaced));
    game.first = game.second = false;
}
int gao1()
{
    char ch[][10] = {"None","Red","Yellow","Green","Brown","Blue","Pink","Black","White"};
    for(int i=0;i<9;i++)
        if(strcmp(game.ball_name,ch[i])==0)
            return i;
    return -1;
}
void gao2()
{
    int state = gao1();
    if(state==0)
        game.foul[0] = true;
    else 
    {
        if(game.next == 1 && state > 1)
            game.foul[1] = true;
        else if(game.next > 1 && state == 1)
            game.foul[1] = true;
        else if(game.next <= 7 && game.next != state)
            game.foul[1] = true;
    }
    game.first = true;
    game.ball_first = state;
}
void gao3()
{
    if(game.second)
    {
        int state = gao1();
        if(game.ball_first != state)
            game.foul[2] = true;
        if(state > 7)
            game.foul[3] = true;
        if(state == 1)
            game.red_cnt++;
        game.replaced[state] = true;
    }
}
void gao4()
{
    int i;
    if(game.last)
    {
        if(game.foul[0] || game.foul[1] || game.foul[2] || game.foul[3])
        {
            printf("Foul!\n");
            game.score[game.turn^1] += 7;
        }
        else if(game.second)
            game.score[game.turn] += 7;
        game.turn^=1;
        printf("%d : %d\n",game.score[0],game.score[1]);
        if(game.foul[0] || game.foul[1] || game.foul[2] || game.foul[3] || game.second)
        {
            if(game.score[0] == game.score[1])
            {
                printf("Tie\nRespot Black\n");
                game.next = 7;
            }
            else
            {
                if(game.score[0] > game.score[1])
                    printf("%s wins\n",game.name[0]);
                else
                    printf("%s wins\n",game.name[1]);
                game.over = true;
            }
        }
        else
            printf("%s's turn\n",game.name[game.turn]);
        return;
    }
    game.ball_cnt[1] -= game.red_cnt;
    if(game.foul[0] || game.foul[1] || game.foul[2] || game.foul[3])
    {
        printf("Foul!\n");
        game.turn^=1;
        game.score[game.turn] += game.penalty;
        printf("%d : %d\n",game.score[0],game.score[1]);
        if(game.replaced[2] || game.replaced[3] || game.replaced[4] || game.replaced[5] || game.replaced[6] || game.replaced[7])
        {
            char ch[][10] = {"","","Yellow","Green","Brown","Blue","Pink","Black"};
            printf("Respot");
            for(i=2;i<=7;i++)
            {
                if(game.replaced[i])
                    printf(" %s",ch[i]);
            }
            printf("\n");
        }
        for(i=1;i<=7;i++)
        {
            if(game.ball_cnt[i] > 0)
            {
                game.next = i;
                break;
            }
        }
        if(!game.foul[3])
            printf("%s's turn\n",game.name[game.turn]);
        else
            printf("%s's turn, in-hand\n",game.name[game.turn]);
    }
    else
    {
        if(game.next == 1)
            game.score[game.turn] += game.red_cnt;
        else if(game.second)
            game.score[game.turn] += game.ball_first;
        printf("%d : %d\n",game.score[0],game.score[1]);
        if(game.next == 8 && game.second)
        {
            char ch[][10] = {"","","Yellow","Green","Brown","Blue","Pink","Black"};
            printf("Respot");
            for(i=2;i<=7;i++)
            {
                if(game.replaced[i])
                    printf(" %s",ch[i]);
            }
            printf("\n");
        }
        else
        {
            if(game.next > 1 && game.second)
            {
                game.ball_cnt[game.next]--;
                if(game.ball_cnt[6] == 0)
                    game.last = true;
            }
        }
        if(game.red_cnt > 0)
            game.next = 8;
        else
        {
            for(i=1;i<=7;i++)
            {
                if(game.ball_cnt[i] > 0)
                {
                    game.next = i;
                    break;
                }
            }
        }
        if(!game.second)
        {
            game.turn^=1;
            printf("%s's turn\n",game.name[game.turn]);
        }
    }
}
int Max(int a,int b)
{
    if(a > b)
        return a;
    return b;
}
int main()
{
    int t,ca,len,i,fi;
    scanf("%d",&t);
    for(ca=1;ca<=t;ca++)
    {
        if(ca>1)
            printf("\n");
        printf("Frame %d\n",ca);
        init1();
        scanf(" %s %s",game.name[0],game.name[1]);
        getchar();
        printf("%s's turn, in-hand\n",game.name[game.turn]);
        while(!game.over)
        {
            gets(game.stroke);
            if(strcmp(game.stroke,"Play again")==0)
            {
                game.turn^=1;
                if(!game.foul[3])
                    printf("%s's turn\n",game.name[game.turn]);
                else
                    printf("%s's turn, in-hand\n",game.name[game.turn]);
                continue;
            }
            if(strcmp(game.stroke,game.name[0])==0)
            {
                game.turn=0;
                printf("%s's turn, in-hand\n",game.name[game.turn]);
                continue;
            }
            if(strcmp(game.stroke,game.name[1])==0)
            {
                game.turn=1;
                printf("%s's turn, in-hand\n",game.name[game.turn]);
                continue;
            }
            len = strlen(game.stroke);
            init2();
            for(i=fi=0;i<len;i++)
            {
                if(game.stroke[i] == ' ' || i + 1 == len)
                {
                    if(fi == 0)
                        continue;
                    if(i + 1 == len)
                        game.ball_name[fi++] = game.stroke[i];
                    if(gao1()<8)
                        game.penalty = Max(game.penalty,gao1());
                    if(!game.first)
                        gao2();
                    else
                        game.second = true;
                    gao3();
                    fi = 0;
                    memset(game.ball_name,'\0',sizeof(game.ball_name));
                }
                else
                {
                    game.ball_name[fi++] = game.stroke[i];
                }
            }
            if(game.next<8)
                game.penalty = Max(game.penalty,game.next);
            gao4();
        }
    }
    return 0;
}
