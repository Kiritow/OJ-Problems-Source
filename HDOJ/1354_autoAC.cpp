#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
typedef struct
{
    int next1,next2;
    char type;
    string text;
    string end;
}Page;
Page page[101];
int mark[101];
int path[101];
void init()
{
    for(int i = 0;i < 101; i++)
    {
        page[i].end = "";
        page[i].text = "";
        page[i].next1 = 0;
        page[i].next2 = 0;
        mark[i] = 0;
        path[i] = 0;
    }
}
bool dfs(int p,int k)
{
    if(mark[p]==1)
    return false;
    path[k] = p;
    mark[p] = 1;
    if(page[p].type=='E'&&page[p].end.compare("HAPPY")==0)
    return true;
    if(page[p].type == 'C')
    {
        if(dfs(page[p].next1,k+1))
        return true;
        if(dfs(page[p].next2,k+1))
        return true;
    }
    path[k] = 0;
    mark[p] = 0;
    return false;
}
void print()
{
    int i = 1;
    while(path[i]!=0)
    {
        cout<<page[path[i]].text<<endl;
        i++;
    }
}
int main()
{
     int n;
     int x;
     int page1,page2;
     string text,end;
     string line;
    cin>>n;
    for(int m = 1; m <= n; m++)
    {
        cin>>x;
         getchar();
         init();
        for(int i = 1; i <= x; i++)
        {
            getline(cin,line);
            if(line[0] == 'C')
            {
                page1 = atoi(line.substr(line.find_last_of("\"")+2,1).c_str());
                page2 = atoi(line.substr(line.find_last_of("\"")+4,1).c_str());
                text = line.substr(line.find_first_of("\"")+1,line.find_last_of("\"")-line.find_first_of("\"")-1);
                page[i].next1 = page1;
                page[i].next2 = page2;
                page[i].text = text;
                page[i].type = 'C';
            }else if(line[0] == 'E')
            {
                text = line.substr(line.find_first_of("\"")+1,line.find_last_of("\"")-line.find_first_of("\"")-1);
                end = line.substr(line.find_last_of("\"")+2,line.length()-line.find_last_of("\""));
                page[i].end = end;
                page[i].text = text;
                page[i].type = 'E';
            }
            line = "";
            cin.clear();
        }
        mark[1] = 1;
        path[1] = 1;
        cout<<"STORY "<<m<<endl;
        if(dfs(page[1].next1,2))
        print();
        else
        {
            if(dfs(page[1].next2,2))
            print();
        }
    }
    return 0;
}
