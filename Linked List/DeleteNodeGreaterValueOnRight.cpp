/*
    Given a singly linked list, 
    remove all the nodes in the list which have any node on their right whose value is greater. 
    (Not just immediate Right , but entire List on the Right)
    
    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)
*/
class Solution
{
    public:
    Node *reverse(Node *head){
        Node* prev = NULL;
        Node* curr = head;
        while(curr!=NULL){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        if(head->next==NULL) return head;
        //Reverse the LL
        head = reverse(head);
        //Leaders in an Array algo
        int max = head->data;
        Node* prev = head;
        Node* curr = head->next;
        while(curr!=NULL){
            if(curr->data>=max){
                max = curr->data;
                prev = curr;
                curr = curr->next;
            }else{
                prev->next = curr->next;
                curr = prev->next;
            }
        }
        //Again reverse the LL
        head=reverse(head);
        return head;
    }
    
};