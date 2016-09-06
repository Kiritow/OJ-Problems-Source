#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool mark[1000010];
int num[1000010];
int k;
int Judge(int n){
    int ans=0;
    while(n){
        ans+=n%10;
        n/=10;
    }
    return ans;
}
void IsPrime(){
    memset(mark,true,sizeof(mark));
    mark[0]=mark[1]=false;
    k=0;
    for(int i=2;i*i<1000000;i++){
        if(mark[i]){
            for(int j=i*i;j<1000000;j+=i)
                mark[j]=false;
        }
    }
    for(int i=2;i<=1000010;i++){
        if(mark[i]&&mark[Judge(i)]){
            num[++k]=i;
        }
    }
}
int Binary_Search(int l,int h,int number){
    while(l<=h){
        int mid=(l+h)/2;
        if(num[mid]==number)return mid;
        else if(num[mid]>number)h=mid-1;
        else l=mid+1;
    }
    return l;
}
int main(){
    IsPrime();
    int _case,n,m,t=1;
    scanf("%d",&_case);
    while(_case--){
        scanf("%d%d",&n,&m);
        int cnt=0;
        int pos1=Binary_Search(1,k,n);
        int pos2=Binary_Search(1,k,m);
        pos1--;
        if(num[pos2]==m)pos2++;
        cnt=pos2-pos1-1;
        printf("Case #%d: %d\n",t++,cnt);
    }
    return 0;
}
