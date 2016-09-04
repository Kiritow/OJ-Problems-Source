#include<iostream>
#include<string>
using namespace std;
int t;
string a,b;
int main()
{
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cin>>a>>b;
        int len=a.length();
        cout<<"Case #"<<cas<<": ";
        if(len>2){
            int n=0,m=0;
            for(int i=0;i<len;i++){
                n+=a[i];
                m+=b[i];
            }
            if((n&1)==(m&1)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            if(((a[0]-b[0]+26)%26)==((a[1]-b[1]+26)%26)&&(a[0]-b[0])%2==0||((a[0]-b[1]+26)%26)==((a[1]-b[0]+26)%26)&&(a[1]-b[0]+1)%2==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}
