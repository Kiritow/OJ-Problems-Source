#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
long long a,b,n;
vector<long long> vt;
long long solve(long long x,long long n){
    vt.clear();
    long long i,j;
    for(i=2;i*i<=n;i++)     
        if(n%i==0){
            vt.push_back(i);
            while(n%i==0)
                n/=i;
        }
    if(n>1)
        vt.push_back(n);
    long long sum=0,val,cnt;
    for(i=1;i<(1<<vt.size());i++){  
        val=1;
        cnt=0;
        for(j=0;j<vt.size();j++)
            if(i&(1<<j)){       
                val*=vt[j];
                cnt++;
            }
        if(cnt&1)     
            sum+=x/val;
        else
            sum-=x/val;
    }
    return x-sum;
}
int main(){
    int t,cases=0;
    scanf("%d",&t);
    while(t--){
        cin>>a>>b>>n;
        cout<<"Case #"<<++cases<<": "<<solve(b,n)-solve(a-1,n)<<endl;
    }
    return 0;
}
