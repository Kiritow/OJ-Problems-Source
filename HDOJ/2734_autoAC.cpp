#include <stdio.h>
#include <string.h>
int main()
{
    char a[300];
    int i;
    int b[300];
    while(gets(a) &&a[0]!='#')
    {
        memset(b,0,sizeof(b));
        int l=strlen(a);
        for(i=0;i<l;i++)
        {
            if(a[i]!=' ')
                b[i]=a[i]-'A'+1;
            else
                b[i]=0;
        }
        int sum=0;
        for(i=0;i<l;i++)
            sum+=b[i]*(i+1); 
        printf("%d\n",sum);
    }
    return 0;
}
