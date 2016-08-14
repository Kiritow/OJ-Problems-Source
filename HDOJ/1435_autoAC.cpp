#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 205
int engage[N],n;
int boy[N][N],girl[N][N];
void Gale_Shapley(){
    queue<int> q;
    int boyid,girlid;
    for(int i=1;i<=n;i++){
        engage[i]=0;
        boy[i][0]=1;
        q.push(i);
    }
    while(!q.empty()){
        boyid=q.front();
        girlid=boy[boyid][boy[boyid][0]++];
        if(engage[girlid]==0){
            engage[girlid]=boyid;
            q.pop();
        }
        else{
            int i;
            for(i=1;i<=n;i++)
                if(girl[girlid][i]==boyid||girl[girlid][i]==engage[girlid])
                    break;
            if(girl[girlid][i]==boyid){
                q.push(engage[girlid]);
                engage[girlid]=boyid;
                q.pop();
            }
        }
    }
}
struct dis{
    double s;
    double c;
    int id;
};
struct type{
    double c;
    double x,y,z;
    dis D[N];
}O[N],I[N];
void cal_dis(int x){
    for(int i=1;i<=n;i++){
        double d=0;
        d+=(O[x].x-I[i].x)*(O[x].x-I[i].x);
        d+=(O[x].y-I[i].y)*(O[x].y-I[i].y);
        d+=(O[x].z-I[i].z)*(O[x].z-I[i].z);
        d=sqrt(d);
        O[x].D[i].s=d;
        O[x].D[i].id=i;
        O[x].D[i].c=I[i].c;
        I[i].D[x].s=d;
        I[i].D[x].id=x;
        I[i].D[x].c=O[x].c;
    }
}
bool cmp(dis a,dis b){
    if(a.s==b.s)
        return a.c>b.c;
    return a.s<b.s;
}
int main(void){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int id;
            scanf("%d",&id);
            scanf("%lf%lf%lf%lf",&O[id].c,&O[id].x,&O[id].y,&O[id].z);
        }
        for(int i=1;i<=n;i++){
            int id;
            scanf("%d",&id);
            scanf("%lf%lf%lf%lf",&I[id].c,&I[id].x,&I[id].y,&I[id].z);
        }
        for(int i=1;i<=n;i++)
            cal_dis(i);
        for(int i=1;i<=n;i++){
            sort(O[i].D+1,O[i].D+n+1,cmp);
            for(int j=1;j<=n;j++)
                boy[i][j]=O[i].D[j].id;
        }
        for(int i=1;i<=n;i++){
            sort(I[i].D+1,I[i].D+n+1,cmp);
            for(int j=1;j<=n;j++)
                girl[i][j]=I[i].D[j].id;
        }
        Gale_Shapley();
        int X[N],Y[N];
        for(int i=1;i<=n;i++){
            X[i]=i;
            Y[i]=engage[i];
        }
        for(int i=1;i<=n;i++)
            printf("%d %d\n",Y[i],X[i]);
        printf("\n");
    }
}
