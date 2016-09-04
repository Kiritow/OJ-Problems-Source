#include <cstdio>
#include <cstring>
void exkmp(char s1[],char s2[],int next[],int ex[]) {
    int i,j,p;
    for (i=0,j=0,p=-1;s1[i]!='\0';i++,j++,p--) {
        if (p==-1) {
            j=0;
            do p++; while (s1[i+p]!='\0'&&s1[i+p]==s2[j+p]);
            ex[i]=p;
        } else if (next[j]<p) ex[i]=next[j];
        else if (next[j]>p) ex[i]=p;
        else {
            j=0;
            while (s1[i+p]!='\0'&&s1[i+p]==s2[j+p]) p++;
            ex[i]=p;
        }
    }
    ex[i]=0;
}
char s1[100100];
char s2[100100];
int ex[100100];
int next[100100];
int ls1,ls2;
bool smallerThan(int i,int j) {
    if (ex[j]<i-j) return s1[j+ex[j]]<s2[ex[j]];
    if (next[i-j]<ls2-(i-j)) return s2[next[i-j]]<s2[i-j+next[i-j]];
    if (next[ls2-(i-j)]<(i-j)) return s2[ls2-(i-j)+next[ls2-(i-j)]]<s2[next[ls2-(i-j)]];
    return false;
}
int main() {
    int ans,i;
    while (scanf("%s%s",s1,s2)!=EOF) {
        exkmp(s2+1,s2,next,next+1);
        exkmp(s1,s2,next,ex);
        ls1=strlen(s1);
        ls2=strlen(s2);
        ans=0;
        for (i=0;i<ls1;i++) {
            if (smallerThan(i+1,ans)) ans=i+1;
        }
        for (i=0;i<ans;i++) printf("%c",s1[i]);
        printf("%s",s2);
        for (i=ans;i<ls1;i++) printf("%c",s1[i]);
        printf("\n");
    }
    return 0;
}
