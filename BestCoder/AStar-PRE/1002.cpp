#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
inline void bzero(void* ptr,size_t size)
{
    memset(ptr,0,size);
}
char msg[102400];
char ans[102400];
int cnt=0;

int main()
{
    int key;
    int turn;
    scanf("%d%*c",&turn);
    for(int tt=0;tt<turn;tt++)
    {
        bzero(msg,102400);
        bzero(ans,102400);
        cnt=0;
        gets(msg);
        scanf("%d%*c",&key);
        int len=strlen(msg);
        int LL=len%key;
        int L=len/key;
        for(int i=0;i<L;i++)
        {
            for(int j=0;j<key;j++)
            {
                int v;
                if(j<LL)
                {
                    v=j*(L+1)+i;
                }
                else
                {
                    v=(L+1)*LL+(j-LL)*L+i;
                }
                ans[cnt]=msg[v];
                cnt++;
            }
        }
        /// "L" th Line. (i==L)
        for(int j=0;j<LL;j++)
        {
            int v=(j+1)*(L+1)-1;
            ans[cnt]=msg[v];
            cnt++;
        }
        printf("Case #%d:\n%s\n",tt+1,ans);
    }
    return 0;
}
