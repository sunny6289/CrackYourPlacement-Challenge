/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *  Given the heads of two singly linked-lists headA and headB, 
 *  return the node at which the two lists intersect. 
 *  If the two linked lists have no intersection at all, return null.
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headB==NULL) return NULL;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
            if(t1==t2) return t1;
            if(t1==NULL) t1=headB;
            if(t2==NULL) t2=headA;
        }
        return t1;
    }
};