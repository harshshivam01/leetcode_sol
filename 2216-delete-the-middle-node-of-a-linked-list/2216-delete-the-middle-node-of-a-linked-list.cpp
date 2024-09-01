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
    ListNode* deleteMiddle(ListNode* head) {
        ios::sync_with_stdio(NULL);
        cin.tie(NULL);
        cout.tie(NULL);
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=head;
        if(head==NULL||head->next==NULL)return NULL;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }
        while(prev->next!=slow){
            prev=prev->next;
        }
        prev->next=slow->next;
        delete(slow);
        
     return head;
    }
};