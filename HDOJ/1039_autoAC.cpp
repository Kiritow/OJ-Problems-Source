#include <stdio.h>
#include <string.h>
int isvowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return 1;
    else
        return 0;
}
int isA(char str[]){
    int i=0,vowel=0,consonant=0,k;
    for(k=0;k<strlen(str);k++){
        if(isvowel(str[k])){
            i=1;
            vowel++;
            consonant=0;
            if(vowel>2)
                return 0;
        }
        else{
            consonant++;
            vowel=0;
            if(consonant>2)
                return 0;
        }
        if(str[k]!='e'&&str[k]!='o'&&str[k]==str[k+1])
            return 0;
    }
    if(!i)
        return 0;
    else
        return 1;
}
int main(){
    char str[25];
    while(~scanf("%s",str)){
        if(!strcmp(str,"end"))
            break;
        if(isA(str)){
            printf("<%s> is acceptable.\n",str);
        }
        else
            printf("<%s> is not acceptable.\n",str);
    }
}
