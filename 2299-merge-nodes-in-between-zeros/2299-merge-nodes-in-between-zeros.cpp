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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode*dummy=new ListNode(-1);
        ListNode*dummyhead=dummy;
        ListNode*curr=head;
        ListNode*temp=head;
       
        while(temp!=NULL){
             long long sum=0;
        while(temp->val!=0){
           sum+=temp->val;
           temp=temp->next;
        }
        if(sum!=0){
        dummy->next=new ListNode(sum);
        dummy=dummy->next;
        }
        curr=temp;
        temp=temp->next;
        }
        return dummyhead->next;
    }
};