#include<iostream>
#include<cstring>
#include<string>
#define maxn 300
using namespace std;
int numx[maxn],numy[maxn],n;
string str,tmp;
string Add(string x,string y){
    string res="";
    memset(numx,0,sizeof(numx));
    memset(numy,0,sizeof(numy));
    int lenx=x.size(),leny=y.size();
    int maxlen=lenx>leny ? lenx:leny;
    for(int i=0;i<lenx;i++)numx[lenx-i-1]=x[i]-'0';
    for(int i=0;i<leny;i++)numy[leny-i-1]=y[i]-'0';
    for(int i=0;i<=maxlen;i++){
        numx[i]+=numy[i];
        if(numx[i]>9){
            numx[i+1]+=numx[i]/10;
            numx[i]%=10;
        }
    }
    int i=maxlen+2;
    for(;i>0&&!numx[i];)i--;
    for(;i>=0;i--)res+=numx[i]+'0';
    return res;
}
int main()
{
    while(cin>>n){
        while(n--){
                string sum="0";
            while(cin>>str&&str!="0"){
                sum=Add(sum,str);
            }
            cout<<sum<<endl;
            if(n)cout<<endl;
        }
    }
    return 0;
}
