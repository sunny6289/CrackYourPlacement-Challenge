/** Here all the operation are always O(1) except top and peek, 
because they might become O(N) in few cases
This solution is Amortized O(1) **/

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {}
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(st1.size()){
                int val = st1.top();
                st1.pop();
                st2.push(val);
            }
        }
        int val = st2.top();
        st2.pop();
        return val;
    }
    
    int peek() {
        if(st2.empty()){
            while(st1.size()){
                int val = st1.top();
                st1.pop();
                st2.push(val);
            }
        }
        return st2.top();
    }
    
    bool empty() {
        return st2.empty() && st1.empty();
    }
};



/** Push Time complexity O(N) **/

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {}
    
    void push(int x) {
        if(!st2.size()){
            st2.push(x);
            return;
        }
        while(st2.size()){
            int val = st2.top();
            st2.pop();
            st1.push(val);
        }
        st2.push(x);
        while(st1.size()){
            int val = st1.top();
            st1.pop();
            st2.push(val);
        }
        return;
    }
    
    int pop() {
        int val = st2.top();
        st2.pop();
        return val;
    }
    
    int peek() {
        return st2.top();
    }
    
    bool empty() {
        return st2.empty();
    }
};