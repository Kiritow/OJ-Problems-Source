#include<stdio.h>
int main()
{
    int t,n,i,c1,c2;
    char a,b,h;
    scanf("%d",&t);
    while(t--)
    {
        c1=c2=0;
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%c%c%c",&a,&h,&b);
            getchar();
            if((a=='R'&&b=='S')||(a=='S'&&b=='P')||(a=='P'&&b=='R'))
                c1++;
            else if((b=='R'&&a=='S')||(b=='S'&&a=='P')||(b=='P'&&a=='R'))
                c2++;
        }
        if(c1>c2)
                printf("Player 1\n");
            else if(c1==c2)
                printf("TIE\n");
            else
                printf("Player 2\n");
    }
}
