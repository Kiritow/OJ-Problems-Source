#include<stdio.h>
#include<string.h>
#define N 2010
#define K 510
char mol[K][N],den[K][N];
char virt[N];
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int divide(char *str,int n,char *s)
{
    int i,k,len;
    len=strlen(str);
    s[len]=0;
    for(k=0,i=len-1;i>=0;i--)
    {
        k=k*10+str[i]-'0';
        s[i]=k/n+'0';
        k%=n;
    }
    for(i=len-1;i>0;i--)
    {
        if(s[i]!='0')
            break;
        s[i]=0;
    }
    return k;
}
void mult(char *str,int n,char *x)
{
    int i,s[N];
    for(i=0;i<N;i++)
        s[i]=0;
    for(i=0;str[i];i++)
        s[i]=(str[i]-'0')*n;
    for(i=0;i<N-1;i++)
    {
        s[i+1]+=s[i]/10;
        s[i]%=10;
    }
    for(i=N-1;i>0 && s[i]==0;i--);
    x[i+1]=0;
    for(;i>=0;i--)x[i]=s[i]+'0';
}
void init()
{
    int i,j,k;
    strcpy(mol[1],"1");
    strcpy(den[1],"2");
    for(i=2;i<K;i++)
    {
        j=2*i;
        k=gcd(j,divide(mol[i-1],j,virt));
        divide(mol[i-1],k,mol[i]);
        mult(den[i-1],j/k,den[i]);
        j--;
        k=gcd(j,divide(den[i],j,virt));
        if(k>1)
            divide(den[i],k,den[i]);
        mult(mol[i],j/k,mol[i]);
        strrev(mol[i-1]);
        strrev(den[i-1]);
    }
}
int main()
{
    int n,T;
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%s/%s\n",mol[n],den[n]);
    }
    return 0;
}
