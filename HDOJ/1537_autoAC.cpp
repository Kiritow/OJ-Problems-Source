#include<cstdio>
#include<cstring>
char a[6][9],s[3];
int T,cas;
void turn(int i,int j)
{
    char p[9];
    memcpy(p,a[i],sizeof(p));
    if(j==1)
    {
        for(int k=0,l=0;k<9;k+=3,l++)
        a[i][k]=p[6+l],a[i][k+1]=p[3+l],a[i][k+2]=p[l];
    }
    else
    {
        for(int k=0,l=0;k<9;k+=3,l++)
        a[i][k]=p[2-l],a[i][k+1]=p[5-l],a[i][k+2]=p[8-l];
    }
}
void go(int P,char &b,char &c,char &d,char &e,char &f,char &g,char &h,char &i,char &j,char &k,char &l,char &m)
{
    char o=k,p=l,q=m;
    if(P==1)
    {
        m=j;l=i;k=h;j=g;i=f;h=e;g=d;f=c;e=b;d=q;c=p;b=o;
    }
    else
    {
        k=b;l=c;m=d;b=e;c=f;d=g;e=h;f=i;g=j;h=o;i=p;j=q;
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<9;i++){scanf("%s",s);a[4][i]=s[0];}
        for(int i=0;i<9;i+=3)
        for(int j=0;j<4;j++)
        for(int k=0;k<3;k++)
        {scanf("%s",s);a[j][i+k]=s[0];}
        for(int i=0;i<9;i++){scanf("%s",s);a[5][i]=s[0];}
        int t,f,p;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d",&f,&p);
            turn(f,p);
            if(f==0)
            go(p,a[4][0],a[4][3],a[4][6],a[1][0],a[1][3],a[1][6],a[5][0],a[5][3],a[5][6],a[3][8],a[3][5],a[3][2]);
            if(f==1)
            go(p,a[4][6],a[4][7],a[4][8],a[2][0],a[2][3],a[2][6],a[5][2],a[5][1],a[5][0],a[0][8],a[0][5],a[0][2]);
            if(f==2)
            go(p,a[5][8],a[5][5],a[5][2],a[1][8],a[1][5],a[1][2],a[4][8],a[4][5],a[4][2],a[3][0],a[3][3],a[3][6]);
            if(f==3)
            go(p,a[4][2],a[4][1],a[4][0],a[0][0],a[0][3],a[0][6],a[5][6],a[5][7],a[5][8],a[2][8],a[2][5],a[2][2]);
            if(f==4)
            go(p,a[3][2],a[3][1],a[3][0],a[2][2],a[2][1],a[2][0],a[1][2],a[1][1],a[1][0],a[0][2],a[0][1],a[0][0]);
            if(f==5)
            go(p,a[1][6],a[1][7],a[1][8],a[2][6],a[2][7],a[2][8],a[3][6],a[3][7],a[3][8],a[0][6],a[0][7],a[0][8]);
        }
        printf("Scenario #%d:\n",++cas);
        for(int i=0;i<9;i+=3)printf("      %c %c %c\n",a[4][i],a[4][i+1],a[4][i+2]);
        for(int i=0;i<9;i+=3)
        for(int j=0;j<4;j++)
        printf("%c %c %c%c",a[j][i],a[j][i+1],a[j][i+2],j==3?'\n':' ');
        for(int i=0;i<9;i+=3)printf("      %c %c %c\n",a[5][i],a[5][i+1],a[5][i+2]);
        puts("");
    }
}
