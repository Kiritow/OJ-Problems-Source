#include <stack>
class Solution {
public:
    ListNode * reverseKGroup(ListNode* head, int k) {
        ListNode* seg_start = head;
        ListNode* now = head;
        ListNode* return_head = head;
        ListNode* last_seg = NULL;
        int passed = 0;

        while (now != NULL)
        {
            passed++;
            if (passed == k)
            {
                // Meet a segment
                ListNode* seg_end = now;
                // Change head
                if (seg_start == head)
                {
                    return_head = seg_end;
                }

                ListNode* p = seg_start;
                std::stack<ListNode*> stk;
                while (p != seg_end)
                {
                    stk.push(p);
                    p = p->next;
                }
                // p is now seg_end

                // checkpoint
                ListNode* next_seg_start = seg_end->next;

                while (!stk.empty())
                {
                    p->next = stk.top();
                    stk.pop();
                    p = p->next;
                }

                // stack is empty. p is now seg_start. 
                // p->next now pointes to the orignal "next"
                
                // set last segment
                if (last_seg)
                {
                    last_seg->next = seg_end;
                }
                last_seg = seg_start;
                // set it to next_seg_start
                p->next = next_seg_start;

                seg_start = next_seg_start;
                now = next_seg_start;
                passed = 0;

                // debug
                //printList(return_head);
            }
            else
            {
                now = now->next;
            }
        }

        return return_head;
    }
};
