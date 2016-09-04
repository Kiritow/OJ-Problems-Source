#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int p[26];
int main()
{
   int n,m;
   while(cin>>n>>m)
   {
       if(n==0&&m==0)  break;
       memset(p,-1,sizeof(p));
       char c;
       char p1;
       char p2;
       string s;
       for(int i=0;i<n;i++)
       {
          cin>>s;
          c=s[0];
          p1=s[1];
          p2=s[2];
         if(p1!='-') p[p1-'A']=c-'A';
         if(p2!='-') p[p2-'A']=c-'A';
       }
       char c1,c2;
       for(int i=0;i<m;i++)
       {
          cin>>s;
          c1=s[0];
          c2=s[1];
          int count1=0,count2=0;
          int target1=c1-'A';
          int target2=c2-'A';
          int cur=target1;
          while(cur!=target2)
          {
             cur=p[cur];
             if(cur==-1)
             {
                 count1=0;
                 break;
             }
             else  count1++;
          }
          if(count1==0)
          {
             cur=target2;
              while(cur!=target1)
          {
             cur=p[cur];
             if(cur==-1)
             {
                 count2=0;
                 break;
             }
             else count2++;
          }
          }
         if(count1==0&&count2==0)
        {
           cout<<'-'<<endl;
        }
        else if(count1!=0)
        {
            if(count1==1)  cout<<"parent"<<endl;
            else if(count1==2)  cout<<"grandparent"<<endl;
            else
            {
               while(count1>=3)
               {
                   cout<<"great-";
                   count1--;
               }
                 cout<<"grandparent"<<endl;
            }
        }
        else if(count2!=0)
        {
            if(count2==1)  cout<<"child"<<endl;
            else if(count2==2)  cout<<"grandchild"<<endl;
            else
            {
               while(count2>=3)
               {
                   cout<<"great-";
                   count2--;
               }
                 cout<<"grandchild"<<endl;
            }
        }
       }
   }
}
