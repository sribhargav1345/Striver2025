// Tortoise Hare method, find where slow stops
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
};