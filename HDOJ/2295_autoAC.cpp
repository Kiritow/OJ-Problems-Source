# include<stdio.h>
# include<math.h>
# include<string.h>
# define eps 1e-8
# define N 55
# define V 3600
int n,m,K;
int L[V],R[V];
int D[V],U[V];
int C[V];
int S[N],H[N];
int ak,size;
double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
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
    bool visit[N];
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
void Dance(int k)
{
    int i,j,c,Min,ans;
    ans=h();
    if(k+ans>K || k+ans>=ak) return;
    if(!R[0])
    {
        if(k<ak) ak=k;
        return;
    }
    for(Min=N,i=R[0];i;i=R[i])
        if(S[i]<Min) Min=S[i],c=i;
    for(i=D[c];i!=c;i=D[i])
    {
        remove(i);
        for(j=R[i];j!=i;j=R[j])
            remove(j);
        Dance(k+1);
        for(j=L[i];j!=i;j=L[j])
            resume(j);
        resume(i);
    }
    return;
}
int main()
{
    int i,j,ncase;
    double x[N],y[N],x1[N],y1[N];
    double left,right,ans,mid;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d%d",&n,&m,&K);
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&x[i],&y[i]);
        for(i=1;i<=m;i++)
            scanf("%lf%lf",&x1[i],&y1[i]);
        left=0;
        right=1416.0;
        ans=right;
        while(right>=left)
        {
            for(i=0;i<=n;i++)
            {
                S[i]=0;
                U[i]=D[i]=i;
                L[i+1]=i;R[i]=i+1;
            }R[n]=0;
            memset(H,-1,sizeof(H));
            size=n+1;
            mid=(left+right)/2;
            for(i=1;i<=m;i++)
            {
                for(j=1;j<=n;j++)
                    if(mid>=dis(x1[i],y1[i],x[j],y[j]))  Link(i,j); 
            }
            ak=N;
            Dance(0);
            if(ak<=K) {ans=mid<ans?mid:ans;right=mid-eps;}
            else left=mid+eps;
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}
