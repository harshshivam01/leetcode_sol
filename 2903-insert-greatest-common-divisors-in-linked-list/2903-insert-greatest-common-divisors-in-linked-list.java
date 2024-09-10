/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
   public int gcd(int a, int b) {
        if (b == 0) 
            return a;
        return gcd(b, a % b);
    }

    
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head == null || head.next == null)  // Check if the list is empty or has only one node
            return head;
        
        ListNode current = head;
        ListNode current1 = head.next;

        while (current1 != null) {
            int gc = gcd(current.val, current1.val);  // Calculate GCD
            ListNode temp = new ListNode(gc);  // Create a new node with GCD value
            temp.next = current1;  // Insert the new node between current and current1
            current.next = temp;
            
            current = current1;  // Move to the next node
            current1 = current1.next;  // Move to the next node
        }
        
        return head;
        
    }
}