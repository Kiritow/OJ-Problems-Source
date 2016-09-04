# include<stdio.h>
# include<string.h>
# define N 200
# define V 900
int n,m,size,ak;
int U[V],D[V];
int L[V],R[V];
int C[V];
int H[N],S[N];
int visit[17][17];
int rr,cc;
char map[17][17];
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
    bool hash[N];
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
    int i,j,Min,c;
    if(h()+k>=ak) return;
    if(!R[0])
    {
        if(k<ak) ak=k;
        return;
    }
    for(Min=N,i=R[0];i;i=R[i])
        if(Min>S[i]) Min=S[i],c=i;
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
}
int main()
{
    int i,j,k1,k2;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cc=0;
        memset(visit,0,sizeof(visit));
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(j=0;map[i][j];j++)
                if(map[i][j]=='#') visit[i][j]=++cc;
        }
        for(i=0;i<=cc;i++)
        {
            S[i]=0;
            D[i]=U[i]=i;
            L[i+1]=i;R[i]=i+1;
        }R[cc]=0;
        size=cc+1;
        memset(H,-1,sizeof(H));
        rr=0;
        for(i=1;i<n-1;i++)
        {
            for(j=1;j<m-1;j++)
                if(map[i][j]=='.') 
                {
                    rr++;
                    k1=i-1;k2=j;
                    while(map[k1][k2]=='.') k1--;
                    if(map[k1][k2]=='#') Link(rr,visit[k1][k2]);
                    k1=i+1;k2=j;
                    while(map[k1][k2]=='.') k1++;
                    if(map[k1][k2]=='#') Link(rr,visit[k1][k2]);
                    k1=i;k2=j-1;
                    while(map[k1][k2]=='.') k2--;
                    if(map[k1][k2]=='#') Link(rr,visit[k1][k2]);
                    k1=i;k2=j+1;
                    while(map[k1][k2]=='.') k2++;
                    if(map[k1][k2]=='#') Link(rr,visit[k1][k2]); 
                }
        }
        ak=N;
        Dance(0);
        printf("%d\n",ak);
    }
    return 0;
}
