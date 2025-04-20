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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int c = 0;
        while(temp!= NULL){
            c++;
            temp=temp->next;
        }
        int ans=0;
        temp = head;
        while(temp!= NULL){
            c--;
            ans += temp->val * pow(2,c);
            temp = temp->next;
        }
        return ans;
    }
};