#include<stdio.h>
#include<stdlib.h>

typedef struct stu{
    long num;
    float scr;
} stu;

stu a[100];

void sort(int left,int right){
     if(left >= right) return;
     int i = left,j = right;
     stu t = a[left];
     while(i<j){
         while((i<j)&&(a[j].scr >= t.scr))j--;
         a[i] = a[j];
         while((i<j)&&(a[i].scr <= t.scr))i++;
         a[j] = a[i];
     }
     a[i] = t;
     sort(left,i-1);
     sort(i+1,right);
}

int main(void){
    int k,jjfly,i;
    scanf("%d %d",&jjfly,&k);
    for(i = 0; i < jjfly; i++)
        scanf("%ld %f",&a[i].num,&a[i].scr);

    sort(0,jjfly);
    printf("%d %.1f",a[jjfly-k+1].num,a[jjfly-k+1].scr);
    return 0;
}
