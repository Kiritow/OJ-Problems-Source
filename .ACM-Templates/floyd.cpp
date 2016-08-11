for(int k=1;k<=n;k++)    
{    
    for(int f=1;f<=n;f++)    
    {    
        for(int t=1;t<=n;t++)    
        {    
            if(f==t||f==k||t==k) continue;    
            if(m[f][k]!=INF&&m[k][t]!=INF)    
            {    
                int total=m[f][k]+m[k][t];    
                if(total<m[f][t]||m[f][t]==INF)    
                {    
                    m[f][t]=total;    
                }    
            }    
        }    
    }    
}
