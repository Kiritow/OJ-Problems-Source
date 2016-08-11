//Written by Coffee. 判断素数  
bool isPrime(int num)  
{  
    if (num == 2 || num == 3)  
    {  
        return true;  
    }  
    if (num % 6 != 1 && num % 6 != 5)  
    {  
        return false;  
    }  
    for (int i = 5; i*i <= num; i += 6)  
    {  
        if (num % i == 0 || num % (i+2) == 0)  
        {  
            return false;  
        }  
    }  
    return true;  
}  
