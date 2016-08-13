#include <stdio.h>
int main()
{
    double in;
    int out,count = 1;
    while(scanf("%lf",&in)!=EOF,in!=0)
    {
        in *= 0.75; 
        in /= (1.86*1000000);
        out = (int)in;
        if(in - out != 0)
        {
            out++;
        }
        printf("File #%d\nJohn needs %d floppies.\n\n",count++,out);
    }
    return 0;
}
