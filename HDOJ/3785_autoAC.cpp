#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int a[100010];
int aux[100010];
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int a[],int l,int h){
    int i=l;
    int j=h+1;
    int v=a[l];
    while(1){
        while(a[++i]>v)if(i==h)break;
        while(a[--j]<v)if(j==l)break;
        if(i>=j)break;
        swap(&a[i],&a[j]);
    }
    swap(&a[l],&a[j]);
    return j;
}
void q_sort(int a[], int l,int h){
    if(l>=h)return;
    int j=partition(a,l,h);
    q_sort(a,l,j-1);
    q_sort(a,j+1,h);
}
void merge(int a[],int l,int mid,int h){
    int i=l;
    int j=mid+1;
    for(int k=l;k<=h;++k)
        aux[k]=a[k];
    for(int k=l;k<=h;++k){
        if(i>mid)a[k]=aux[j++];
        else if(j>h)a[k]=aux[i++];
        else if(aux[i]>aux[j])a[k]=aux[i++];
        else a[k]=aux[j++];
    }
}
void m_sort(int a[],int l,int h){
    if(h<=l)return ;
    int mid=l+(h-l)/2;
    m_sort(a , l , mid);
    m_sort(a,mid+1,h);
    merge(a,l,mid,h);
}
int main(int argc, char *argv[])
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(a,0,sizeof(a));
        if(n==0&&m==0)return 0;
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        q_sort(a,0,n-1);
        for(int i=0;;++i)
        {
            if(m)printf("%d",a[i]);
            m--;
            if(m)printf(" ");
            if(m==0)break;
        }
        printf("\n");
    }
    return 0;
}
