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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = NULL;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != NULL){
            if(prev->val != curr->val){
                temp = prev;
                prev = prev->next;
                curr = curr->next;
            }
            else{
                while(curr != NULL && prev->val == curr->val){
                    curr = curr->next;
                }
                if(temp == NULL){
                    head = curr; 
                }
                else{
                    temp->next = curr;
                }
                prev = curr;
                if(curr != NULL) curr = curr->next;
            }
        }
        return head;
    }
};