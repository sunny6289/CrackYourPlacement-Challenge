/*
    Given elements as nodes of the two singly linked lists. 
    The task is to multiply these two linked lists, say L1 and L2.

    Note: The output could be large take modulo 10^9+7.
*/

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long int firstVal = 0;
        long long int secVal = 0;
        while(first!=NULL){
            firstVal=firstVal*10+first->data;
            firstVal=firstVal%(1000000007);
            first=first->next;
        }
        while(second!=NULL){
            secVal=secVal*10+second->data;
            secVal=secVal%(1000000007);
            second=second->next;
        }
        return (firstVal*secVal)%(1000000007);
        
    }
};