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
   ListNode* reverse(ListNode*root){
    ListNode*curr=root;
    ListNode*naxt=NULL;
    ListNode*prev=NULL;
    while(curr!=NULL){
        naxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=naxt;

    }
return  prev;
   }
    int pairSum(ListNode* head) {
       ListNode*fast=head;
       ListNode*slow=head;
       while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

       }

      ListNode*temp= reverse(slow);
      int maxi=INT_MIN;
      ListNode*curr=head;
      while(curr!=slow&&temp!=NULL){
         maxi=max(maxi,curr->val+temp->val);
        curr=curr->next;
        temp=temp->next;
      }
return maxi;
        
    }
};