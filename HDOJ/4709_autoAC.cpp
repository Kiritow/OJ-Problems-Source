#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;
struct point
{
    double x;
    double y;
};
double area(point A,point B,point C)
{
   double abx=B.x-A.x;
   double aby=B.y-A.y;
   double acx=C.x-A.x;
   double acy=C.y-A.y;
   double ans=(abx*acy-acx*aby)/2;
   return fabs(ans);
}
int main()
{
   int T;
   int n;
   cin>>T;
   while(T--)
   {
      cin>>n;
      point p[n];
      double x,y;
      for(int i=0;i<n;i++)
      {
      scanf("%lf %lf",&x,&y);
      p[i].x=x;
      p[i].y=y;
      }
      vector<double> v;
      for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
          for(int k=j+1;k<n;k++)
           {
             v.push_back(area(p[i],p[j],p[k]));
           }
       sort(v.begin(),v.end());
       double ans=0;
       for(int i=0;i<v.size();i++)
         if(v[i]!=0)
         {
             ans=v[i];
             break;
         }
       if(ans==0)  cout<<"Impossible"<<endl;
       else printf("%.2lf\n",ans);
   }
}
