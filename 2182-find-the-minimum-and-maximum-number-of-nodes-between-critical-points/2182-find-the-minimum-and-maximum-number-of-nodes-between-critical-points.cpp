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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>v;
        if(head==NULL||head->next==NULL||head->next->next==NULL)return {-1,-1};
        ListNode*prev=head;
        ListNode*curr=head->next;
        int count=0;
        ListNode*nxt=curr->next;
        while(nxt!=NULL){
            count++;
           if(curr->val>prev->val&&curr->val>nxt->val){
             v.push_back(count);
           }
           else if(curr->val<prev->val&&curr->val<nxt->val){
            v.push_back(count);
           }
           prev=curr;
           curr=nxt;
           nxt=nxt->next;
          

        }
        if(v.size()<=1)return {-1,-1};
        sort(v.begin(),v.end());
        int  mini=INT_MAX;
     
        for(int i=0;i<v.size()-1;i++){
           int diff=v[i+1]-v[i];
            mini=min(mini,diff);
        }
       return{ mini ,v[v.size()-1]-v[0] }; 
    }
};