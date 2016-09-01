#include<stdio.h>
int main()
{
    int T;
    int l,v,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&l,&v,&m);
        if(v>0)    printf("YES\n");
        else    printf("NO\n");
    }
    return 0;
}
