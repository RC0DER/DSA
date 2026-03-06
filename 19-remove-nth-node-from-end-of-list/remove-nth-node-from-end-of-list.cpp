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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* temp = head;
        // int cnt = 0;
        // while(temp != NULL){
        //     cnt++;
        //     temp = temp->next;
        // }
        // if(cnt == n) return head->next;
        // cnt = cnt-n;
        // temp = head;
        // while(temp != NULL){
        //     cnt--;
        //     if(cnt == 0) break;
        //     temp = temp->next;
        // }
        // if(temp->next->next == NULL){
        //     temp->next = NULL;
        // }
        // else{
        //     temp->next = temp->next->next;
        // }
        // return head;
        ListNode* fast = head;
        ListNode* slow = head;
        if(head->next == NULL) return head->next;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        if(fast == NULL) return head->next;
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow->next->next == NULL) slow->next = NULL;
        else slow->next = slow->next->next;
        return head;
    }
};