#include<iostream>
#include<map>
#include<queue>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
struct Editor{
    int ID;    
    int Num;
};
vector<int>data[10000];    
map<string,int> name;    
map<string,int>::iterator pos;
int author[10000];        
string Erdos = "Erdos,P.";
void bfs()    
{
    queue<Editor>Q;
    Editor tmp,now;
    int i,id,nNum;
    memset(author,-1,sizeof(author));
    tmp.ID = name[Erdos];
    tmp.Num = 0;
    Q.push(tmp);
    while(!Q.empty())
    {
        now = Q.front();    Q.pop();
        id = now.ID;
        nNum = data[id].size();
        for(i=0;i<nNum;i++)
        {
            if(author[data[id][i]] == -1)
            {
                author[data[id][i]] = now.Num + 1;    
                tmp.ID = data[id][i];
                tmp.Num = now.Num + 1;
                Q.push(tmp);    
            }
        }
    }
}
int main()
{
    char str[300];
    string fullname;
    int p,n,len,numAuthor,numPaper,i,j,title;
    int paper[300],iCase = 0;
    while(scanf("%d%d",&p,&n)!=EOF && p+n)
    {
        for(i=0;i<10000;i++)
            data[i].clear();
        name.clear();
        numAuthor = 0;
        while(p--)
        {
            numPaper = 0;
            int flag = 1;
            while(1)
            {
                scanf("%s",str);
                fullname = str;
                scanf("%s",str);    len = strlen(str);
                if(str[len-1] == ':' || str[len-1] == '.')        flag = 0;
                str[len-1] = '\0';
                fullname += str;
                pos = name.find(fullname);
                if(pos == name.end())    
                    name[fullname] = numAuthor ++;
                paper[numPaper++] = name[fullname];    
                if(!flag)
                {
                    gets(str);    break;
                }
            }
            for(i=0;i<numPaper;i++)    
            {
                for(j=0;j<numPaper;j++)
                {
                    if(i!=j)
                        data[paper[i]].push_back(paper[j]);
                }
            }
        }
        pos = name.find(Erdos);
        if(pos == name.end())    name[Erdos] = numAuthor++;
        bfs();
        printf("Database #%d\n",++iCase);
        while(n--)
        {
            scanf("%s",str);    printf("%s",str);
            fullname = str;
            scanf("%s",str);    printf(" %s: ",str);
            fullname +=str;
            pos = name.find(fullname);
            if(pos == name.end() || author[name[fullname]]==-1)
                printf("infinity\n");
            else printf("%d\n",author[name[fullname]]);
        }
        printf("\n");
    }
    return 0;
}
