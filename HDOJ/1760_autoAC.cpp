#include<map>
#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;
map<string,int>sg;
map<string,bool>is;
int n,m;
bool judge(string str,int i,int j)
{
    if(str[i * m + j] == '1' || str[i * m + j + 1] == '1' || str[i * m + m + j] == '1' || str[i * m + m + j + 1] == '1')
        return false;
    return true;
}
void input(string &str,int i,int j)
{
    str[i * m + j]=str[i * m + j + 1]=str[i * m + m + j] = str[i * m + m + j + 1] = '1';
}
int DFS(string str)
{
    if(is[str])
    return sg[str];
    for(int i = 0;i < n - 1;i++)
    {
        for(int j = 0;j < m - 1;j++)
        {
            if(judge(str,i,j))
            {
                string temp = str;
                input(temp,i,j);
                if(DFS(temp) == 0)
                {
                    is[str] = 1;
                    sg[str] = 1;
                    return 1;
                }
            }
        }
    }
    is[str] = 1;
    sg[str] = 0;
    return 0;
}
int main()
{
    string str;
    string temp;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        str="";
        sg.clear();
        is.clear();
        for(int i = 0;i < n;i++)
        {
            cin >> temp;
            str += temp;
        }
        if(DFS(str))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return   0;
}
