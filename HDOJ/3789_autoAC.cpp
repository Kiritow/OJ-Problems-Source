#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct   nation
{
    long double  gold;
    long double  all;
    long double  area;
    int id;
    int rate1;
    int rate2;
    int rate3;
    int rate4;
    int bestrate;
    int sortway;
};
int cmpway;
bool cmp(nation a,nation b)
{
   if(cmpway==0)   return a.id<b.id;
   else  if(cmpway==1)return a.gold>b.gold;
   else if(cmpway==2)  return a.all>b.all;
   else if(cmpway==3)  return a.gold/a.area>b.gold/b.area;
   else if(cmpway==4)  return a.all/a.area>b.all/b.area;
 }
int main()
{
  int n,m;
  bool flag=0;
  while(cin>>n>>m)
  {
        nation p[n];
        vector<nation>  vn;
      double gold,all,area;
      for(int i=0;i<n;i++)
       {
          scanf("%lf%lf%lf",&gold,&all,&area);
          p[i].gold=gold;
          p[i].all=all;
          p[i].area=area;
          p[i].id=i;
       }
         int   temp;
        for(int i=0;i<m;i++)
         {
              scanf("%d",&temp);
              vn.push_back(p[temp]);
              vn[i].id=i;
         }
        if(m>0)
        {
      cmpway=1;
      sort(vn.begin(),vn.end(),cmp);
      for(int i=0;i<m;i++)
       {
          vn[i].rate1=i;
       }
       for(int i=1;i<m;i++)
       {
          if(vn[i].gold==vn[i-1].gold)   vn[i].rate1=vn[i-1].rate1;
       }
      cmpway=2;
      sort(vn.begin(),vn.end(),cmp);
      for(int i=0;i<m;i++)
       {
          vn[i].rate2=i;
       }
       for(int i=1;i<m;i++)
       {
          if(vn[i].all==vn[i-1].all)   vn[i].rate2=vn[i-1].rate2;
       }
      cmpway=3;
      sort(vn.begin(),vn.end(),cmp);
      for(int i=0;i<m;i++)
       {
          vn[i].rate3=i;
       }
       for(int i=1;i<m;i++)
       {
          if(vn[i].gold/vn[i].area==vn[i-1].gold/vn[i-1].area)   vn[i].rate3=vn[i-1].rate3;
       }
       cmpway=4;
      sort(vn.begin(),vn.end(),cmp);
      for(int i=0;i<m;i++)
       {
          vn[i].rate4=i;
       }
       for(int i=1;i<m;i++)
       {
          if(vn[i].all/vn[i].area==vn[i-1].all/vn[i-1].area)   vn[i].rate4=vn[i-1].rate4;
       }
       cmpway=0;
       sort(vn.begin(),vn.end(),cmp);
      for(int i=0;i<m;i++)
        {
           vn[i].bestrate=vn[i].rate1;
           vn[i].sortway=1;
           if(vn[i].rate2<vn[i].bestrate)
           {
              vn[i].bestrate=vn[i].rate2;
              vn[i].sortway=2;
           }
           if(vn[i].rate3<vn[i].bestrate)
           {
              vn[i].bestrate=vn[i].rate3;
              vn[i].sortway=3;
           }
           if(vn[i].rate4<vn[i].bestrate)
           {
              vn[i].bestrate=vn[i].rate4;
              vn[i].sortway=4;
           }
        }
         for(int i=0;i<m;i++)
            printf("%d:%d\n",vn[i].bestrate+1,vn[i].sortway);
        }
        cout<<endl;
  }
}
