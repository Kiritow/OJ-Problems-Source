class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return false;
		ListNode* p = head;
		ListNode* q = head->next->next;
		while (p != q && q && q->next)
		{
			p = p->next;
			q = q->next->next;
		}
		return (p == q);
	}
};
