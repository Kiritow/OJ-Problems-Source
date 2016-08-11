/// LCIS 最长公共上升子序列  
namespace LCIS  
{  
  
const int MAXLEN_A = 500;  
const int MAXLEN_B = 500;  
int dp[MAXLEN_A+5][MAXLEN_B+5];  
int deal(const char* a,const char* b)  
{  
    int lena=strlen(a);  
    int lenb=strlen(b);  
    for(int i=1;i<=lenb;i++)  
    {  
        int k=0;  
        for(int j=1;j<=lena;j++)  
        {  
            dp[i][j]=dp[i-1][j];/// when b[i-1] != a[j-1]  
            if(b[i-1]>a[j-1]) k=max(k,dp[i-1][j]);  
            else if(b[i-1]==a[j-1]) dp[i][j]=k+1;  
        }  
    }  
    int ans=0;  
    for(int i=1;i<=lena;i++) ans=max(ans,dp[lenb][i]);  
    return ans;  
}  
  
}  
//End of namespace LCIS  

