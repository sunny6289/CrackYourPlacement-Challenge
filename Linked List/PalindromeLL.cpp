/*
    Given the head of a singly linked list, return true if it is a palindrome
    or false otherwise.
*/
class Solution {
public:
    ListNode* reverse(ListNode* tempHead){
        ListNode* prev = NULL;
        ListNode* curr = tempHead;
        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead = reverse(slow->next);
        ListNode* temp = head;
        while(newHead!=NULL){
            if(temp->val!=newHead->val) return false;
            temp=temp->next;
            newHead=newHead->next;
        }
        reverse(slow->next);
        return true;
    }
};