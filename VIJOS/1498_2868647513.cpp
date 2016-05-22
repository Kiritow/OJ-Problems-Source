#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct zong{
    int sum,num;
}y[2001];
struct heng{
    int sum,num;
}x[2001];
int dog(const zong&a,const zong&b)
{
    return a.sum>b.sum;
}
int cat(const heng&a,const heng&b)
{
    return a.sum>b.sum;
}
int tiger(const zong&a,const zong&b)
{
    return a.num<b.num;
}
int sheep(const heng&a,const heng&b)
{
    return a.num<b.num;
}
int main()
{
    int m,n,k,l,d,x1,y1,x2,y2,i;
    scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
    for(i=1;i<=m;i++){
        x[i].num=i;
    }
    for(i=1;i<=n;i++){
        y[i].num=i;
    }
    for(i=1;i<=d;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1==x2){
            y[y1<y2?y1:y2].sum++;
        }
        else{
            x[x1<x2?x1:x2].sum++;
        }
    }
    sort(x+1,x+m+1,cat);
    sort(y+1,y+n+1,dog);
    sort(x+1,x+k+1,sheep);
    sort(y+1,y+l+1,tiger);
    for(i=1;i<=k;i++){
        printf("%d ",x[i].num);
    }
    printf("\n");
    for(i=1;i<=l;i++){
        printf("%d ",y[i].num);
    }
    return 0;
}
