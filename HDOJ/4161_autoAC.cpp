#include <stdio.h>
int sum=-1;
int dif(int a[],int n)
{
    int i,s=0;
    bool zero=true;
    sum++;
    for(i=0;i<n-1;i++)
    {    if(a[i]<0)
            a[i]=0-a[i];
        if(a[i+1]<0)
            a[i+1]=0-a[i+1];
        a[i]=a[i+1]-a[i];
        if(a[i]!=0)
            zero=false;
        s+=a[i];
    }
    a[n-1]=s;
    if(s==0 && zero)
        return sum;
    if(sum>1000)
        return -1;
    dif(a,n);
}
int main()
{
    int a[21];
    int n,temp=1;
    while(scanf("%d",&n)!=EOF && n)
    {
        sum=-1;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int num=dif(a,n);
        printf("Case %d: ",temp);
        if(num==-1)
            printf("not attained\n");
        else
            printf("%d iterations\n",num);
        temp++;
    }
    return 0;
}
