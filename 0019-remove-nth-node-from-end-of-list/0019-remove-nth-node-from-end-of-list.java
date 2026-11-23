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
    private int getTotalLength(ListNode head){
        int count=0;
        while(head!=null){
            count++;
            head=head.next;
        }
        return count;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        int totalLength=getTotalLength(head);

        if(n==totalLength) return head.next;

        int nodeToSkipFromFront= totalLength-n;

        ListNode curr=head;
        for(int i=0;i<nodeToSkipFromFront-1;i++){
            curr=curr.next;
        }

        curr.next=curr.next.next;
        return head;
        
    }
}