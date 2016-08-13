#include<cstdio>
#include<cmath>
bool prime[10001];  
void IsPrime(){  
     prime[0]=prime[1]=0;prime[2]=1;  
     for(int i=3;i<=10000;i++)  
        prime[i]=i%2==0?0:1;  
     int t=(int)sqrt(10000*1.0);  
     for(int i=3;i<=t;i++)  
       if(prime[i])  
         for(int j=i*i;j<10000;j+=2*i) 
            prime[j]=0;  
}  
int main()
{
    IsPrime();
    int pri[10010];
    int num = 0;
    for(int i = 0; i < 10000; i++)
    {
        if(prime[i])
            pri[num++] = i;
    }
    int m, a, b;
    while(scanf("%d%d%d", &m, &a, &b)!=EOF && m && a && b)
    {
        int maxx = 0, ii, jj;
        for(int i = num-1; i >= 0; i--)
        {
            for(int j = i; j <= num-1; j++)
            {
                if(pri[j] > m || pri[i]*pri[j]>m || 1.0*pri[i]/pri[j]<1.0*a/b)
                    continue;
                else
                {
                    if(maxx < pri[i]*pri[j])
                    {
                        maxx = pri[i]*pri[j];
                        ii = pri[i];
                        jj = pri[j];
                    }
                }
            }
        }
        printf("%d %d\n", ii, jj);
    }
    return 0;
}
