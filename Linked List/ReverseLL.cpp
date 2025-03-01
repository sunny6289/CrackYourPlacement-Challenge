/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *  
 *                                  ***QUESTION***
 *  Given the head of a singly linked list, reverse the list, and return the reversed list.
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = newHead;
            newHead = curr;
            curr = temp;
        }
        return newHead;
    }
};