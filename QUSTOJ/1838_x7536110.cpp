#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long tree[2][2][3100][3100];
int n,m;
int add(int x,int y,long long v){
  for (int i=x;i<=n;i+=i&(-i))
    for (int j=y;j<=n;j+=j&(-j))
      tree[x&1][y&1][i][j]^=v;
  return 0;
}
long long sum(int x,int y){
  long long ans=0;
  for (int i=x;i>0;i-=i&(-i))
    for (int j=y;j>0;j-=j&(-j))
      ans^=tree[x&1][y&1][i][j];
  return ans;
}
int main(){
 // freopen("in","r",stdin);
 // freopen("out","w",stdout);
  while (~scanf("%d%d",&n,&m)){
    memset(tree,0,sizeof tree);
    for (int i=1;i<=m;i++){
        char op[2];scanf("%s",op);
        int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (op[0]=='P'){
            int manyNum;scanf("%d",&manyNum);
            long long val;val=0;
 
            for (int j=0;j<manyNum;j++){
                int a,b;
 
                scanf("%d%d",&a,&b);
                if (b%2){
                    long long kkk=((long long)1)<<(a-1);
                    val=val^kkk;
                }
            }
            add(x2+1,y2+1,val);
            add(x1,y2+1,val);
            add(x2+1,y1,val);
            add(x1,y1,val);
        }
        else {
            long long ans=0;
            ans^=sum(x2,y2);
            if (x1>1) ans^=sum(x1-1,y2);
            if (y1>1) ans^=sum(x2,y1-1);
            if (x1>1&&y1>1) ans^=sum(x1-1,y1-1);
            for (int j=0;j<50;j++){
                long long kkk=((long long)1)<<j;
                if ((ans&kkk)!=0) printf("2 ");
                else printf("1 ");
            }
            printf("\n");
        }
    }
  }
  return 0;
}
