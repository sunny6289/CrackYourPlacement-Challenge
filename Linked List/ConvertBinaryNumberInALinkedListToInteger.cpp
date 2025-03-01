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
        if(head->next==NULL){
            return head->val;
        }
        int ans = 0;
        ListNode* temp= head;
        while(temp){
            ans*=2;
            ans+=temp->val;
            temp=temp->next;
        }
        return ans;
    }
};