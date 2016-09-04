#include<iostream>  
#include<vector>  
#include<algorithm>  
#include<cstdio>  
#include<string>  
#include<map>  
#include<set>  
#include<cstring>  
using namespace std;  
map<int,set<int> > m;  
map<int,set<int> >::iterator mi;  
set<int>::iterator si;  
set<int>s;  
map<int,int>yy;  
int n;  
int tx,ty;  
char c[11];  
int temp,t2;  
int tt;  
int main()  
{  
    int cas=1;  
    while(cin>>n)  
    {  
        if(n==0)  
        {  
            break;  
        }  
        if(cas!=1)  
        {  
            cout<<endl;  
        }  
        printf("Case %d:\n",cas++);  
        m.clear();  
        s.clear();  
        yy.clear();  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%s",c);  
            scanf("%d%d",&tx,&ty);  
            if(c[0]=='a')  
            {  
                if(yy.find(ty) == yy.end())  
                {  
                    yy[ty] = 1;  
                }  
                else  
                {  
                    yy[ty]++;  
                }  
                if(s.find(tx)==s.end())  
                {  
                    s.insert(tx);  
                }  
                mi = m.find(tx);  
                if(mi != m.end())  
                {  
                    si = mi -> second.find(ty);  
                    if(si!=mi -> second.end())  
                    {  
                        continue;  
                    }  
                    else  
                    {  
                        mi->second.insert(ty);  
                    }  
                }  
                else  
                {  
                    m[tx].insert(ty);  
                }  
            }  
            else if(c[0]=='f')  
            {  
                if(yy.upper_bound(ty) == yy.end())  
                {  
                    printf("-1\n");  
                    continue;  
                }  
                tt = tx;  
                while(true)  
                {  
                    if(s.empty())  
                    {  
                        printf("-1\n");  
                        break;  
                    }  
                    si = s.upper_bound(tt);  
                    if(si!=s.end())  
                    {  
                        temp = *si;  
                        tt = temp;  
                        if(m[temp].empty())  
                        {  
                            continue;  
                        }  
                        si = m[temp].upper_bound(ty);  
                        if(si != m[temp].end())  
                        {  
                            t2 = *si;  
                            printf("%d %d\n",temp,t2);  
                            break;  
                        }  
                        else  
                        {  
                            continue;  
                        }  
                    }  
                    else  
                    {  
                        printf("-1\n");  
                        break;  
                    }  
                }  
            }  
            else if(c[0]=='r')  
            {  
                m[tx].erase(ty);  
                if(m[tx].empty())  
                {  
                    s.erase(tx);  
                }  
                if(!--yy[ty])  
                {  
                    yy.erase(ty);  
                }  
            }  
        }  
    }  
    return 0;  
}
