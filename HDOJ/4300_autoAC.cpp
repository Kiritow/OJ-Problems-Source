#include<iostream>
#include<cstring>
using namespace std;
char a[100001],c[100001];
int ne[100001];
int main()
{
    int T,i,j,len,nima[27],mid;
    char b[27];
    while(scanf("%d",&T)!=EOF)
    {
        getchar();
        while(T--)
        {
            scanf("%s%s",b+1,a+1);
            for(i=1;i<=26;i++)
               nima[b[i]-'a']=i-1;
            len=strlen(a+1);
            for(i=1;i<=len;i++)
                c[i]='a'+nima[a[i]-'a'];
            i=1;j=0;ne[1]=0;
            while(i<len)
            {
                if(j==0||c[i]==c[j])
                {
                    i++;j++;
                    ne[i]=j;
                }
                else
                    j=ne[j];
            }
            if(len%2==0)
                i=len/2+1;
            else
                i=len/2+2;
            j=1;mid=i;
            while(i<=len)
            {
                if(j==0||a[i]==c[j])
                {
                    i++;j++;
                }
                else
                    j=ne[j];
            }
            for(i=1;i<=len;i++)
                printf("%c",a[i]);
            for(i=j;i<j+len-2*j+2;i++)
                printf("%c",c[i]);
            printf("\n");
        }
    }
    return 0;
}
