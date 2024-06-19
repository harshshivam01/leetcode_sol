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
    ListNode* oddEvenList(ListNode* head) {
         ListNode*EvenDummy=new ListNode(0);
         ListNode*evenhead=EvenDummy;
         ListNode*OddDummy=new ListNode(0);
         ListNode*oddhead=OddDummy;
         ListNode*curr=head;
         int count=1;
         while(curr!=NULL){

            if(count%2==0){
                EvenDummy->next=new ListNode(curr->val);
                EvenDummy=EvenDummy->next;
            }
            else{
                OddDummy->next=new ListNode(curr->val);
                OddDummy=OddDummy->next;
            }
            count++;
            curr=curr->next;
         }
         OddDummy->next=evenhead->next;
         return oddhead->next;
        // ListNode* EvenDummy = new ListNode(0);
        // ListNode* evenhead = EvenDummy;
        // ListNode* OddDummy = new ListNode(0);
        // ListNode* oddhead = OddDummy;
        // ListNode* curr = head;
        // int count = 1;
        // while (curr != NULL) {
        //     if (count % 2 == 0) {
        //         EvenDummy->next = new ListNode(curr->val);
        //         EvenDummy = EvenDummy->next;
        //     } else {
        //         OddDummy->next = new ListNode(curr->val);
        //         OddDummy = OddDummy->next;
        //     }
        //     count++;
        //     curr = curr->next;
        // }
        // OddDummy->next = evenhead->next;
        // return oddhead->next;
    }
};