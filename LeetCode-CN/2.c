/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#ifdef __cplusplus
#include <cstdio>
#include <cstdlib>
#include <cstring>
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif
typedef struct ListNode ListNode;

ListNode* BigIntegerAdd(ListNode* a, ListNode* b,
    int* tmp)
{
    ListNode* pa = a;
    ListNode* pb = b;
    int pos = 0;
    while (pa != NULL && pb != NULL)
    {
        tmp[pos] = pa->val + pb->val;
        pa = pa->next;
        pb = pb->next;
        pos++;
    }
    while (pa != NULL)
    {
        tmp[pos] = pa->val;
        pa = pa->next;
        pos++;
    }
    while (pb != NULL)
    {
        tmp[pos] = pb->val;
        pb = pb->next;
        pos++;
    }
    ListNode* head = NULL;
    ListNode** pthis = &head;
    for (int i = 0; i < pos; i++)
    {
        if (tmp[i] >= 10)
        {
            tmp[i + 1] += tmp[i] / 10;
            tmp[i] %= 10;
        }

        (*pthis) = (ListNode*)malloc(sizeof(ListNode));
        (*pthis)->val = tmp[i];
        (*pthis)->next = NULL;
        pthis = &((*pthis)->next);
    }

    if (tmp[pos] > 0)
    {
        (*pthis) = (ListNode*)malloc(sizeof(ListNode));
        (*pthis)->val = tmp[pos];
        (*pthis)->next = NULL;
        pthis = &((*pthis)->next);
    }

    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int tmp[1024];
    memset(tmp, 0, sizeof(tmp));
    return BigIntegerAdd(l1, l2, tmp);
}
