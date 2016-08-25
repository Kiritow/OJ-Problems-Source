#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string.h>
#include<map>
using namespace std;
char s[1024];
int rec[506],word[506];
int main()
{ 
    map<int,char> mp;
    mp[21]='K';
    mp[22]='X';
    mp[23]='V';
    mp[31]='M';
    mp[32]='C';
    mp[33]='N';
    mp[41]='O';
    mp[42]='P';
    mp[43]='H';
    mp[51]='Q';
    mp[52]='R';
    mp[53]='S';
    mp[61]='Z';
    mp[62]='Y';
    mp[63]='I';
    mp[71]='J';
    mp[72]='A';
    mp[73]='D';
    mp[74]='L';
    mp[81]='E';
    mp[82]='G';
    mp[83]='W';
    mp[91]='B';
    mp[92]='U';
    mp[93]='F';
    mp[94]='T';
    while(scanf("%s",s)!=EOF) {
          int len = strlen(s),cnt = 0;
          memset(rec,0,sizeof(rec));
          for(int i = 0; i < len; i += 2,cnt++) {
                  rec[cnt] = s[i] - '0';
                  rec[cnt] = rec[cnt] * 10 + s[i+1] - '0';
          }
          int lim = (cnt-1)>>1;
          for(int i = lim, j = cnt - 1, k = 0; i >= 0; --i,--j,k += 2) {
                  if(cnt & 1) {
                         word[k] = rec[i];
                         word[k+1] = rec[j];
                  }else {
                        word[k] = rec[j];
                        word[k+1] = rec[i];
                  }
          }
          for(int i = 0; i < cnt; ++i) {
                  printf("%c",mp[word[i]]);
          }
          puts("");
    }
    return 0;
}
