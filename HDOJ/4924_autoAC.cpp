#include <stdio.h>
#define INF 99999999
#define max(A,B)(A>B?A:B)
struct S{
int c[4],p[4],mx;
bool flag[4];
}node[20];
int n,hash[100],add[20][20],a,b,c,ansc,ansp,df,mf,st,gk,attach,dpc[13][3][13][13],dpp[13][3][13][13],sel[13];
void dfs(int now,int cnt)
{
    if(cnt==11)
    {
        int i,j,k,l,mx;
        attach=0;
        for(i=0;i<11;i++) for(j=0;j<11;j++) attach+=add[sel[i]][sel[j]];
        mx=0;
        for(i=0;i<11;i++) mx+=node[sel[i]].mx;
        if(mx+attach<ansc) return;
        gk=df=mf=st=0;
        for(i=0;i<11;i++)
        {
            if(node[sel[i]].flag[0]) gk++;
            if(node[sel[i]].flag[1]) df++;
            if(node[sel[i]].flag[2]) mf++;
            if(node[sel[i]].flag[3]) st++;
        }
        if(gk<1 || df<a || mf<b || st<c) return;
        for(i=0;i<=11;i++) for(j=0;j<=1;j++) for(k=0;k<=a;k++) for(l=0;l<=b;l++) dpc[i][j][k][l]=-INF;
        dpc[0][0][0][0]=dpp[0][0][0][0]=0;
        for(i=0;i<11;i++)
        {
            for(j=0;j<=1;j++)
            {
                for(k=0;k<=a;k++)
                {
                    for(l=0;l<=b;l++)
                    {
                        if(dpc[i][j][k][l]!=-INF)
                        {
                            if(node[sel[i]].flag[0])
                            {
                                if(dpc[i+1][j+1][k][l]<dpc[i][j][k][l]+node[sel[i]].c[0])
                                {
                                    dpc[i+1][j+1][k][l]=dpc[i][j][k][l]+node[sel[i]].c[0];
                                    dpp[i+1][j+1][k][l]=dpp[i][j][k][l]+node[sel[i]].p[0];
                                }
                                else if(dpc[i+1][j+1][k][l]==dpc[i][j][k][l]+node[sel[i]].c[0])
                                {
                                    dpp[i+1][j+1][k][l]=max(dpp[i][j][k][l]+node[sel[i]].p[0],dpp[i+1][j+1][k][l]);
                                }
                            }
                            if(node[sel[i]].flag[1])
                            {
                                if(dpc[i+1][j][k+1][l]<dpc[i][j][k][l]+node[sel[i]].c[1])
                                {
                                    dpc[i+1][j][k+1][l]=dpc[i][j][k][l]+node[sel[i]].c[1];
                                    dpp[i+1][j][k+1][l]=dpp[i][j][k][l]+node[sel[i]].p[1];
                                }
                                else if(dpc[i+1][j][k+1][l]==dpc[i][j][k][l]+node[sel[i]].c[1])
                                {
                                    dpp[i+1][j][k+1][l]=max(dpp[i][j][k][l]+node[sel[i]].p[1],dpp[i+1][j][k+1][l]);
                                }
                            }
                            if(node[sel[i]].flag[2])
                            {
                                if(dpc[i+1][j][k][l+1]<dpc[i][j][k][l]+node[sel[i]].c[2])
                                {
                                    dpc[i+1][j][k][l+1]=dpc[i][j][k][l]+node[sel[i]].c[2];
                                    dpp[i+1][j][k][l+1]=dpp[i][j][k][l]+node[sel[i]].p[2];
                                }
                                else if(dpc[i+1][j][k][l+1]==dpc[i][j][k][l]+node[sel[i]].c[2])
                                {
                                    dpp[i+1][j][k][l+1]=max(dpp[i][j][k][l]+node[sel[i]].p[2],dpp[i+1][j][k][l+1]);
                                }
                            }
                            if(node[sel[i]].flag[3])
                            {
                                if(dpc[i+1][j][k][l]<dpc[i][j][k][l]+node[sel[i]].c[3])
                                {
                                    dpc[i+1][j][k][l]=dpc[i][j][k][l]+node[sel[i]].c[3];
                                    dpp[i+1][j][k][l]=dpp[i][j][k][l]+node[sel[i]].p[3];
                                }
                                else if(dpc[i+1][j][k][l]==dpc[i][j][k][l]+node[sel[i]].c[3])
                                {
                                    dpp[i+1][j][k][l]=max(dpp[i][j][k][l]+node[sel[i]].p[3],dpp[i+1][j][k][l]);
                                }
                            }
                        }
                    }
                }
            }
        }
        dpc[11][1][a][b]+=attach;
        if(ansc<dpc[11][1][a][b]) ansc=dpc[11][1][a][b],ansp=dpp[11][1][a][b];
        else if(ansc==dpc[11][1][a][b]) ansp=max(dpp[11][1][a][b],ansp);
        return;
    }
    if(now>=n || cnt+n-now<11) return;
    sel[cnt]=now;
    dfs(now+1,cnt+1);
    dfs(now+1,cnt);
}
int main()
{
    int T,i,j,t,id,val;
    char s[5];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            hash[t]=i;
            for(j=0;j<4;j++) node[i].flag[j]=0;
            node[i].mx=-INF;
            scanf("%d",&t);
            while(t--)
            {
                scanf("%s",s);
                if(s[0]=='G') id=0;
                else if(s[0]=='D') id=1;
                else if(s[0]=='M') id=2;
                else id=3;
                scanf("%d%d",&node[i].c[id],&node[i].p[id]);
                node[i].mx=max(node[i].mx,node[i].c[id]);
                node[i].flag[id]=1;
            }
        }
        scanf("%d",&t);
        for(i=0;i<n;i++) for(j=0;j<n;j++) add[i][j]=0;
        while(t--)
        {
            scanf("%d%d%s%d",&a,&b,s,&val);
            if(s[0]=='D') add[hash[a]][hash[b]]=-val;
            else add[hash[a]][hash[b]]=val;
        }
        scanf("%d-%d-%d",&a,&b,&c);
        ansc=ansp=-INF;
        dfs(0,0);
        if(ansc>-INF) printf("%d %d\n",ansc,ansp);
        else printf("Poor Manager!\n");
    }
}
