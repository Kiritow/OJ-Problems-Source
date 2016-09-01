#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct node {
    int r;
    int d;
    bool ok;
} a[111][111];
int b[111][111];
int n,m;
int num(int x) {
    if(x==0)return 1;
    int ans=0;
    while(x)
        ans++,x/=10;
    return 3-ans;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        char c;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                scanf(" %c",&c);
                if(c=='_') {
                    a[i][j].ok=1;
                } else {
                    b[i][j]=c-'0';
                }
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(a[i][j].ok) {
                    for(int k=j+1; k<=m; k++) {
                        if(a[i][k].ok)break;
                        a[i][j].r+=b[i][k];
                    }
                    for(int k=i+1; k<=n; k++) {
                        if(a[k][j].ok)break;
                        a[i][j].d+=b[k][j];
                    }
                }
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(a[i][j].ok) {
                    if(a[i][j].d) {
                        int h=num(a[i][j].d);
                        for(int i=0; i<h; i++)
                            printf("0");
                        printf("%d",a[i][j].d);
                    } else
                        printf("XXX");
                    if(a[i][j].r==0&&a[i][j].d==0) {
                        printf("XXXX");
                    } else if(a[i][j].d&&a[i][j].r==0)
                        printf("\\XXX");
                    else{
                              printf("\\");
                        int h=num(a[i][j].r);
                        for(int i=0; i<h; i++)
                            printf("0");
                        printf("%d",a[i][j].r);
                    }
                } else if(b[i][j])
                    printf(".......");
                if(j!=m)printf(" ");
                else    printf("\n");
            }
        }
          printf("\n");
    }
    return 0;
}
