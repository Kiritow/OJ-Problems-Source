#include <stdio.h>
#include <string.h>
#define maxn 150
#define mod 1000000007
struct matrix{
    int v[70][70];
    void clear(){
        memset(v,0,sizeof(v));
    }
} a,b;
int st_num[maxn],stn;
int n,m;
int ans;
int f[10][10][maxn];
int q[2][maxn],qn[2];
void dfs(int p,int mask,int st){
    if (p==n){
        if ((mask&(1<<n))==0){
            a.v[st_num[st]][st_num[mask]]++;
        }
        return;
    }
    int c1=((mask>>p)&1),c2=((mask>>p+1)&1);
    if (c1 && c2){
        dfs(p+1,mask^(1<<p)^(1<<p+1),st);
    }else
    if (c1 || c2){
        dfs(p+1,mask,st);
        dfs(p+1,mask^(1<<p)^(1<<p+1),st);
    }else{
        dfs(p+1,mask^(1<<p)^(1<<p+1),st);
    }
}
matrix mat_mul(matrix a,matrix b){
    matrix c;
    for (int i=0;i<stn;i++)
        for (int j=0;j<stn;j++){
            c.v[i][j]=0;
            for (int k=0;k<stn;k++)
                c.v[i][j]=(c.v[i][j]+(long long)a.v[i][k]*b.v[k][j])%mod;
        }
    return c;
}
matrix Mul(int p){
    matrix ret,ta=a;
    ret.clear();
    for (int i=0;i<stn;i++) ret.v[i][i]=1;
    while (p){
        if ((p&1)>0) ret=mat_mul(ret,ta);
        ta=mat_mul(ta,ta);
        p>>=1;
    }
    return ret;
}
inline int getBit(int mask,int p){
    return (mask>>p)&1;
}
inline void Add(int &x,int v){
    x=(x+v)%mod;
}
int cal(int st1,int st2,int c1,int c2){
    int ret=0;
    int now=0,next;
    qn[0]=1;
    q[0][0]=st1;
    memset(f,0,sizeof(f));
    for (int i=0;i<n;i++){
        next=now^1;
        qn[next]=0;
        for (int p=0;p<qn[now];p++){
            int st=q[now][p];
            if (i==0 || getBit(st,n)==getBit(st2,i-1)){
                if (i==0){
                    f[0][0][st<<1]=1;
                    q[next][qn[next]++]=st<<1;
                }else{
                    int nst=st;
                    if (getBit(st2,i-1)) nst-=(1<<n);
                    Add(f[i][0][nst<<1],f[i-1][n][st]);
                    q[next][qn[next]++]=nst<<1;
                }
            }
        }
        now=next;        
        for (int j=0;j<n;j++){
            next=now^1;
            qn[next]=0;
            for (int p=0;p<qn[now];p++){
                int st=q[now][p],nst;
                int c1=getBit(st,j),c2=getBit(st,j+1);
                if (c1 && c2){
                    nst=st^(1<<j)^(1<<j+1);
                    if (f[i][j+1][nst]==0){
                        q[next][qn[next]++]=nst;
                    }
                    Add(f[i][j+1][nst],f[i][j][st]);
                }else
                if (c1 || c2){
                    nst=st;
                    if (f[i][j+1][nst]==0){
                        q[next][qn[next]++]=nst;
                    }
                    Add(f[i][j+1][nst],f[i][j][st]);
                    nst=st^(1<<j)^(1<<j+1);
                    if (f[i][j+1][nst]==0){
                        q[next][qn[next]++]=nst;
                    }
                    Add(f[i][j+1][nst],f[i][j][st]);
                }else{
                    nst=st^(1<<j)^(1<<j+1);
                    if (f[i][j+1][nst]==0){
                        q[next][qn[next]++]=nst;
                    }
                    Add(f[i][j+1][nst],f[i][j][st]);
                }
            }
            now=next;
        }
    }
    for (int i=0;i<qn[now];i++){
        int st=q[now][i];
        if (getBit(st,n)==getBit(st2,n-1)){
            int nst=st;
            if (getBit(st,n)) nst-=(1<<n);
            if (nst==0) Add(ret,f[n-1][n][st]);
        }
    }
    long long tmp=ret;
    tmp*=c1;
    tmp%=mod;
    tmp*=c2;
    tmp%=mod;
    ret=tmp;
    return ret;
}
int main(){
    int cp=0;
    while (scanf("%d%d",&n,&m)!=EOF){
        printf("Case %d: ",++cp);
        if (n%2){
            puts("0");
            continue;
        }
        stn=0;
        memset(st_num,-1,sizeof(st_num));
        for (int i=0;i<(1<<n);i++){
            int k=0;
            for (int j=0;j<n;j++)
                if ((i&(1<<j))>0) k++;
            if (k%2==0){
                st_num[i]=stn++;
            }
        }
        a.clear();
        for (int i=0;i<(1<<n);i++)
            if (st_num[i]>-1) dfs(0,i<<1,i);
        b=Mul(m-n);
        ans=0;
        for (int i=0;i<(1<<n);i++)
            for (int j=0;j<(1<<n);j++){
                int si=st_num[i],sj=st_num[j];
                if (b.v[0][si] && b.v[0][sj]) ans=(ans+cal(i,j,b.v[0][si],b.v[0][sj]))%mod;
            }
        printf("%d\n",ans);
    }
    return 0;
}
