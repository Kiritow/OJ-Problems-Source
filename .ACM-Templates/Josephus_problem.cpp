///约瑟夫问题,n个人,查m个数  
int JosephusProblem_Solution4(int n, int m)  
{  
    if(n < 1 || m < 1)  
        return -1;  
  
    vector<int> f(n+1,0);  
    for(unsigned i = 2; i <= n; i++)  
        f[i] = (f[i-1] + m) % i;  
  
    return f[n];  
}
