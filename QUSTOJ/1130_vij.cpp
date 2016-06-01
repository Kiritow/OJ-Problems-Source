#include<iostream> 
using namespace std; 
int main() 
{ 
char a[100]; 
int a1[100],s=0; 
for(int i=1;i<=13;i++) 
{ 
cin>>a[i]; 
a1[i]=a[i]-48; 
} 
 
for(int i=1,g=1;i<=11;i++,g++) 
{ 
if(a[i]=='-')i++; 
s+=a1[i]*g; 
} 
 
if(s%11==10&&a[13]=='X'||s%11==a1[13]) cout<<"Right"<<endl; 
else
{ 
for(int i=1;i<=12;i++) 
{ 
cout<<a[i]; 
} 
if(s%11==10) cout<<'X'; 
else cout<<s%11; 
return 0;
} 
}
