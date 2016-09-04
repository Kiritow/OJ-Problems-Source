#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define size 10001
#define _clr(x) memset(x,0xff,sizeof(int)*26)
#define inf 1000000000
using namespace std;
int g[26][26];
bool l[26][size];
int KM(int n);
bool HaveLetter[26];
struct loc 
{
    int a[size];
    int len;
    loc(){len = 0;}
    void add(int val)
    {
        a[len++] = val;
    }
}locate1[26],locate2[26],rem2,rem1;
void InitGraph(int n)
{
    int i,j,A;
    memset(HaveLetter,0,sizeof(HaveLetter));
    for(i=0;i<26;i++)
        locate2[i].len = 0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            g[i][j] = 0;
        }
    }
    for (i=0;i<rem2.len;i++)
    {
        A = rem2.a[i];
        memset(l[A],0,sizeof(l[A]));
    }
}
void GreateGraph()
{
    int i,j,k,A,B,locate;
    int count[26];
    for (i=0;i<rem1.len;i++)
    {
        A = rem1.a[i];
        memset(count,0,sizeof(count));
        for (j=0;j<locate1[A].len;j++)
        {
            locate = locate1[A].a[j];
            for (k=0;k<rem2.len;k++)
            {
                B = rem2.a[k];
                if(l[B][locate])
                {
                    count[B]++;
                    g[i][k] = count[B];
                }
            }
        }
    }
}
int main()
{
    int T,n,k,m,i,letter;
    char ch[2];
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&k,&m);
        memset(HaveLetter,0,sizeof(HaveLetter));
        rem1.len = 0;
        for(i=0;i<26;i++)
            locate1[i].len = 0;
        for(i=0;i<n;i++)
        {
            scanf("%s",ch);
            letter = ch[0]-'A';
            if(!HaveLetter[letter])
                rem1.add(letter),HaveLetter[letter] = 1;
            locate1[letter].add(i);
        }
        sort(rem1.a,rem1.a+rem1.len);
        while (m--)
        {
            InitGraph(k);
            rem2.len=0;
            for (i=0;i<n;i++)
            {
                scanf("%s",ch);
                letter = ch[0]-'A';
                if(!HaveLetter[letter])
                    rem2.add(letter),HaveLetter[letter] = 1;
                locate2[letter].add(i);
                l[letter][i] = 1;
            }
            sort(rem2.a,rem2.a+rem2.len);
            GreateGraph();
            printf("%.4lf\n",KM(k)*1.0/n);
        }
    }
    return 0;
}
int KM(int n)
{
    int s[26],t[26],l1[26],l2[26],p,q,ret=0,i,j,k;
    int match1[26],match2[26];
    for (i=0;i<n;i++)
        for (l1[i]=-inf,j=0;j<n;j++)
            l1[i]=g[i][j]>l1[i]?g[i][j]:l1[i];
        for (i=0;i<n;l2[i++]=0);
        for (_clr(match1),_clr(match2),i=0;i<n;i++)
        {
            for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
                for (k=s[p],j=0;j<n&&match1[i]<0;j++)
                    if (l1[k]+l2[j]==g[k][j]&&t[j]<0)
                    {
                        s[++q]=match2[j],t[j]=k;
                        if (s[q]<0)
                            for (p=j;p>=0;j=p)
                                match2[j]=k=t[j],p=match1[k],match1[k]=j;
                    }
                    if (match1[i]<0)
                    {
                        for (i--,p=inf,k=0;k<=q;k++)
                            for (j=0;j<n;j++)
                                if (t[j]<0&&l1[s[k]]+l2[j]-g[s[k]][j]<p)
                                    p=l1[s[k]]+l2[j]-g[s[k]][j];
                                for (j=0;j<n;l2[j]+=t[j]<0?0:p,j++);
                                for (k=0;k<=q;l1[s[k++]]-=p);
                    }
        }
        for (i=0;i<n;i++)
            ret+=g[i][match1[i]];
        return ret;
}
