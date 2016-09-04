#include<iostream>
#include<algorithm>
using namespace std;
int a[500005];
int l,n,m;
int solve(int step){
    int s=0,count=0,i=0;
    while(s<l){
        s+=step;
        while(a[i]<=s)
            i++;
        s=a[i-1];
        count++;
    }
    return count;
}
int binary_search(int low,int high){
    int left=low,right=high,mid;
    while(left<right){
        mid=(left+right)/2;
        if(solve(mid)<=m){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    return left;
}
int main(){
    while(cin>>l>>n>>m){
        int ans,i;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        a[n]=l; a[n+1]=l*2;
        ans=a[0];
        for(i=1;i<=n;i++)
            if(a[i]-a[i-1]>ans)
                ans=a[i]-a[i-1];
        ans=binary_search(ans,l);
        cout<<ans<<endl;
    }
    return 0;
}
