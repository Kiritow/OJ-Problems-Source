#include<stdio.h>

    int a,i,cnt;
    int intArray[210];
    float floatArray[210];
    char charPointArray[210][10];

int main(void){
    scanf("%d",&a);
    for(i = 0; i < a; i++){
        scanf("%s %f %d",&charPointArray[i],&floatArray[i],&intArray[i]);
    }

//    a = 5;

//    charPointArray[0]="Zhang";floatArray[0]=38.3; intArray[0]=0;
//    charPointArray[1]="Li";   floatArray[1]=37.5; intArray[1]=1;
//    charPointArray[2]="Wang"; floatArray[2]=37.1; intArray[2]=1;
//    charPointArray[3]="Zhao"; floatArray[3]=39.0; intArray[3]=1;
//    charPointArray[4]="Liu";  floatArray[4]=38.2; intArray[4]=1;

    for(i = 0; i < a; i++){
        if( (floatArray[i] >= 37.5) && (intArray[i] == 1) ){
            printf("%s\n",charPointArray[i]);
            cnt++;
        }
    }
    printf("%d",cnt);
//   getchar();getchar();getchar();getchar();getchar();getchar();getchar();
    return 0;
}
