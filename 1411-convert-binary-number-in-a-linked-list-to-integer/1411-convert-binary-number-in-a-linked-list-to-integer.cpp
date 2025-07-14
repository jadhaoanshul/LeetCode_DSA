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
        vector<int> res;
        while(head!= NULL){
            res.push_back(head->val);
            head = head->next;
        }
        int idx=0;
        int n = res.size();

        for(int i=0; i<n; i++){
            idx += res[i]*pow(2, n - 1 - i);
        }
        return idx;
    }
};