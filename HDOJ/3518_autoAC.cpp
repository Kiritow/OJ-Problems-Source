#include<stdio.h>
#include<string.h>
#define max 11000
int wa[max],wb[max],wv[max],ws[max];
int rank[max],height[max];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++) ws[i]=0;
    for(i=0; i<n; i++) ws[x[i]=r[i]]++;
    for(i=1; i<m; i++) ws[i]+=ws[i-1];
    for(i=n-1; i>=0; i--) sa[--ws[x[i]]]=i;
    for(p=1,j=1; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) ws[i]=0;
        for(i=0; i<n; i++) ws[wv[i]]++;
        for(i=1; i<m; i++) ws[i]+=ws[i-1];
        for(i=n-1; i>=0; i--) sa[--ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return ;
}
void calheight(int *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++)rank[sa[i]]=i;
    for(i=0; i<n; height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
    return;
}
int main()
{
    char str1[max];
    int str[max];
    int sa[max];
    int mint;
    int maxt;
    while(scanf("%s",str1)!=EOF)
    {
        int len=strlen(str1);
        if(str1[0]=='#')
            break;
        for(int i=0;i<len;i++)
            str[i]=str1[i]-'a'+1;
        str[len]=0;
        da(str,sa,len+1,27);
        calheight(str,sa,len);
        int ans=0;
        for(int i=1; i<=(len+1)/2; i++)
        {
            mint=1001;
            maxt=-1;
            for(int j=1; j<=len; j++)
            {
                if(height[j]>=i)
                {
                    int tem=sa[j-1]>sa[j]?sa[j]:sa[j-1];
                    mint=mint>tem?tem:mint;
                        tem=sa[j-1]>sa[j]?sa[j-1]:sa[j];
                    maxt=maxt>tem?maxt:tem;                }
                else
                {
                    if(mint+i<=maxt)ans++;
                    mint=1001,maxt=-1;
                }
            }
            if(mint+i<=maxt)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
