#include<stdio.h>
#include<string.h>
__int64 a1[26],f[55],a2[26];
char s1[55],s2[55];
int main()
{
    int k,n,i,t,j;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        char ch='a';
        int p=1;
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        scanf("%s%s%d",s1,s2,&k);
        for(i=0;i<strlen(s1);i++)
        {
            int d=s1[i]-'a';
            a1[d]++;
        }
        for(i=0;i<strlen(s2);i++)
        {
            int d=s2[i]-'a';
            a2[d]++;
        }
        for(i=0;i<26;i++)
        {
            f[0]=a1[i];
            f[1]=a2[i];
            for(j=2;j<=k;j++) f[j]=f[j-2]+f[j-1];
            a1[i]=f[k];
        }
        for(i=0;i<26;i++) printf("%c:%I64d\n",ch+i,a1[i]);
        printf("\n");
    }
    return 0;
}
