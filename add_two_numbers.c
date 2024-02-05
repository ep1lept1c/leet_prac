/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int len(struct ListNode* l) {
    struct ListNode* tmp = l;
    int retval = 0;
    do {
        retval++;
        tmp = tmp->next;
    } while (tmp);
    return retval;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    int len1 = len(l1), len2 = len(l2);
    if (len1 < len2) {
        struct ListNode* ltmp = l1;
        l1 = l2;
        l2 = ltmp;
        int tmp = len1;
        len1 = len2;
        len2 = tmp;
    }
    struct ListNode* ans = malloc(sizeof(*ans));
    struct ListNode* head = ans;
    struct ListNode* almostend = malloc(sizeof(*ans));
    for (int i = 0; i < len1; i++) {
        head->val = 0;
        head->next = malloc(sizeof(*head));
        head = head->next;
    }
    head->val = 0;
    head->next = NULL;
    head = ans;
    int prev = 0;
    for (int i = 0; i < len1; i++) {
        head->val += l1->val + prev;
        l1 = l1->next;
        if (i < len2) {
            head->val += l2->val;
            l2 = l2->next;
        }
        prev = head->val / 10;
        head->val %= 10;
        head = head->next;
    }
    if (prev) {
        head->val = prev;
    } else {
        head = ans;
        for (int i = 0; i < len1 - 1; i++) {
            head = head->next;
        }
        head->next = NULL;
    }
    return ans;
}
