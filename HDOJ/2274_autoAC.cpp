#include<stdio.h>
#include<string.h>
int a[6],s[100005],sum;
int main()
{
    for(int i=0;i<=99999;i++) {  
        int t=i,k=0,sum;
        while(t>0) {
            a[k++]=t%10;
            t/=10;
        }
        int tmp=0;
        for(int j=0;j<k;j++)
            tmp+=a[j];
        s[i]=tmp*24*11111-i;
    } 
    while(~scanf("%d",&sum)) {  
        for(int i=0;i<=99999;i++)
            if(sum==s[i]) printf("%05d\n",i);
    }
    return 0;
}
