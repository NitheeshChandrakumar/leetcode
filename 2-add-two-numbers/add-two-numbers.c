#include <stdio.h>
#include <stdlib.h>
//declare variables

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    int carry = 0;

    dummy.next = NULL;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }

        carry = sum / 10;

        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tail = tail->next;
        tail->val = sum % 10;
        tail->next = NULL;
    }

    return dummy.next;
}
