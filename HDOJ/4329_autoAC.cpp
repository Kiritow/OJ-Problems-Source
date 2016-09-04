#include<cstdio>  
#include<cstring>  
#include<map>  
#include<string>  
#include<iostream>  
using namespace std;  
int main(){  
    int t,T,i,j,k,n;  
    int sta;  
    double sum[110],ans;  
    int all[110];  
    int ss,num;  
    string str;  
    char sss[10010];  
    map<string,int> m[100];  
    scanf("%d",&T);  
    for(t=1;t<=T;t++){  
        memset(all,0,sizeof(all));  
        memset(sum,0,sizeof(sum));  
        scanf("%d",&n);  
        for(i=0;i<n;i++){  
            scanf("%s",str);  
            getline(cin,str);  
            for(j=0;j<str.length() && str[j]==' ';j++);  
            sta=j;  
            for(;j<str.length();j++){  
                if(str[j]==' '){  
                    m[i].insert(make_pair(str.substr(sta,j-sta),1));  
                    all[i]++;  
                    for(;j<str.length() && str[j]==' ';j++);  
                    sta=j;  
                    if(sta==str.length())break;  
                    j--;  
                }  
            }  
            if(sta!=str.length()){  
                m[i].insert(make_pair(str.substr(sta,j-sta),1));  
                all[i]++;  
            }  
        }  
        for(i=0;i<n;i++){  
            scanf("%s",str);  
            getline(cin,str);  
            for(j=0;j<str.length() && str[j]==' ';j++);  
            sta=j;  
            ss=num=0;  
            for(;j<str.length();j++){  
                if(str[j]==' '){  
                    num++;  
                    if(m[i].find(str.substr(sta,j-sta))!=m[i].end()){  
                        ss++;  
                        sum[i]+=(double)ss/num;  
                    }  
                    for(;j<str.length() && str[j]==' ';j++);  
                    sta=j;  
                    if(sta==str.length())break;  
                    j--;  
                }  
            }  
            if(sta!=str.length()){  
                num++;  
                if(m[i].find(str.substr(sta,j-sta))!=m[i].end()){  
                     ss++;  
                     sum[i]+=(double)ss/num;  
                }  
            }  
            sum[i]/=all[i];  
        }  
        ans=0;  
        for(i=0;i<n;i++)  
            ans+=sum[i];  
        printf("Case #%d: %.6lf\n",t,ans/n);  
    }  
}
