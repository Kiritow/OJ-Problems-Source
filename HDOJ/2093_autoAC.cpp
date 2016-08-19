#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 10005
typedef struct {
    char name[15];
    int ac;
    int time;
}Stu;
int N,M;
Stu record[maxn];
int cmp_struct(const void* now,const void* next)
{
    Stu* Now = (Stu*)now;
    Stu* Next = (Stu*)next;
    if(Now->ac == Next->ac){
        if(Now->time == Next->time)
            return strcmp(Now->name,Next->name);
        return (Now->time - Next->time);
    }
    return (Next->ac - Now->ac);
}
int main()
{
    int cnt = 0;
    memset(record,0,sizeof(record));
    scanf("%d%d",&N,&M);
    while(scanf("%s",record[cnt].name)!=EOF){
        int ac;
        char c;
        int time;
        for(int i = 0 ; i < N ; i++){
            scanf("%d",&ac);
            if(ac > 0){
                record[cnt].ac++;
                record[cnt].time += ac;
            }
            if((c = getchar())=='('){
                scanf("%d",&time);
                getchar();
                record[cnt].time += time * M;
            }
        }
        cnt++;
    }
    qsort(record,cnt,sizeof(record[0]),cmp_struct);
    for(int i = 0 ; i < cnt ; ++i)
        printf("%-10s %2d %4d\n",record[i].name,record[i].ac,record[i].time);
    return 0;
}
