#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

vector<char> S;

bool operator < (vector<char>& a,vector<char>& b)
{
    int maxsize=a.size()>b.size()?a.size():b.size();
    for(int i=0;i<maxsize;i++)
    {
        if(a.at(i)>b.at(i))
        {
            return false;
        }
        else if(a.at(i)<b.at(i))
        {
            return true;
        }
    }
    return a.size()<b.size();
}

bool operator > (vector<char>& a,vector<char>& b)
{
    int maxsize=a.size()>b.size()?a.size():b.size();
    for(int i=0;i<maxsize;i++)
    {
        if(a.at(i)>b.at(i))
        {
            return true;
        }
        else if(a.at(i)<b.at(i))
        {
            return false;
        }
    }
    return a.size()>b.size();
}

bool operator == (vector<char>& a,vector<char>& b)
{
    if(a.size()!=b.size())
    {
        return false;
    }
    int maxsize=a.size();
    for(int i=0;i<maxsize;i++)
    {
        if(a.at(i)!=b.at(i))
        {
            return false;
        }
    }
    return true;
}

/*
int main()
{
    int n;
    scanf("%d%*c",&n);
    for(int i=0;i<n;i++)
    {
        char c;
        scanf("%c%*c",&c);
        S.push_back(c);
    }
    for(int i=0;i<n;i++)
    {
        if(S.at(0)<S.at(S.size()-1))
        {
            printf("%c",S.at(0));
            S.erase(S.begin());
        }
        else
        {
            printf("%c",S.at(S.size()-1));
            S.erase(S.end()-1);
        }
    }
    return 0;
}
*/

char XS[2048];
int L,R;

int main()
{
    int n;
    scanf("%d%*c",&n);
    L=0;
    R=n-1;
    for(int i=0;i<n;i++)
    {
        scanf("%c%*c",&XS[i]);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(XS[L]<XS[R])
        {
            printf("%c",XS[L]);
            L++;
        }
        else if(XS[L]>XS[R])
        {
            printf("%c",XS[R]);
            R--;
        }
        else
        {
            /// XS[L] == XS[R]
            bool check=false;
            for(int i=1;i<R-L;i++)
            {
                if(XS[L+i]<XS[R-i])
                {
                    check=true;
                    printf("%c",XS[L]);
                    L++;
                    break;
                }
                else if(XS[L+i]>XS[R-i])
                {
                    check=true;
                    printf("%c",XS[R]);
                    R--;
                    break;
                }
            }
            if(!check)
            {
                printf("%c",XS[L]);
                L++;
            }
        }
        cnt++;
        if(cnt==80)
        {
            printf("\n");
            cnt=0;
        }
    }
    printf("\n");
    return 0;
}
