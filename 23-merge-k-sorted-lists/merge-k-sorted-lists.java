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

    private static final int MAX_VAL = 10000;
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = null;
        ListNode tail = null;

        while(true) {
            int minVal = MAX_VAL + 1;
            int minIdx = -1;

            for (int i = 0; i < lists.length; i++) {
               ListNode list = lists[i];

               if(list == null) continue;
               if(list.val < minVal) {
                    minVal = list.val;
                    minIdx = i;
               }
            }

             if(minIdx == -1)
                break;

            ListNode newNode = new ListNode(minVal);
            lists[minIdx] = lists[minIdx].next;

            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                tail = tail.next;
            }
        }

        return head;
    }
}