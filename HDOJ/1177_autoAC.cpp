#include <iostream>
#include <stdio.h>
#include<cstring>
using namespace std;
struct person{
    int completed;
    int hour;
    int minute;
    int second;
    int judge;
};
int main()
{
    int n=0,g=0,s=0,c=0,m=0;
    struct person person[131];
    int isEarly(struct person[],int a,int b);
    while(scanf("%d%d%d%d%d",&n,&g,&s,&c,&m)&&(n||g||s||c||m))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d:%d:%d",&person[i].completed,&person[i].hour,&person[i].minute,&person[i].second);
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=m) person[i].judge=0;
            else person[i].judge=1;
        }
        int index=0;
        struct person cordinator;
        for(int i=1;i<n;i++)
        {
            index=i;
            for(int j=i+1;j<=n;j++)
            {
                if(person[index].completed<person[j].completed) index=j;
                else if(person[index].completed==person[j].completed)
                {
                    if(isEarly(person,index,j)==-1) index=j;
                }
            }
            if(index!=i)
            {
               cordinator=person[i];person[i]=person[index];person[index]=cordinator;
            }
        }
      int f=1;
      while(f)
      {
          if(person[f].judge==1) {break;}
          f++;
      }
      if(f<=g) cout<<"Accepted today? I've got a golden medal :)"<<endl;
      else if(f<=g+s) cout<<"Accepted today? I've got a silver medal :)"<<endl;
      else if(f<=g+s+c) cout<<"Accepted today? I've got a copper medal :)"<<endl;
      else cout<<"Accepted today? I've got an honor mentioned :)"<<endl;
    }
    return 0;
}
int isEarly(person person[],int a,int b)
{
    if(person[a].hour==person[b].hour)
    {
        if(person[a].minute==person[b].minute)
        {
            if(person[a].second==person[b].second)
            {
                return 0;
            }
            else if(person[a].second<person[b].second)
            return 1;
            else return -1;
        }
        else if(person[a].minute<person[b].minute)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else if(person[a].hour<person[b].hour)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
