#include <algorithm>
#include <stack>
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int maxp = 0;
        stack<int> stk;

        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }
            else // if (s[i] == ')')
            {
                // Stack not empty, and symbol matches.
                if (!stk.empty() && s[stk.top()]=='(')
                {
                    // Pop matched pairs.
                    stk.pop();
                    if (stk.empty())
                    {
                        // From Start to i is a valid string.
                        maxp = std::max(i + 1, maxp);
                    }
                    else
                    {
                        // From stk.top()+1 to i is a valid string. Length: i-(stk.top()+1)+1
                        maxp = std::max(i - stk.top(), maxp);
                    }
                }
                else
                {
                    // new start point (stub)
                    stk.push(i);
                }
            }
        }
        return maxp;
    }
};
