#include <stdio.h>

int main()
{

    int g,m,c;
    for(g=0;g<21;++g)
        for(m=0;m<35;m++)
            for(c=0;c<100;c+=3)
                if(g*5+m*3+c/3==100&&g+m+c==100)
                    printf("%d\t%d\t%d\n",g,m,c);
    return 0;
}
