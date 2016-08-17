#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
  int n,i,j,mark,z,m;
  float c[1000],maxx,b[100],sum,aa,bb,cc;
  char a[100];
  while(~scanf("%f%d",&maxx,&n),n){
      for(i=1,z=1;i<=n;i++){
          scanf("%d",&m);
          getchar();
          c[z]=mark=0;aa=bb=cc=0;
          for(j=0;j<m;j++){
              scanf("%c:%f",&a[j],&b[j]);
              getchar();
              if(!(a[j]=='A'||a[j]=='B'||a[j]=='C')) mark=1;
              if(a[j]=='A') aa+=b[j];
              if(a[j]=='B') bb+=b[j];
              if(a[j]=='C') cc+=b[j];
              if(aa>600||bb>600||cc>600) mark=1;
              c[z]+=b[j];
              if(c[z]>maxx) mark=1;
          }
          if(mark) continue;
          z++;
      }
      z--;
      sort(c+1,c+z+1);
      sum=0;
      for(i=z;i>=1;i--)
      {
          if(sum+c[i]>maxx) continue;
          sum+=c[i];
      }
      printf("%.2f\n",sum);
  }
}
