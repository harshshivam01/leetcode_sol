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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(-1);
        ListNode*current=dummy;
        int sum=0;
        while(l1!=NULL||l2!=NULL||sum){
        
        if(l1)sum=sum+l1->val;
        if(l2)sum=sum+l2->val;
        ListNode*newNode=new ListNode(sum%10);
        sum=sum/10;
        if(l1)l1=l1->next;
         if(l2)l2=l2->next;
         current->next=newNode;
         current=current->next;
        }
        
        return dummy->next;
    }
};