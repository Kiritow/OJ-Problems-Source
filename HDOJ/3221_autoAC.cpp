# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# define N 1000005
int visit[N],prime[N],K;
__int64 P,Phi;
struct matrix{
    __int64 A[2][2];
};
void intt()
{
    int i,j;
    memset(visit,0,sizeof(visit));
    for(i=2;i<=1000;i++)
    {
        if(visit[i]==0)
        {
            for(j=i+i;j<=1000000;j+=i)
            {
                visit[j]=1;
            }
        }
    }
    K=0;
    for(j=2;j<=1000000;j++)
        if(visit[j]==0) prime[++K]=j;
}
matrix power(matrix ans1,matrix ans2)
{
    int i,j,k;
    matrix ans;
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            ans.A[i][j]=0;
            for(k=0;k<=1;k++)
            {
                ans.A[i][j]+=ans1.A[i][k]*ans2.A[k][j];
                if(ans.A[i][j]>Phi)
                {
                    ans.A[i][j]=ans.A[i][j]%Phi+Phi;
                }
            }
        }
    }
    return ans;
}
matrix mod(matrix un,__int64 k)
{
    matrix ans;
    ans.A[0][0]=1;
    ans.A[0][1]=0;
    ans.A[1][0]=0;
    ans.A[1][1]=1;
    while(k)
    {
        if(k%2) ans=power(ans,un);
        un=power(un,un);
        k/=2;
    }
    return ans;
}
__int64 mod1(__int64 a,__int64 k)
{
    __int64 ans;
    ans=1;
    while(k)
    {
        if(k%2) 
        {
            ans=ans*a;
            ans%=P;
        }
        a=a*a;
        a%=P;
        k/=2;
    }
    return ans%P;
}
int main()
{
    int i,ncase,t;
    __int64 a,b,aa,bb,n,num,num1,num2;
    matrix init,ans;
    intt();
    scanf("%d",&ncase);
    for(t=1;t<=ncase;t++)
    {
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&P,&n);
        printf("Case #%d: ",t);
        if(n==1) {printf("%I64d\n",a%P);continue;}
        else if(n==2) {printf("%I64d\n",b%P); continue;}
        else if(n==3) {printf("%I64d\n",a*b%P);continue;}
        if(P==1) {printf("0\n");continue;}
        init.A[0][0]=0;
        init.A[0][1]=1;
        init.A[1][0]=1;
        init.A[1][1]=1;
        Phi=1;
        num=P;
        for(i=1;i<=K;i++)
        {
            if(prime[i]>P) break;
            if(P%prime[i]==0) {Phi*=(prime[i]-1);num/=prime[i];}
        }
        Phi*=num;
        ans=mod(init,n-3);
        num1=ans.A[1][1];
        num2=ans.A[0][1]+ans.A[1][1];
        if(num2>Phi) num2=num2%Phi+Phi;
        aa=mod1(a,num1);
        bb=mod1(b,num2);
        printf("%I64d\n",aa*bb%P);
    }
    return 0;
}
