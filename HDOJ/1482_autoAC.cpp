#include<stdio.h>
#include<string.h>
int main()
{
    char str[9][20];
    int a[12];
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<9;i++)scanf("%s",&str[i]);
        int res=-1;
        while(res<12)
        {
            int t;
            if(res==-1){res=0;t=1;}
            else if(a[res]==1)  t=-1;
            else  {res++;t=1;}
            for(int i=0;i<12;i++) a[i]=0;
            a[res]=t;
            int L=0,R=0;
            int len=strlen(str[0]);
            for(int i=0;i<len;i++) L+=a[str[0][i]-'A'];
            len=strlen(str[1]);
            for(int i=0;i<len;i++) R+=a[str[1][i]-'A'];
            if(strcmp(str[2],"even")==0)
            {
                if(L!=R)continue;
            }    
            if(strcmp(str[2],"up")==0)
               if(L<=R)continue;
            if(strcmp(str[2],"down")==0)
               if(L>=R)continue;
            L=0,R=0;
            len=strlen(str[3]);
            for(int i=0;i<len;i++) L+=a[str[3][i]-'A'];
            len=strlen(str[4]);
            for(int i=0;i<len;i++) R+=a[str[4][i]-'A'];
            if(strcmp(str[5],"even")==0)
            {
                if(L!=R)continue;
            }    
            if(strcmp(str[5],"up")==0)
               if(L<=R)continue;
            if(strcmp(str[5],"down")==0)
               if(L>=R)continue;
            L=0,R=0;
            len=strlen(str[6]);
            for(int i=0;i<len;i++) L+=a[str[6][i]-'A'];
            len=strlen(str[7]);
            for(int i=0;i<len;i++) R+=a[str[7][i]-'A'];
            if(strcmp(str[8],"even")==0)
            {
                if(L!=R)continue;
            }    
            if(strcmp(str[8],"up")==0)
               if(L<=R)continue;
            if(strcmp(str[8],"down")==0)
               if(L>=R)continue;
            break;
        }    
        printf("%c is the counterfeit coin and it is ",res+'A');
        if(a[res]==-1) printf("light.\n");
        else printf("heavy.\n");
    }    
    return 0;
}
