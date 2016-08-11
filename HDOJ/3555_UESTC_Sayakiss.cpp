#include<cstdio>
#include<cmath>
unsigned long long n,ans,sa,nn,np,t,f,i,c[30][30],k,f49;
int fbreak,tcase;
void cc()
{
    int i,j;
    c[0][0]=1;
    c[1][0]=1;c[1][1]=1;
    for (i=0;i<25;i++)
    {
        c[i][0]=1;
        for (j=1;j<=i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
}
unsigned long long sayacal(long long n,int k)//10^n
{
    unsigned long long ans;
    sa=1;f=1;ans=0;
    while (1)
    {        
        sa++;k=k-2;n=n/100;if (n==0) break;
        if (f) 
        {
            ans=ans+c[sa+k-1][k]*n;
            f=0;
        }
        else
        {
            ans=ans-c[sa+k-1][k]*n;
            f=1;
        }
    }
    return ans;
}
    
int main()
{
    cc();//计算组合数
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%I64d",&n);
        if (n<49) {printf("0n");continue;}
        ans=0;fbreak=0;
        while (n)
        {
            k=0;nn=1;
            while(nn<n)
            {
                nn=nn*10;
                k++;
            }
            if (nn!=n) {nn=nn/10;k--;}
            np=nn;unsigned nnp=0;
            while (np<=n)
            {
                if (nnp!=4) ans+=sayacal(nn,k);
                else 
                {
                    ans+=nn/10+sayacal(nn,k);
                    ans-=sayacal(nn/10,k-1);
                }
                np+=nn;
                nnp++;
                if (nnp==4) f49=1; else f49=0;
            }
            n=n%nn;nn=nn/10;if (fbreak) break;
            if (nn) if (f49) if ((n/nn)>8)
            {
                ans+=n%nn+1;
                fbreak=1;
            }
        }
        printf("%I64dn",ans);
    }
}
