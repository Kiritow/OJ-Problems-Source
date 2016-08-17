#include<stdio.h>
#include<stdlib.h>
#define M 100000
#include<string.h>
struct ln{
    int xuehao;
    char name[10];
    int score;
};
struct ln a[M+10];
int cmpx(const void *a,const void *b){
    return (*(ln*)a).xuehao-(*(ln*)b).xuehao;
}
int cmpn(const void *a,const void *b){
    ln *c=(ln*)a;
    ln *d=(ln *)b;
    if(!strcmp(c->name,d->name))            
    return c->xuehao-d->xuehao;
    else
    return strcmp(c->name,d->name);
}
int cmps(const void *a,const void *b){
    ln *c=(ln*)a;
    ln *d=(ln *)b;
    if(c->score==d->score)
    return  c->xuehao-d->xuehao;
    else 
    return c->score-d->score;
}
int main(){
    int n,c;
    int i;
    int t=0;
    while(scanf("%d%d",&n,&c)&&n){
        t++;
        for(i=0;i<n;i++){
            scanf("%d%s%d",&a[i].xuehao,a[i].name,&a[i].score);
        }
        if(c==1)
        qsort(a,n,sizeof(a[0]),cmpx);
        if(c==2)
        qsort(a,n,sizeof(a[0]),cmpn);
        if(c==3)
        qsort(a,n,sizeof(a[0]),cmps);
        printf("Case %d:\n",t);
        for(i=0;i<n;i++){
            printf("%06d %s %d\n",a[i].xuehao,a[i].name,a[i].score);
        }
    }
    return 0;
}
