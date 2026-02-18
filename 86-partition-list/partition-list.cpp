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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* before = new ListNode(-1);
        ListNode* bhead = before;
        ListNode* after = new ListNode(-1);
        ListNode* ahead = after;
        while(head != NULL){
            if(head->val < x){
                before->next = head;
                before = head;
            }
            else{
                after->next = head;
                after = head;
            }
            head = head->next;
        }
        before->next = ahead->next;
        after->next = NULL;
        return bhead->next;
    }
};