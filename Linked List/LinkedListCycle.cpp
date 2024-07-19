/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    **Brute Force: Use a set, insert all the Nodes in the set while traversal
                   and keep checking if the current node is in the set or not
                   If 'Yes' then there is a cycle. 
                   If the pointer reaches the end and none of the node is visited before, then it 
                   means there is no cycle
    
    **Optimal :    Use slow fast pointer, if there is a cycle the fast pointer will catch the slow
                   pointer for sure, which will confirm that there is a cycle.
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }

        return false;

    }
};