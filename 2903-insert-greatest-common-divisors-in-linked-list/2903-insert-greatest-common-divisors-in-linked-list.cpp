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
    int gcd(int a, int b) {

        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* current1 = head->next;
        while (current1 != NULL) {
            int gc = gcd(current->val, current1->val);
            ListNode* temp = new ListNode(gc);
            temp->next = current1;
            current->next = temp;
            current = current1;
            current1 = current1->next;
        }
        return head;
    }
};