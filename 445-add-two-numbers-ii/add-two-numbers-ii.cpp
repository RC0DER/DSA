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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* back = NULL;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = back;
            back = curr;
            curr = temp;
        }
        return back;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry = 0;
        ListNode* sum = NULL;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int newVal = carry;
            if(l1 != NULL){
                newVal += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                newVal += l2->val;
                l2 = l2->next;
            }

            carry = newVal/10;
            newVal = newVal%10;

            ListNode* NewHead = new ListNode(newVal);
            NewHead->next = sum;
            sum = NewHead;
        }
        if(sum->next == NULL) return sum;
        while(sum != NULL && sum->val ==0){
            ListNode* del = sum;
            sum = sum->next;
            delete(del);
        }
        return sum;
    }
};