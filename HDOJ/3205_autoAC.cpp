#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<utility>
using namespace std;
map<int,int> tmp;
set<map<int,int> > ans[1010];
int a[1010],b[1010],c[1010];
bool cmp(vector<pair<int,int> > A,vector<pair<int,int> > B)
{
       vector<pair<int,int> >::reverse_iterator pA=A.rbegin(),pB=B.rbegin();
       while (1)
       {
              if (pA->first<pB->first) return true;
              if (pA->first>pB->first) return false;
              if (abs(pA->second)<abs(pB->second)) return true;
              if (abs(pA->second)>abs(pB->second)) return false;
              if (pA->second<pB->second) return true;
              if (pA->second>pB->second) return false;
              ++pA;++pB;
       }
}
void init()
{
       tmp[1]=1;
       tmp[0]=-1;
       ans[1].insert(tmp);
       for (int i=2;i<=1001;++i)
       {
              for (int j=1;j<i;++j)
                     if (i%j==0)
                            for (set<map<int,int> >::iterator p=ans[j].begin();p!=ans[j].end();++p)
                                   ans[i].insert(*p);
              for (int j=0;j<=i;++j) a[j]=0;
              a[i]=1;
              a[0]=-1;
              for (set<map<int,int> >::iterator p=ans[i].begin();p!=ans[i].end();++p)
              {
                     for (int j=0;j<=i;++j) b[j]=c[j]=0;
                     for (std::_Rb_tree_const_iterator<std::pair<const int, int> > it=p->begin();it!=p->end();++it)
                            b[it->first]=it->second;
                     int get=0;
                     for (int j=0;j<=i;++j) if (b[j]) get=j;
                     for (int j=i;j>=0;--j)
                            if (a[j])
                            {
                                   c[j-get]=a[j];
                                   for (int k=get;k>=0;--k)
                                          a[j-get+k]-=c[j-get]*b[k];
                            }
                     for (int j=i;j>=0;--j) a[j]=c[j];
              }
              tmp.clear();
              for (int j=i;j>=0;--j)
                     if (a[j]) tmp[j]=a[j];
              ans[i].insert(tmp);
       }
}
void work()
{
       while (1)
       {
              int n;
              scanf("%d",&n);
              if (!n) return;
              vector<vector<pair<int,int> > > v;
              v.clear();
              vector<pair<int,int> > w;
              for (set<map<int,int> >::iterator p=ans[n].begin();p!=ans[n].end();++p)
              {
                     w.clear();
                     for (std::_Rb_tree_const_iterator<std::pair<const int, int> > it=p->begin();it!=p->end();++it)
                            w.push_back(make_pair(it->first,it->second));
                     v.push_back(w);
              }
              sort(v.begin(),v.end(),cmp);
              for (vector<vector<pair<int,int> > >::iterator p=v.begin();p!=v.end();++p)
              {
                     w=*p;
                     putchar('(');
                     int flag=0;
                     for (vector<pair<int,int> >::reverse_iterator it=w.rbegin();it!=w.rend();++it)
                     {
                            if (flag) putchar((it->second>0)?'+':'-');
                            it->second=abs(it->second);
                            if (it->first==0) printf("%d",it->second);
                            else if (it->first==1) (it->second==1)?putchar('x'):printf("%dx",it->second);
                            else (it->second==1)?printf("x^%d",it->first):printf("%dx^%d",it->second,it->first);
                            flag=1;
                     }
                     putchar(')');
              }
              puts("");
       }
}
int main()
{
       init();
       work();
       return 0;
}
