#include <cstdio>
#include <cstring>
//#define LOCAL
using namespace std;

const int MAXN=205;

char a[MAXN],b[MAXN],all[2*MAXN-5];
int lenA,lenB,lenAll;

bool DFS(int posA,int posB,int posAll) {
    if(posA==lenA&&posB==lenB)
        return true;
    if(posA<lenA&&a[posA]==all[posAll]&&DFS(posA+1,posB,posAll+1))
        return true;
    if(posB<lenB&&b[posB]==all[posAll]&&DFS(posA,posB+1,posAll+1))
        return true;
    return false;
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
    int T,cnt=0;
    scanf("%d",&T);
    while(T--) {
        printf("Data set %d: ",++cnt);
        scanf("%s%s%s",a,b,all);
        lenA=strlen(a);
        lenB=strlen(b);
        lenAll=strlen(all);
        if((all[0]!=a[0]&&all[0]!=b[0])||(all[lenAll-1]!=a[lenA-1]&&all[lenAll-1]!=b[lenB-1])) {//剪枝，不加上就会TLE
            printf("no\n");
            continue;
        }
        printf("%s\n",DFS(0,0,0)?"yes":"no");
    }
    return 0;
}
