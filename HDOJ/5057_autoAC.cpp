#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int maxn=100005;
int n,m;
int digit[maxn][10];
int block[400][10][10];
int X,Y,L,R,D,P;
int main()
{
    int x;
    char str[10];
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        memset(block,0,sizeof(block));
        for(int i=1;i<=n;i++) {
            scanf("%d",&x);
            int b=(i>>8);
            for(int j=1;j<=10;j++) {
                digit[i][j]=x%10;
                block[b][j][x%10]++;
                x/=10;
            }
        }
        for(int i=0;i<m;i++) {
            scanf("%s",str);
            if(str[0]=='S') {
                scanf("%d%d",&X,&Y);
                int b=(X>>8);
                for(int j=1;j<=10;j++) {
                    block[b][j][digit[X][j]]--;
                    digit[X][j]=Y%10;
                    block[b][j][Y%10]++;
                    Y/=10;
                }
            }
            else {
                scanf("%d%d%d%d",&L,&R,&D,&P);
                int bl=((L-1)>>8)+1,br=((R+1)>>8)-1;
                int ans=0;
                if(bl<=br) {
                    for(int i=bl;i<=br;i++)
                        ans+=block[i][D][P];
                    for(int i=L;i<(bl<<8);i++)
                        ans+=(digit[i][D]==P);
                    for(int i=((br+1)<<8);i<=R;i++)
                        ans+=(digit[i][D]==P);
                }
                else {
                    for(int i=L;i<=R;i++) {
                        ans+=(digit[i][D]==P);
                    }
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
