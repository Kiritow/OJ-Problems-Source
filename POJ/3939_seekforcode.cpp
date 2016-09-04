#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int weekday(int y,int m,int d)
{


       int tm=m>=3?(m-2):(m+10);


       int ty=m>=3?y:(y-1);


       return (ty+ty/4-ty/100+ty/400+(int)(2.6*tm-0.2)+d)%7;
}
int preoperate()
{
int year,mon,da,cont=0;
for(year=1753;year<=1753+400;year++)
{
for(mon=1;mon<=12;mon++)
{
for(da=1;da<=21;da=da+10)
{
if(weekday(year,mon,da)==1)
cont++;
}
}
}
return cont;
}
void gotowhat(int y,int m,int d,int howmany)
{
int cont=howmany;
int year,mon,da;
year=y;
for(mon=m;mon<=12;mon++)
{
for(da=(mon==m?d:1);da<=21;da=da+10)
{
         int tag=weekday(year,mon,da);
if(tag==1)
cont--;
if(cont==0)
{
cout<<year<<" "<<mon<<" "<<da<<endl;
return ;
}
}
}
for(year=y+1;year<=y+500;year++)
{
for(mon=1;mon<=12;mon++)
{
for(da=1;da<=21;da=da+10)
{
       int tag=weekday(year,mon,da);
if(tag==1)
cont--;
if(cont==0)
{
cout<<year<<" "<<mon<<" "<<da<<endl;
return ;
}
}
}
}
}
int main()
{
int t,y,m,d,number,st,ts;
int oneturn=preoperate();
cin>>t;
while(t--)
{
cin>>y>>m>>d>>number;
st=number%2058;
ts=number/2058;
y+=400*ts;
                number=number-2058*ts;
gotowhat(y,m,d,number);
}
return 0;
}
