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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* temp = head;
        while(temp->next!=NULL){
            if(temp->val==temp->next->val){
                ListNode* temp2 = temp->next;
                while(temp2!=NULL){
                    if(temp->val==temp2->val){
                        temp2=temp2->next;
                    }else{
                        break;
                    }
                }
                temp->next=temp2;
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
};