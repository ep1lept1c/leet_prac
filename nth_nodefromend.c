/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* frwrd = head;
    struct ListNode* nptr = head;
    int cnt = 0, flag = 0;
    while (frwrd->next){
        cnt++;
        frwrd = frwrd->next;
        if (cnt == n + 1 || flag){
            flag = 1;
            nptr = nptr->next;
        }
    }
    printf("%d %d %d", cnt,  nptr->val, frwrd->val);
    if (cnt == n - 1){
        head = nptr->next;
    }
    struct ListNode* tmp = nptr->next;
    if (!tmp){
        return NULL;
    }
    if (!tmp->next){
        nptr->next = NULL;
    }
    nptr->next = tmp->next;
    return head;
}
