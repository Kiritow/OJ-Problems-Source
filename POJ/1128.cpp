#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

const int MAXH = 32;
const int MAXW = 32;
const int MAXCHARACTER = 26;
char map[MAXH][MAXW];

int up[MAXCHARACTER];
int down[MAXCHARACTER];
int left[MAXCHARACTER];
int right[MAXCHARACTER];

/// under[A][B]
/// 表示字符B在A上面(under[A][B]==1) 或 未知(under[A][B]==0)
int under[26][26];

int indegree[26];
int notes[26];
int _GN;


int ans[26];
int visit[26];
void DFS(int step)
{
    if(step==_GN)
    {
        for(int i=0; i<_GN; i++)
        {
            printf("%c",ans[i]+'A');
        }
        printf("\n");
        return;
    }
    for(int j=0; j<_GN; j++)
    {
        if(!visit[notes[j]]&&indegree[notes[j]]==0)
        {
            for(int k=0;k<_GN;k++)
            {
                if(under[notes[j]][notes[k]])
                {
                    indegree[notes[k]]--;
                }
            }
            visit[notes[j]]=1;
            ans[step]=notes[j];
            DFS(step+1);
            /// Recover
            visit[notes[j]]=0;
            for(int k=0;k<_GN;k++)
            {
                if(under[notes[j]][notes[k]])
                {
                    indegree[notes[k]]++;
                }
            }
        }
    }
}

int main()
{
    int h,w;
    while(scanf("%d %d%*c",&h,&w)==2)
    {
        memset(map,0,sizeof(map));
        for(int i=1; i<=h; i++)
        {
            gets(&map[i][1]);
        }
        memset(up,0x3f,sizeof(up));
        memset(down,0,sizeof(down));
        memset(left,0x3f,sizeof(left));
        memset(right,0,sizeof(right));
        memset(under,0,sizeof(under));
        memset(indegree,0,sizeof(indegree));
        memset(notes,0,sizeof(notes));
        memset(visit,0,sizeof(visit));
        memset(ans,0,sizeof(ans));
        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                if(map[i][j]=='.') continue;
                int cc=map[i][j]-'A';
                up[cc]=min(i,up[cc]);
                down[cc]=max(i,down[cc]);
                left[cc]=min(j,left[cc]);
                right[cc]=max(j,right[cc]);
            }
        }
        _GN=0;
        for(int i=0; i<26; i++)
        {
            /// If a letter does not exist, skip it.
            if(up[i]==INF) continue;
            notes[_GN++]=i;
            char c='A'+i;

            /// Check the outline of the frame.
            for(int col=left[i]; col<=right[i]; col++)
            {
                /// First Line
                if(c!=map[up[i]][col])
                {
                    under[i][map[up[i]][col]-'A']=1;
                }
                /// Last Line
                if(c!=map[down[i]][col])
                {
                    under[i][map[down[i]][col]-'A']=1;
                }
            }
            for(int line=up[i]+1; line<=down[i]-1; line++)
            {
                /// First Col
                if(c!=map[line][left[i]])
                {
                    under[i][map[line][left[i]]-'A']=1;
                }
                /// Last Col
                if(c!=map[line][right[i]])
                {
                    under[i][map[line][right[i]]-'A']=1;
                }
            }
        }

        /// Graphical Sort

        /// Calculate in-degree
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<26; j++)
            {
                if(under[i][j]!=0) indegree[j]++;
            }
        }

        /**
        //单拓扑排序(WA)
        for(int i=0; i<_GN; i++)
        {
            for(int j=0; j<_GN; j++)
            {
                if(indegree[notes[j]]==0)
                {
                    indegree[notes[j]]--;
                    printf("%c",notes[j]+'A');
                    for(int k=0; k<_GN; k++)
                    {
                        if(under[notes[j]][notes[k]]==1)
                        {
                            indegree[notes[k]]--;
                        }
                    }
                    break;
                }
            }
        }
        */

        /// 全拓扑排序
        DFS(0);
    }

    return 0;


}
