#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[100];
void solve(int n){
    while(n>=10){
        a[n%10]++;
        n/=10;
    }
    a[n]++;
}
int main()
{
    int T;
    cin>>T;
    getchar();
    while(T--){
            memset(a,0,sizeof(a));
            char name[600];int n;char tmp[60];char temp[100];
            gets(name);
            cin>>n>>tmp;
            getchar();
            int i=0;
            while(i<n){
                    gets(temp);
                    if(temp[0]=='+'){
                        int u,v,c;
                        char t;
                        sscanf(temp,"%c%d%d%d",&t,&u,&v,&c);
                        i+=(v-u)/c+1;
                        while(u<=v){
                                solve(u);
                                u+=c;
                        }
                    }
                    else{
                        i++;
                        int u;
                        sscanf(temp,"%d",&u);
                        solve(u);
                    }
            }
            cout<<name<<endl;
            cout<<n<<" "<<tmp<<endl;
            int tot=0;
            for(i=0;i<=9;i++){
                    tot+=a[i];
                    cout<<"Make "<<a[i]<<" digit "<<i<<endl;
            }
            if(tot==1){
                    cout<<"In total 1 digit"<<endl;
            }
            else
                printf("In total %d digits\n",tot);
    }
    return 0;
}
