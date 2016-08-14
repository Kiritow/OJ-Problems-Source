#include <cstdio>  
#include <cstring>  
#define MAX(x,y) x>y?x:y  
#define MIN(x,y) x<y?x:y  
int max, min, flag, ff;  
bool f[101];  
int dfs(int t)  
{  
    if(t==1)  
    {  
        if(flag==0)  
        {  
            ff = 1; flag = 1;  
            if(dfs(max)) return 1;  
            else {flag = 0; return 0;}  
        }  
        return 1;  
    }  
    int len = 100<t?100:t;  
    for(int i = 2; i <= len; i++)  
    if(t%i==0&&f[i]==0)  
    {  
        f[i] = 1; if(dfs(t/i)) return 1;  
        f[i] = 0;  
    }  
    return 0;  
}  
int main ()  
{  
    int a, b;  
    while(~scanf("%d%d",&a,&b))  
    {  
        flag = 0;ff = 0;  
        int ans;  
        max = MAX(a,b);  
        min = MIN(a,b);  
        memset(f,0,sizeof(f));  
        int tt = dfs(min);  
        if(ff==0) ans = max;  
        else if(ff==1&&tt==1) ans = max;  
        else ans = min;  
        printf("%d\n",ans);  
    }  
    return 0;  
}
