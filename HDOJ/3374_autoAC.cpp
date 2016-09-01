# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# define N  1000005
char s1[2*N],s2[2*N],s[N],ch1[N],ch2[N];; 
int next[N];
void Gnext(char str[])
{
    int i,j,len=strlen(str); 
    next[0]=0;
    j=0; 
    for(i=1;i<len;i++)
    {
        while(j>0 && str[j]!=str[i]) j=next[j-1];
        if(str[i]==str[j]) j++;
        next[i]=j; 
    } 
} 
int KMP(char *a,char *b)
{
    int i,j,lena,lenb,count;
    j=0;
    lena=strlen(a);
    lenb=strlen(b);
    count=0; 
    for(i=0;i<lenb;i++)
    {
        while(j>0 && a[j]!=b[i]) j=next[j-1];
        if(a[j]==b[i]) j++;
        if(j==lena) {j=next[j-1];count++;} 
    }  
    return count; 
} 
int main()
{
    int i,j,len1,len2,len,k,minnum,maxnum,count1,count2;
    while(scanf("%s",s)!=EOF)
    {
        len=strlen(s);
        strcpy(s1,s);
        strcat(s1,s);
        strcpy(s2,s1);
        i=0;j=1;
        while(i<=len && j<=len)
        {
            for(k=0;k<len;k++)
            if(s1[i+k]!=s2[j+k]) break;
            if(k==len) break;
            if(s1[i+k]>s2[j+k]) i=i+k+1;
            else j=j+k+1;
            if(i==j) j++;
        }
        if(j<i) i=j; 
        minnum=i+1;
        for(j=0;j<len;j++)
        ch1[j]=s1[i+j];
        ch1[j]=0;
        i=0;j=1;
        while(i<=len && j<=len)
        {
            for(k=0;k<len;k++)
            if(s1[i+k]!=s2[j+k]) break;
            if(k==len) break;
            if(s1[i+k]<s2[j+k]) i=i+k+1;
            else j=j+k+1;
            if(i==j) j++;
        }
        if(j<i) j=i;
        maxnum=i+1;
        for(j=0;j<len;j++)
        ch2[j]=s1[i+j];
        ch2[j]=0;       
        Gnext(ch1); 
        count1=KMP(ch1,s1); 
        if(minnum==1) count1--; 
        Gnext(ch2);
        count2=KMP(ch2,s1);
        if(maxnum==1) count2--; 
        printf("%d %d %d %d\n",minnum,count1,maxnum,count2); 
    }
    return 0;
}
