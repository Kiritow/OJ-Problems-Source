#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
const int CCC=20;
const int RR=400;
const int V=8000;
const double eps=1e-7;
const int N=65550;
bool hash[N];
int st[N];
const double pi = acos(-1.0);
int U[V],D[V];
int L[V],R[V];
int C[V];
int size,S[CCC],H[RR],n,m;
int dir[17]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
struct node{
    double x,y;
}s[20];
struct point{
    double x,y;
}cnt,cnt1;
double Dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point Whirl(double cosl, double sinl, point a, point b)
{    
    b.x -= a.x; b.y -= a.y;
    point c;
    c.x = b.x * cosl - b.y * sinl + a.x;
    c.y = b.x * sinl + b.y * cosl + a.y;
    return c;
}
point inst(point u1,point u2,point v1,point v2)
{
    point ans = u1;
    double t = ((u1.x - v1.x)*(v1.y - v2.y) - (u1.y - v1.y)*(v1.x - v2.x))/
                ((u1.x - u2.x)*(v1.y - v2.y) - (u1.y - u2.y)*(v1.x - v2.x));
    ans.x += (u2.x - u1.x)*t;
    ans.y += (u2.y - u1.y)*t;
    return ans;
}
point fun(point a,point b,double r)
{
    double l=Dis(a,b);
    double ans=acos((l/2)/r);
    point k1=Whirl(cos(ans),sin(ans),a,b);
    point k2=Whirl(cos(ans),-sin(ans),b,a);
    point cent=inst(a,k1,b,k2);
    return cent;
}
void Link(int r,int c)
{
    S[c]++;C[size]=c;
    U[size]=U[c];D[U[c]]=size;
    D[size]=c;U[c]=size;
    if(H[r]==-1) H[r]=L[size]=R[size]=size;
    else
    {
        L[size]=L[H[r]];R[L[H[r]]]=size;
        R[size]=H[r];L[H[r]]=size;
    }
    size++;
}
void remove(int c)
{
    int i;
    for(i=D[c];i!=c;i=D[i])
        L[R[i]]=L[i],R[L[i]]=R[i];
}
void resume(int c)
{
    int i;
    for(i=U[c];i!=c;i=U[i])
        L[R[i]]=R[L[i]]=i;
}
int h()
{
    int i,j,k,count=0;
    bool visit[20];
    memset(visit,0,sizeof(visit));
    for(i=R[0];i;i=R[i])
    {
        if(visit[i]) continue;
        count++;
        visit[i]=1;
        for(j=D[i];j!=i;j=D[j])
        {
            for(k=R[j];k!=j;k=R[k])
                visit[C[k]]=1;
        }
    }
    return count;
}
int Dance(int k)
{
    int i,j,Min,c;
    if(k+h()>m) return 0;
    if(!R[0]) return 1;
    for(Min=RR,i=R[0];i;i=R[i])
        if(S[i]<Min) Min=S[i],c=i;
        for(i=D[c];i!=c;i=D[i])
        {
            remove(i);
            for(j=R[i];j!=i;j=R[j])
            {
                remove(j);
            }
            if(Dance(k+1)) return 1;
            for(j=L[i];j!=i;j=L[j])
                resume(j);
            resume(i);
        }
        return 0;
}
double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int i,j,ncase,r,k,bit,sum;
    double left,right,mid,ansx,ansy,ans,num;
    point a,b;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&s[i].x,&s[i].y);
        left=0.0;
        right=7.1;
        ans=7.1;
        while(right>=left)
        {
            for(i=0;i<=n;i++)
            {
                S[i]=0;
                U[i]=D[i]=i;
                L[i+1]=i;R[i]=i+1;
            }R[n]=0;
            size=n+1;
            memset(H,-1,sizeof(H));
            memset(hash,0,sizeof(hash));
            mid=(left+right)/2;
            r=0;
            sum=0;
            for(i=1;i<=n;i++)
            {
                ansx=s[i].x;ansy=s[i].y;
                bit=0;
                for(j=1;j<=n;j++)
                    if(dis(s[j].x,s[j].y,ansx,ansy)<=mid) bit+=dir[j-1];
                    if(!hash[bit]) {hash[bit]=1;st[++sum]=bit;}
            }
            for(i=1;i<=n;i++)
            {
                for(j=i+1;j<=n;j++)
                {
                    num=dis(s[i].x,s[i].y,s[j].x,s[j].y);
                    if(num<2*mid)
                    {
                        a.x=s[i].x;a.y=s[i].y;
                        b.x=s[j].x;b.y=s[j].y;
                        cnt=fun(a,b,mid);
                        ansx=(a.x+b.x)/2;
                        ansy=(a.y+b.y)/2;
                        cnt1.x=2*ansx-cnt.x;
                        cnt1.y=2*ansy-cnt.y;
                        bit=0;
                        for(k=1;k<=n;k++)
                        {
                            if(k==i) {bit+=dir[i-1];continue;}
                            if(k==j) {bit+=dir[j-1];continue;}
                            if(dis(s[k].x,s[k].y,cnt.x,cnt.y)<=mid) bit+=dir[k-1];
                        }
                        if(!hash[bit]) {hash[bit]=1;st[++sum]=bit;}
                        bit=0;
                        for(k=1;k<=n;k++)
                        {
                            if(k==i) {bit+=dir[i-1];continue;}
                            if(k==j) {bit+=dir[j-1];continue;}
                            if(dis(s[k].x,s[k].y,cnt1.x,cnt1.y)<=mid) bit+=dir[k-1];
                        }
                        if(!hash[bit]) {hash[bit]=1;st[++sum]=bit;}
                    }
                    else if(num==2*mid)
                    {
                        ansx=(s[i].x+s[j].x)/2;
                        ansy=(s[i].y+s[j].y)/2;
                        bit=0;
                        for(k=1;k<=n;k++)
                        {
                            if(k==i) {bit+=dir[i-1];continue;}
                            if(k==j) {bit+=dir[j-1];continue;}
                            if(dis(s[k].x,s[k].y,ansx,ansy)<=mid) bit+=dir[k-1];
                        }
                        if(!hash[bit]) {hash[bit]=1;st[++sum]=bit;}
                    }
                }
            }
            qsort(st+1,sum,sizeof(st[1]),cmp);
            for(i=sum;i>=1;i--)
            {
                for(j=1;j<=n;j++)
                    if(st[i]&dir[j-1]) hash[st[i]-dir[j-1]]=0;
                if(hash[st[i]]==0) continue;
                r++;
                for(j=1;j<=n;j++)
                    if(st[i]&dir[j-1]) {Link(r,j);hash[dir[j-1]]=0;}
            }
            if(Dance(0)) {ans=mid;right=mid-eps;}
            else left=mid+eps;
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}
