#include <stdio.h>
#include <string.h>
int main()
{
    char inf[50],ans[5];
    int t,n,cnt,cas = 0,f,i,j,y[5];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(y,0,sizeof(y));
        gets(inf);
        for(j = 0; j < n; ++j)
        {
            cnt = f = 0;
            gets(inf);
            for(i = 0; inf[i] != ' ' && inf[i]; ++i);
            for(; inf[i]; ++i){
                if(inf[i-1] == ' ' && inf[i] == 'y'){
                    if(cnt == 0)
                        ++y[1];
                    else
                        ++y[2];
                    ++cnt;
                    f = 1;
                }
                else if(inf[i-1] ==' ' && inf[i] =='n'){
                    ++cnt;
                }
            }
            if(cnt == 0)
                ++y[4];
            else if(!f)
                ++y[3];
        }
        printf("Roll-call: %d\n",++cas);
        printf("Present: %d out of %d\n",y[1],n);
        printf("Needs to study at home: %d out of %d\n",y[2],n);
        printf("Needs remedial work after school: %d out of %d\n",y[3],n);
        printf("Absent: %d out of %d\n",y[4],n);
    }
    return 0;
}
