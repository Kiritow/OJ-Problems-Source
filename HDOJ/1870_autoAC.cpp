#include <stdio.h>
#include <string.h>
int main()
{
    int l;
    char a[1000];
    while(gets(a))
    {
        l=strlen(a);
        int wbx=0;
        int i;
        for(i=0;i<l;i++)
        {
            if(a[i]=='(')
            {
                wbx++;
            }
            if(a[i]==')')
            {
                wbx--;
            }
            if(a[i]=='B')
            {
                break;
            }
        }
        printf("%d\n",wbx);
    }
    return 0;
}
