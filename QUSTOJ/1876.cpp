#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef struct
{
    int inversion;
    char* pointer_to_string;
}pack;
pack list[105];
     
char data[105][64];
     
     
void quicksort(pack* a,int left,int right)
{
    if(left>=right) return;
    int keyvalue=a[left].inversion;
    int i=left,j=right;
    while(i<j)
    {
        while(i<j&&a[j].inversion>=keyvalue)
        {
            j--;
        }
        while(i<j&&a[i].inversion<=keyvalue)
        {
            i++;
        }
        pack tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
    if(i==j)
    {
        pack tmp=a[left];
        a[left]=a[j];
        a[j]=tmp;
    }
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
}
     
     
int main()
{
    int max,length;
    scanf("%d %d%*c",&length,&max);
    for(int i=0;i<max;i++)
    {
        scanf("%s",&data[i][0]);
        list[i].pointer_to_string=&data[i][0];
        int inversion=0;
        for(int ii=0;ii<length-1;ii++)
        {
            for(int j=ii+1;j<length;j++)
            {
                if(list[i].pointer_to_string[ii]>list[i].pointer_to_string[j])
                {
                    inversion++;
                }
            }
        }
        list[i].inversion=inversion;
    }
    quicksort(list,0,max-1);
    for(int i=0;i<max;i++)
    {
        printf("%s\n",list[i].pointer_to_string);
    }
    return 0;
}
