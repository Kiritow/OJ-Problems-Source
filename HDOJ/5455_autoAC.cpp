#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#define LL long long
#define MAXN 100010
using namespace std;
string s1;
int len,k,fg,cnt,ans,fg2;
int main(){
    int T,cas,i;
    scanf("%d",&T);
    getchar();
    for(cas=1;cas<=T;cas++)
    {
        char s2[MAXN];
        getline(cin,s1);
        len=s1.length();
        fg=0;
        for(i=0;i<len;i++)
        {
            if(s1[i]=='c')
            {
                fg=1;
                k=i;
                break;
            }
        }
        if(fg)
        {
            cnt=0;
            for(i=k;i<len;i++)
            {
                s2[cnt++]=s1[i];
            }
            for(i=0;i<k;i++)
            {
                s2[cnt++]=s1[i];
            }
        }
        else
        {
            ans=(len+1)/2;
            printf("Case #%d: %d\n",cas,ans);
            continue;
        }
        ans=1;
        fg2=1;
        int shuf=0;
        for(i=1;i<len;i++)
        {
            if(s2[i]=='f')
            {
                shuf++;
            }
            else
            {
                if(s2[i]=='c')
                {
                    if(shuf<2)
                    {
                        printf("Case #%d: -1\n",cas);
                        break;
                    }
                    else
                    {
                        ans++;
                        shuf=0;
                    }
                }
                else
                {
                    printf("Case #%d: -1\n",cas);
                    break;
                }
            }
        }
        if(i==len&&shuf<2)
        {
            printf("Case #%d: -1\n",cas);
            continue;
        }
        if(i==len)
        {
            printf("Case #%d: %d\n",cas,ans);
        }
    }
    return 0;
}
