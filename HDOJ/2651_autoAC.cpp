#include <iostream>
#include <string.h>
using namespace std;
int sum=0;
struct TireTree 
{
    int num;
    TireTree *next[9];        
};
int Change(int a[],char str[])   
{
    int i,k=0,len=strlen(str),t=1;
    for(i=1;i<len;++i)
    {
        if(str[i]!=str[i-1])
        { a[k++]=t; t=1;}
        else if(str[i]==str[i-1])
        t++;
    }
    a[k]=t;
    return k;
}
void Insert(TireTree *root,int a[],int k)
{
     TireTree *current=root;
     int i=0;
     while(i<=k)
     {
         if(current->next[a[i]]!=NULL)
         current=current->next[a[i]];
         else
         {
             TireTree *NewNode=new TireTree;
             NewNode->num=0;
             for(int j=0;j<9;j++) NewNode->next[j]=NULL;
             current->next[a[i]]=NewNode;
             current=NewNode;
         }
         i++;
     }
     current->num++;
}
void GetSum(TireTree *root)
{
    int temp=root->num;
    sum+=(temp)*(temp-1)/2;
    for(int k=0;k<9;++k)
    if(root->next[k])
    GetSum(root->next[k]);
}
int main()
{
    int a[8],n,i,k;
    char str[8];
    while(cin>>n)
   {
     TireTree *root=new TireTree;
     root->num=0;
     for(k=0;k<9;++k) root->next[k]=NULL;
    sum=0;
    for(i=0;i<n;++i)
    {
     cin>>str;  
     k=Change(a,str);
     Insert(root,a,k);
    }
    GetSum(root);
    cout<<sum<<endl;
    }
    return 0;
}
