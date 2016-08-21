#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct 
{
    double score;
    string name;
}disney;
bool cmp(disney a,disney b)
{
    if(a.score==b.score)
       return a.name<b.name;
    else
    return a.score>b.score;
}
int sum=0;
void NEW(disney a[],disney b)
{
    int i;
    for(i=0;i<sum;i++)
        if(a[i].name==b.name)
            break;
        if(i==sum&&sum<=100)
        {
            a[sum].name=b.name;
            a[sum].score=b.score;
            sum++;
            cout<<"A new record"<<endl;
        }
        else
        {
            a[i].score=b.score;
            cout<<"update succeed"<<endl;
        }
}
void average(disney a[])
{
    if(sum==0)
    {
        cout<<"0.00"<<endl;
        return ;
    }
    int i;
    double s=0,t;
    for(i=0;i<sum;i++)
        s+=a[i].score;
    t=s/sum;
    printf("%.2lf\n",t);
}
void Max(disney a[])
{
    if(sum==0)
    {
        cout<<"0 0"<<endl;
        return ;
    }
    int i,num=0;
    sort(a,a+sum,cmp);
        for(i=1;i<sum;i++)
        {
            if(a[i].score==a[i-1].score)
                num++;
            else
                break;
        }
        cout<<a[0].score<<" "<<num+1<<endl;
        for(i=0;i<=num;i++)
            cout<<a[i].name<<endl;
}
void Delete(disney a[],string s)
{
        int i;
    for(i=0;i<sum;i++)
        if(a[i].name==s)
            break;
        if(i==sum)
           cout<<"no such record"<<endl;
        else
        {cout<<"delete succeed"<<endl;
         a[i].score=0;
         sort(a,a+sum,cmp);
        sum--;
        }
}
int main()
{
    disney a[100];
    disney b;
    string s,str;
    while(cin>>s)
    {
        if(s=="NEW")
        {
            cin>>b.name>>b.score;
            NEW(a,b);
        }
        else if(s=="AVERAGE")
            average(a);
        else if(s=="MAX")
            Max(a);
        else if(s=="DELETE")
        {
            cin>>str;
            Delete(a,str);
        }
        else if(s=="QUIT")
            break;
    }
    return 0;
}
