#include<cstdio>
#include<cstring>
#include<cmath>
char s[1010];
char ans[1020];
int st[1010][20];
int Min(int x,int y)
{
    return s[x] <= s[y] ? x : y;
}
void RMQ_Init(int len)
{
    for(int i = 0; i < len; i++)
    st[i][0] = i;
    for(int j = 1; (1<<j) < len; j++)
    for(int i = 0; i+(1<<j)-1 < len;i++)
    st[i][j] = Min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int Query(int l,int r)
{
    int k = (int)(log((double)(r-l+1))/log(2.0));
    return Min(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    int len, m, i;
    while(scanf("%s%d",s, &m)!=EOF)
    {
        len = strlen(s);
        RMQ_Init(len);
        m = len - m;
        int pos = 0, num = 0;
        while(m--)
        {
            pos = Query(pos, len - m - 1);
            ans[num++] = s[pos++];
        }
        for(i = 0; i < num; i++)
            if(ans[i]!='0')
                break;
        if(i == num)
            printf("0");
        else
        {
            while(i < num)
                printf("%c",ans[i++]);
        }
        puts("");
    }
    return 0;
}
