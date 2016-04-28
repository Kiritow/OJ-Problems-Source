#include <stdio.h>
int main()
{
    int all,maxl,maxh;
    int square,box;
    int l,h;
    scanf("%d",&all);
    for(;all>0;all--)
    {
        square=0;box=0;
        scanf("%d %d",&maxl,&maxh);
        for(l=1;l<=maxl;l++)
        {
            for(h=1;h<=maxh;h++)
            {
                if(l==h)
                {
                    square+=(maxl-l+1)*(maxh-h+1);
                }
                else
                {
                    box+=(maxl-l+1)*(maxh-h+1);
                }
            }
        }
        printf("%d %d\n",square,box);
    }
    return 0;
}
