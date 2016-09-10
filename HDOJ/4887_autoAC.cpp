#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
using namespace std;
#define ll __int64
#define usint unsigned int
const usint NONE=0xffffffff;
int n,s1,s2;
int a1[33],a2[33];
usint xo;
class hash {
public:
    hash() {
        memset(a,0xff,sizeof(a));
    }
    usint locate(usint x) {
        usint l=x%MOD;
        while(a[l]!=x&&a[l]!=NONE) l=l+1;
        return l;
    }
    void insert(usint x,usint va) {
        usint l=locate(x);
        if(a[l]==NONE) {
            a[l]=x;
            v[l]=va;
        }
    }
    usint get(usint x) {
        usint l=locate(x);
        return a[l]==x?v[l]:NONE;
    }
    void clear() {
        memset(a,0xff,sizeof(a));
    }
private:
    static const usint MOD=1000007;
    usint a[MOD+100],v[MOD+100];
} S;
struct vct {
    bool a[33];
    vct(bool q[33]) {
        for(int i=0; i<=n; i++)
            a[i]=q[i];
    }
    vct() {}
    void clear() {
        memset(a,0,sizeof(a));
    }
    void show() {
        for(int i=0; i<=n; i++)
            printf("%d ",a[i]);
        puts("");
    }
};
struct matrix {
    bool a[33][33];
    matrix(bool q[33][33]) {
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                a[i][j]=q[i][j];
    }
    matrix() {}
    void clear() {
        memset(a,0,sizeof(a));
    }
    friend matrix operator *(matrix A,matrix B) {
        matrix re;
        int i,j,k;
        re.clear();
        for(i=0; i<=n; i++)
            for(j=0; j<=n; j++)
                for(k=0; k<=n; k++)
                    re.a[i][j]=(re.a[i][j]^(A.a[i][k]*B.a[k][j]));
        return re;
    }
    void danwei() {
        memset(a,0,sizeof(a));
        for(int i=0; i<=n; i++)
            a[i][i]=1;
    }
    void show() {
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++)
                printf("%d ",a[i][j]);
            puts("");
        }
    }
};
inline usint atox(bool a[33],int n) {
    usint re=0;
    for(int i=0; i<n; i++)
        re=(re<<1)+a[n-i-1];
    return re;
}
inline int xtoa(bool a[33],int n,usint x) {
    for(int i=0; i<n; i++) {
        a[i]=x&1;
        x=x>>1;
    }
}
void check(bool a[33],int n) {
    for(int i=0; i<n; i++)
        printf("%2d",a[i]);
    puts("");
}
inline usint next(usint now) {
    bool a[33],j;
    usint re;
    xtoa(a,n,now);
    j=a[a1[0]];
    for(int i=1; i<s1; i++)
        j^=a[a1[i]];
    re=(now>>1)+(j<<(n-1));
    re^=xo;
    return re;
}
vct operator * (matrix mt,vct v) {
    vct re;
    int i,j;
    re.clear();
    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            re.a[i]=(re.a[i]^(mt.a[i][j]*v.a[j]));
    return re;
}
matrix qpow(matrix a,usint x) {
    matrix re,t;
    re.danwei();
    t=a;
    while(x>0) {
        if(x&1==1)re=re*t;
        x=x>>1;
        t=t*t;
    }
    return re;
}
int main() {
    usint i,j;
    bool a[33];
    usint cnt;
    usint st,ed,now,m,t;
    matrix ni,nc,n1,n2;
    vct v;
    while(scanf("%d%d%d",&n,&s1,&s2)!=EOF) {
        for(i=0; i<s1; i++) {
            scanf("%d",&a1[i]);
            a1[i]--;
        }
        xo=0;
        for(i=0; i<s2; i++) {
            scanf("%d",&j);
            a2[i]=j-1;
            xo=xo|(1<<(j-1));
        }
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        st=atox(a,n);
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        ed=atox(a,n);
        n1.clear();
        n2.clear();
        for(i=0; i<=n; i++)
            n2.a[i][i]=1;
        for(i=0; i<s2; i++)
            n2.a[a2[i]][n]=1;
        for(i=0; i<s1; i++)
            if(a1[i]>0) n1.a[0][a1[i]-1]=1;
        n1.a[0][n-1]=1;
        for(i=0; i<n-1; i++)
            n1.a[i+1][i]=1;
        n1.a[n][n]=1;
        ni=n1*n2;
        now=st;
        S.clear();
        m=ceil(sqrt(((usint)1)<<n));
        for(i=0; i<m; i++) {
            S.insert(now,i);
            now=next(now);
        }
        nc=qpow(ni,m);
        now=ed;
        cnt=0;
        t=S.get(now);
        while(t==NONE) {
            if(cnt>m) break;
            xtoa(v.a,n,now);
            v.a[n]=1;
            v=nc*v;
            now=atox(v.a,n);
            cnt++;
            t=S.get(now);
        }
        if(t==NONE) printf("poor sisyphus\n");
        else printf("%u\n",cnt*m+t);
    }
    return 0;
}
