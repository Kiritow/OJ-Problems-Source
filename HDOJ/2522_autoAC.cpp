#include<iostream>
using namespace std;
int main()
{
    int a[100005],b[100005],t;
    scanf("%d",&t);
    while(t--)
    {
        int n,w=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        if(n<0)
        {
            n=-n;
            w=1;
        }
        int k=1;
        b[k]=1;
        int j=0;
        while(k&&n!=1)
        {
            k*=10;
            a[j++]=k/n;
            k%=n;
            if(b[k])
                break;
            b[k]=1;
        }
        if(w==1)
            printf("-");
        if(n==1)
            printf("1\n");
        else
        {
        printf("0.");
        for(int i=0;i<j;i++)
            printf("%d",a[i]);
        printf("\n");
        }
    }
    return 0;
}
