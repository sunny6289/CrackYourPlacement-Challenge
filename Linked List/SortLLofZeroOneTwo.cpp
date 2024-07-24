class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head->next==NULL || head==NULL) return head;
        
        // Add code here
        Node* temp = head;
        Node* zeroHead = new Node(-1);
        Node* zero = zeroHead;
        Node* oneHead = new Node(-1);
        Node* one = oneHead;
        Node* twoHead = new Node(-1);
        Node* two = twoHead;
        
        while(temp!=NULL){
            if(temp->data==0){
                zero->next = temp;
                zero=zero->next;
            }else if(temp->data==1){
                one->next = temp;
                one=one->next;
            }else{
                two->next = temp;
                two=two->next;
            }
            temp=temp->next;
        }
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;
        delete(oneHead);
        delete(twoHead);
        
        return zeroHead->next;
        
    }
};