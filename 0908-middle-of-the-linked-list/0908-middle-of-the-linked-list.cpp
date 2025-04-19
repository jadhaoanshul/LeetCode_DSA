class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int c = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            c++;
        }
        int mid = c / 2;
        ListNode* side = head;
        for (int i = 0; i < mid; i++) {
            side = side->next;
        }

        return side;  // Return middle node
    }
};
