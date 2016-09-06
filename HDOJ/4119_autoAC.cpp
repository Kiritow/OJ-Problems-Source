#include <set>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Point
{
    int x,y;
    Point(){}
    Point(int x,int y):x(x),y(y){}
    bool operator <(const Point& S)const
    {
        return x<S.x || x==S.x && y<S.y;
    }
}P[4][666];
struct TT
{
    string s;
    bool ok;
    bool operator <(const TT& S)const
    {
        return s < S.s;
    }
}Ans[4];
int n,m;
Point Rotary(Point A)
{
    return Point(A.y,n+1-A.x);
}
int main()
{
    int z,ncase=0;
    char tmp[25],map[55][55];
    set<string> Dic;
    scanf("%d",&z);
    while(z--)
    {
        Dic.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%s",map[i]+1);
        int top = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",map[0]+1);
            for(int j=1;j<=n;j++)
                if(map[0][j] == '*')
                    P[0][top++] = Point(i,j);
        }
        for(int i=1;i<=3;i++)
            for(int j=0;j<top;j++)
                P[i][j] = Rotary(P[i-1][j]);
        for(int i=0;i<=3;i++)
            sort(P[i],P[i]+top);
        for(int k=0;k<=3;k++)
            Ans[k].ok = true;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%s",tmp);
            Dic.insert(tmp);
        }
        for(int k=0;k<=3;k++)
        {
            int loc = -1;
            string& str = Ans[k].s;
            str = "";
            for(int i=k;i<k+4;i++)
                for(int j=0;j<top;j++)
                {
                    char ttmp = map[ P[i%4][j].x ][ P[i%4][j].y ];
                    str += ttmp=='.' ? ' ' : ttmp;
                }
            while(!str.empty() && str[0]==' ')
                str.erase(str.begin());
            for(int i=1;i<str.length();i++)
                if(str[i]==' ' && str[i-1]==' ')
                    str.erase(str.begin()+(i--));
            if(!str.empty() && str[ str.length()-1 ]==' ')
                str.erase(str.end()-1);
            if(str.empty())
            {
                Ans[k].ok = false;
                continue;
            }
            while(++loc < str.length())
            {
                string word;
                while(loc<str.length() && str[loc]!=' ')
                    word += str[loc++];
                if(Dic.find(word) == Dic.end())
                {
                    Ans[k].ok = false;
                    break;
                }
            }
        }
        sort(Ans,Ans+4);
        printf("Case #%d: ",++ncase);
        int i;
        for(i=0;i<4;i++)
            if(Ans[i].ok)
            {
                puts(Ans[i].s.c_str());
                break;
            }
        if(i == 4)
            puts("FAIL TO DECRYPT");
    }
    return 0;
}
