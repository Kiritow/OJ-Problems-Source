#include <cstdio>
#include <ctype.h>
#include <cmath>
#include <stdlib.h>
char rin[10100],rout[10100];
struct sta{
       double x;
       bool digit;
       char ch;
} stack[10100];
double tst[10100];
int top,ttop,rtop;
int priority(char ch)
{
    switch (ch)
    {
           case '+' : 
           case '-' : return 1;break;
           case '*' :
           case '/' : return 2;break;
           case '^' : return 3;break;
    }
}
int main()
{
    int i;
    bool mark;
    while (scanf("%s",rin) != EOF)
    {
          mark = true;
          top = 0; i = 0; rtop = 0;
          while (rin[i])
          { 
                if (mark)
                {
                         mark = false;
                         while (rin[i] == '(')
                         {
                              i ++;  
                              rout[++rtop] = '(';    
                         }
                         if (rin[i] == '-' || rin[i] == '+')
                         {
                            stack[++top].x = 0;
                            stack[top].digit = true;
                         }      
                         else {
                               sscanf(&rin[i],"%lf",&stack[++top].x);
                               stack[top].digit = true;
                               while (!isdigit(rin[i]))
                                     i++;
                               while (isdigit(rin[i]) || rin[i] == '.')
                                     i++;
                              }
                }
                else {
                        mark = true;
                        if (rin[i] == ')')
                        {
                           while (rout[rtop] != '(')
                           {
                                 stack[++top].ch = rout[rtop--];
                                 stack[top].digit = false;
                           }
                           rtop--;
                           mark = false;         
                        }  
                        else {
                               if (!rtop || rout[rtop] == '(')
                                  rout[++rtop] = rin[i];
                               else {
                                      while ( rtop&& priority(rin[i]) < priority(rout[rtop]))
                                      {
                                        stack[++top].ch = rout[rtop--];
                                        stack[top].digit = false;
                                      }
                                      if (rtop && priority(rin[i]) == priority(rout[rtop]))
                                      {
                                          stack[++top].ch = rout[rtop];
                                          stack[top].digit = false;
                                          rout[rtop] = rin[i];        
                                      }
                                      else rout[++rtop] = rin[i];
                                    }
                             }
                        i ++;
                     }
          }
         while (rtop)
          {
                stack[++top].ch = rout[rtop--];
                stack[top].digit = false;
          }
          ttop = 0; i = 1;
          bool flag = true;
          while (i <= top && flag)
          {
                if (stack[i].digit)
                   tst[++ttop] = stack[i].x;
                else {
                        double b = tst[ttop--], a = tst[ttop];
                        switch (stack[i].ch)
                        {
                               case '+': tst[ttop] = a + b;
                                         break;
                               case '-': tst[ttop] = a - b;
                                         break;
                               case '*': tst[ttop] = a * b;
                                         break;
                               case '/': if (fabs(b) < 0.00000001)
                                               flag = false;
                                         else tst[ttop] = a / b;
                                         break;
                               case '^': tst[ttop] = pow(a,b);
                                         break;
                        }
                     }
                i++;
          }
          if (flag)
             printf("%.8lf\n",tst[ttop]);
          else printf("The teacher is so lazy!\n"); 
    }
    return 0;
}
