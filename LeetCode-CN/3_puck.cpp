#include <algorithm>
#include <string>
#include <set>
using std::string;
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int result{};
        for (std::size_t i{}; i < s.size(); ++i)
        {
            string tmp_str = s.substr(i);
            int cu_length{};
            std::set<char> set_except;
            
            for (auto ch : tmp_str)
            {
                if (set_except.end() == set_except.find(ch))
                {
                    set_except.insert(ch);
                    ++cu_length;
                }
                else
                {
                    break;
                }
            }

            result = std::max(result, cu_length);
        }

        return result;
    }
};
