/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slowptr = head;
        stack<int> st;
        while (slowptr){
            st.push(slowptr->val);
            slowptr = slowptr->next;
        }
        while (head) {
            int last = st.top();
            st.pop();
            if (head->val != last){
                return false;
            }
            head = head->next;
        }
        return true;
    }
};
