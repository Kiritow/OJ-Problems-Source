#include<stdio.h>
#include<string.h>
int main()
{
    int t,l,n,a[21][21],i,j,k,o;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(int)*21*21);
        k=0;
        scanf("%d%d",&l,&n);
        o=n;
        while(o--)
        {
            scanf("%d%d",&i,&j);
            if(a[i][j]==0) a[i][j]=1;
            else k++;
        }
        if((n-k)%4==0)printf("YES\n");
        else printf("NO\n");
    }
}
