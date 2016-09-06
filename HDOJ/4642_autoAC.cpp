#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int x;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&x);
        if(x)
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;
}
