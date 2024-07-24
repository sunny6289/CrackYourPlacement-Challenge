class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        if(head->next==NULL){
            if(head->val==val) return NULL;
            else return head;
        }
        ListNode* dNode = new ListNode(-1);
        ListNode* listHead = dNode;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val!=val){
                listHead->next = temp;
                listHead = listHead->next;
                temp = temp->next;
                listHead->next = NULL;
            }else{
                temp = temp->next;
            }
        }
        return dNode->next;
    }
};