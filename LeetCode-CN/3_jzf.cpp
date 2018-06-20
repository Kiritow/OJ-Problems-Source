class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int num =1;
        int max =0;
        if(s.length()==1)
        {
            return 1;
        }
        for(size_t i =0;i<s.length();i++)
        {
            
            for(size_t j=i+1;j<s.length();j++)
            {
                int flag =0;
                for(size_t k =i;k<j;k++)
                {
                    if(s[j]==s[k])   
                    {
                        flag =1;
                        break;
                    }
                    num++;
                }
                    if(num>max)
                    {
                        max =num;
                    }
                if(flag ==1)
                {
                    break;
                }
                num =1;
            }
             num =1;
        }
        return max;
    }
};
