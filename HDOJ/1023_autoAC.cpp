#include<stdio.h>
#include<string.h>
int res[101][200] = {0};
int temp[200] = {0};
void add(int *x, int *y){
    int i, t;
    for(i=0; x[i]!=0&&y[i]!=0; i++){
        x[i] += y[i] -'0';
    }
    for(i; y[i]!=0; i++){
        x[i] += y[i];
    }
    for(t=0; x[t]!=0; t++){
        if(x[t+1]!=0){
            x[t+1] += (x[t]-'0')/10;
        }
        else{
            if((x[t]-'0')/10!=0){
                x[t+1] += (x[t]-'0')/10+'0';
            }
            else{
                x[t+1] = 0;
            }
        }
        x[t] = (x[t]-'0')%10+'0';
    }
}
int* multiple(int *x, int *y){
    int i, j, length;
    for(i=0; i<200; i++){
        temp[i] = 0;
    }
    for(i=0; x[i]!=0; i++){
        for(j=0; y[j]!=0; j++){
            if(temp[i+j]!=0){
                temp[i+j] += (x[i]-'0')*(y[j]-'0');
            }
            else{
                temp[i+j] += (x[i]-'0')*(y[j]-'0')+'0';
            }
        }
    }
    length = 0;
    while(temp[length]!=0){
        length++;
    }
    for(i=0; i<length; i++){
        temp[i+1] += (temp[i]-'0')/10;
        temp[i] = (temp[i]-'0')%10 + '0';
    }
    if(temp[length]!=0){
        temp[length] += '0';
    }
    while(temp[length]!=0){
        if((temp[length]-'0')/10!=0){
            temp[length+1] += temp[length]/10+'0';
        }
        temp[length] = (temp[length]-'0')%10+'0';
        length++;
    }
    return temp;
}
int main(){
    int n, i, j;
    res[0][0] = '1';
    res[1][0] = '1';
    for(i=2; i<=100; i++){
        for(j=0; j<i; j++){
            add(res[i], multiple(res[j], res[i-j-1]));
        }
    }
    while(scanf("%d", &n) != EOF){
        i=199;
        while(i>=0){
            if(res[n][i] != 0){
                printf("%c", res[n][i]);
            }
            i--;
        }
        printf("\n");
    }
    return 0;
}
