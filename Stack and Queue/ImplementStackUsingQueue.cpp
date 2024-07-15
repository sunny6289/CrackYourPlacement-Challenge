/** USING ONE QUEUE **/
class MyStack {
public:
    queue<int>q1;
    MyStack() {}
    
    void push(int x) {
        if(q1.size()){
            q1.push(x);
            int itr = q1.size()-1;
            while(itr){
                int val = q1.front();
                q1.pop();
                q1.push(val);
                itr-=1;
            }
        return;
        }
        q1.push(x);
        return;
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};





/*** USING TWO QUEUE ***/

class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {}
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int res = q1.front();
        q1.pop();
        return res;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};