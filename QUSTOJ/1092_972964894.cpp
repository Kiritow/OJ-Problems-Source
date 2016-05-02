#include<iostream>
#include<algorithm>
using namespace std;
struct leaf{
    long long x,y,z;
}a[50000];
long long n,k,w[10],i;

bool cmp(leaf a,leaf b){
    return (a.x>b.x) || (a.x==b.x && a.z<b.z);
}

int main(){
    cin>>n>>k;
    for (i=0;i<10;i++) cin>>w[i];
    for (i=0;i<n;i++){
        cin>>a[i].x;
        a[i].z=i+1;
    }
    sort(a,a+n,cmp);
    for (i=0;i<n;i++){
        a[i].y=i;
        a[i].x+=w[a[i].y%10];
    }
    sort(a,a+n,cmp);
    for (i=0;i<k;i++){
        cout<<a[i].z;
        if (i+1==k) cout<<endl;
        else cout<<' ';
    }
    return 0;
}
