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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int length=1;
        
        ListNode*temp=head;
        while(temp->next){
            temp=temp->next;
            length++;
        }
        temp->next=head;
         k = k % length;
        if (k == 0){
            temp->next = NULL;
             return head;
        } 
        int rest=length-k;
        ListNode*prev=temp;
        while(rest--){
           prev=prev->next;
           
        }
        ListNode* newhead=prev->next;
        prev->next=NULL;
        return newhead;
    }
};