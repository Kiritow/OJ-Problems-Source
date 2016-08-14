#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=101;
char m[maxn][2*maxn];
int n;
bool judge(int h,int left,int right)
{
    if(right>2*n-h||left<h)
        return false;
    for(int i=left;i<=right;++i)
        if(m[h][i]!='-')
            return false;
    return true;
}
int up(int h,int l)          
{
    int result=0;
    for(int i=h;i>=1;--i)
        if(judge(i,l-(h-i),l+(h-i)))
            result+=2*(h-i)+1;
        else
            break;
    return result;
}
int down(int h,int l)                
{
    int result=0;
    for(int i=h;i<=n;++i)
        if(judge(i,l-(i-h),l+(i-h)))
            result+=2*(i-h)+1;
        else
            break;
    return result;
}
int dfs()
{
    int maxarea=0;
    for(int i=1;i<=n;++i)
        for(int j=i;j<=2*n-i;++j)
        {
            if(m[i][j]=='#')
                continue;
            if((i+j)%2==1)        
                maxarea=max(maxarea,down(i,j));
            else                   
                maxarea=max(maxarea,up(i,j));
        }
    return maxarea;
}
int main()
{
    static int num=0;
    while(cin>>n&&n)
    {
        getchar();
        for(int i=1;i<=n;++i)
            gets(m[i]+1);
        cout<<"Triangle #"<<++num<<endl;
        cout<<"The largest triangle area is "<<dfs()<<"."<<endl<<endl; 
    }
    return 0;
}
