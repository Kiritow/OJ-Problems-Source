# include<stdio.h>
# include<string.h>
# define cc 100
# define rr 60
# define V 6000
int U[V],D[V];
int L[V],R[V];
int C[V],ROW[V];
int H[rr],S[cc];
int mark[rr],visit[27],size,ak;
struct node{
    int m;
    int num1,num2;
    int a[11][2],b[11][2];
}s[27];
void Link(int r,int c)
{
    S[c]++;
    C[size]=c;
    ROW[size]=r;
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
    {
        L[R[i]]=L[i];
        R[L[i]]=R[i];
    }
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
    bool hash[cc];
    memset(hash,0,sizeof(hash));
    for(i=R[0];i;i=R[i])
    {
        if(hash[i]) continue;
        hash[i]=1;
        count++;
        for(j=D[i];j!=i;j=D[j])
            for(k=R[j];k!=j;k=R[k])
                hash[C[k]]=1;
    }
    return count;
}
void Dance(int k)
{
    int j,i,c,Min;
    if(k+h()>=ak) return;
    if(!R[0]) 
    {
        if(k<ak) ak=k;
        return;
    }
    for(Min=rr,i=R[0];i;i=R[i])
        if(Min>S[i]) Min=S[i],c=i;
    for(i=D[c];i!=c;i=D[i])
    {
        if(visit[mark[ROW[i]]]) continue;
        visit[mark[ROW[i]]]=1;
        remove(i);
        for(j=R[i];j!=i;j=R[j])
            remove(j);
        Dance(k+1);
        for(j=L[i];j!=i;j=L[j])
            resume(j);
        resume(i);
        visit[mark[ROW[i]]]=0;
    }
}
int main()
{
    int i,j,ncase,t,n,sum[26],number,mob,k,c,r;
    scanf("%d",&ncase);
    for(t=1;t<=ncase;t++)
    {
        scanf("%d",&n);
        sum[0]=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&s[i].m);
            scanf("%d",&s[i].num1);
            for(k=0;k<s[i].num1;k++)
                scanf("%d%d",&s[i].a[k][0],&s[i].a[k][1]);
            if(s[i].m==2)
            {
                scanf("%d",&s[i].num2);
                for(k=0;k<s[i].num2;k++)
                    scanf("%d%d",&s[i].b[k][0],&s[i].b[k][1]);
            }
            sum[i+1]=sum[i]+s[i].m;
        }
        c=sum[n]-1;
        for(i=0;i<=c;i++)
        {
            S[i]=0;
            U[i]=D[i]=i;
            L[i+1]=i;R[i]=i+1;
        }R[c]=0;
        size=c+1;
        r=0;
        memset(H,-1,sizeof(H));
        for(i=0;i<n;i++)
        {
            r++;
            mark[r]=i;
            for(j=0;j<s[i].num1;j++)
            {
                number=s[i].a[j][0];
                mob=s[i].a[j][1];
                Link(r,sum[number]+mob);
            }
            for(j=0;j<s[i].m;j++)
                Link(r,sum[i]+j);
            if(s[i].m==2)
            {
                r++;
                mark[r]=i;
                for(j=0;j<s[i].num2;j++)
                {
                    number=s[i].b[j][0];
                    mob=s[i].b[j][1];
                    Link(r,sum[number]+mob);
                }
                for(j=0;j<s[i].m;j++)
                    Link(r,sum[i]+j);
            }
        }
        memset(visit,0,sizeof(visit));
        ak=n;
        Dance(0);
        printf("Case %d: %d\n",t,ak);
    }
    return 0;
}
