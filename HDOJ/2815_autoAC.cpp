#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL __int64
#define N 1000000
using namespace std;
struct Node{
    int idx;
    int val;
}baby[N];
bool cmp(Node n1,Node n2){
    return n1.val!=n2.val?n1.val<n2.val:n1.idx<n2.idx;
}
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int extend_gcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int gcd=extend_gcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return gcd;
}
int inval(int a,int b,int n){
    int e,x,y;
    extend_gcd(a,n,x,y);
    e=((LL)x*b)%n;
    return e<0?e+n:e;
}
int PowMod(int a,int b,int MOD){
    LL ret=1%MOD,t=a%MOD;
    while(b){
        if(b&1)
            ret=((LL)ret*t)%MOD;
        t=((LL)t*t)%MOD;
        b>>=1;
    }
    return (int)ret;
}
int BinSearch(int num,int m){
    int low=0,high=m-1,mid;
    while(low<=high){
        mid=(low+high)>>1;
        if(baby[mid].val==num)
            return baby[mid].idx;
        if(baby[mid].val<num)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int BabyStep(int A,int B,int C){
    LL tmp,D=1%C;
    int temp;
    for(int i=0,tmp=1%C;i<100;i++,tmp=((LL)tmp*A)%C)
        if(tmp==B)
            return i;
    int d=0;
    while((temp=gcd(A,C))!=1){
        if(B%temp) return -1;
        d++;
        C/=temp;
        B/=temp;
        D=((A/temp)*D)%C;
    }
    int m=(int)ceil(sqrt((double)C));
    for(int i=0,tmp=1%C;i<=m;i++,tmp=((LL)tmp*A)%C){
        baby[i].idx=i;
        baby[i].val=tmp;
    }
    sort(baby,baby+m+1,cmp);
    int cnt=1;
    for(int i=1;i<=m;i++)
        if(baby[i].val!=baby[cnt-1].val)
            baby[cnt++]=baby[i];
    int am=PowMod(A,m,C);
    for(int i=0;i<=m;i++,D=((LL)(D*am))%C){
        int tmp=inval(D,B,C);
        if(tmp>=0){
            int pos=BinSearch(tmp,cnt);
            if(pos!=-1)
                return i*m+pos+d;
        }
    }
    return -1;
}
int main(){
    int A,B,C;
    while(scanf("%d%d%d",&A,&C,&B)!=EOF){
        if(B>=C){
            puts("Orz,I cant find D!");
            continue;
        }
        int ans=BabyStep(A,B,C);
        if(ans==-1)
            puts("Orz,I cant find D!");
        else
            printf("%d\n",ans);
    }
    return 0;
}
