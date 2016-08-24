#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=600010;
int sa[maxn],Rank[maxn];
char s[maxn];
int N;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&sa[i]);
            Rank[sa[i]]=i;
        }
        Rank[N+1]=-1;
        int k=0;
        s[sa[1]]=k+'a';
        for(int i=2;i<=N;i++)
        {
            int x=sa[i-1],y=sa[i];
            if(Rank[x+1]>Rank[y+1])k++;
            s[sa[i]]=k+'a';
        }
        if(k>=26)printf("-1\n");
        else
        {
            s[N+1]=0;
            printf("%s\n",s+1);
        }
    }
    return 0;
}
