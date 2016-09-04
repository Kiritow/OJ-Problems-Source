#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1005][1005];
int ques[1005];
struct mike{
    int sum,k,num;
}b[1005];
int n,s,p;
bool cmp(mike a,mike b){
    if(a.sum!=b.sum) return a.sum>b.sum;
    if(a.num!=b.num) return a.num>b.num;
    else return a.k<b.k;
}
int main(){
    int i,j;
    while(~scanf("%d%d%d",&n,&s,&p)){
        memset(ques,0,sizeof(ques));
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++){
            for(j=0;j<s;j++){
                scanf("%d",&a[i][j]);
                ques[i]+=a[i][j];
                b[j].num+=a[i][j];
            }
        }
        for(i=0;i<s;i++){
            b[i].k=i;
            for(j=0;j<n;j++)
                if(a[j][i]){
                    b[i].sum+=s-ques[j];
                }
        }
        sort(b,b+s,cmp);
        for(i=0;i<s;i++){
            if(b[i].k==p-1) break;
        }
        printf("%d %d\n",b[i].sum,i+1);
    }
    return 0;
}
