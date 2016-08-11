#include<stdio.h>
#include<stdlib.h>
#define SCD 666

//定义四则运算以及函数指针，注意调用除法判断除数不为0
double plus(double a,double b){return a+b;}
double jian(double a,double b){if(a-b < 0) return b-a; else return a-b;}
double cheng(double a,double b){return a*b;}
double devide (double a,double b){return a/b;}
double (*calc[4])(double ,double ) = { plus, jian, cheng, devide,};

//递归的判断函数，其中结果使用参数传递而不是返回值
int judge(bool *fb,double res,double *a,bool *ifa){
  if(ifa[0] && ifa[1] && ifa[2] && ifa[3]){
    if(res == 24){
      *fb = true;
      return SCD;
    }
    else
      return 0;
  }
  //printf("in, res = %d\n",res);
  for(int i = 0; i < 4; i++){
    if(!ifa[i]){
      ifa[i] = true;
      for(int j = 0; j < 3; j++)
        if(judge(fb,calc[j](res,a[i]),a,ifa) == SCD)
	  return SCD;
      if(a[i] != 0)
	if(judge(fb,calc[3](res,a[i]),a,ifa) == SCD)
	  return SCD;
      ifa[i] = false;
    }
  }
  return 0;
}

int main(int argc,char** argv){
  //要读进来的四个数
  int a1[4];
  double a[4];
  //保存结果的数组
  bool sb[1000];
  //计数器，用来控制输出结果
  int cnt = 0;
  while(true){
    //计算结果
    double res = 0;
    //判断结果
    bool fb = false;
    //是否被使用了
    bool ifa[4] = {false};
    scanf("%d %d %d %d",&a1[0],&a1[1],&a1[2],&a1[3]);
    for(int i = 0; i < 4; i++)
      a[i] = a1[i];
    //判断是否结束输入
    if((a[0] == 0.0) && (a[1] == 0.0) && (a[2] == 0.0) &&(a[3] == 0.0))
      break;
    //判断
    judge(&fb,res,a,ifa);
    //把结果写进去
    sb[cnt] = fb;
    //计数器自增
    cnt++;
  }
  //控制输出
  for(int i = 0; i < cnt; i++){
    if(sb[i]){
      printf("YES\n");
    }
    else{
      printf("NO\n");
    }
  }
  return 0;
}
