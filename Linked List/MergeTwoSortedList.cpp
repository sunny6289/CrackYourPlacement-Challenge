class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
                temp=temp->next;
            }else{
                temp->next=list2;
                list2=list2->next;
                temp=temp->next;
            }
        }
        if(list1!=NULL){
            temp->next=list1;
        }else{
            temp->next=list2;
        }
        return dNode->next;
    }
};